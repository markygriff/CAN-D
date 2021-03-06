/**
  ******************************************************************************
  * File Name          : CAN.c
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "can.h"
#include "fatfs.h"
#include "proto_handler.h"
#include "stm32302c_custom.h"
#include "usbd_cdc_if.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define TX_BUFFER_SIZE 8
#define RX_BUFFER_SIZE 8

/* If defined, the CAN TX Task will be scheduled */
#define CAN_TX_ON

/* Private variables ---------------------------------------------------------*/
static APP_ConfigType mAppConfiguration = { 0 };
static char canLogIdentifier[] = CAN_LOG_IDENTIFIER;
/* Threads */
static osThreadId CANMonitorTaskHandle;
static osThreadId MarkLogTaskHandle;
/* Queues */
static osMessageQId CANRxQueueHandle;

/* Data Pools */
osPoolDef(CANTxPool, TX_BUFFER_SIZE, CANTxMessage);
osPoolDef(CANRxPool, RX_BUFFER_SIZE, CANRxMessage);
static osPoolId CANTxPool;
static osPoolId CANRxPool;

/* RX Elements */
CAN_RxHeaderTypeDef CAN_RxHeader = {
    .StdId = 0x45,
    .ExtId = 0,
    .IDE = 0,
    .RTR = 0x00000000U,
    .DLC = 8,
    .Timestamp = 0,
    .FilterMatchIndex = 0
};

/* TX Elements */
#if defined(CAN_TX_ON)
static osThreadId CANTransmitTaskHandle;
static osMessageQId CANTxQueueHandle;
static uint32_t CAN_TxMailbox;
static CAN_TxHeaderTypeDef CAN_TxHeader = {
    .StdId = 0x45,
    .ExtId = 0,
    .IDE = CAN_ID_STD,
    .RTR = 0x00000000U,
    .DLC = 8,
    .TransmitGlobalTime = DISABLE
};
#endif // CAN_TX_ON

/* Private macro -------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
CAN_HandleTypeDef hcan;

/* Private function prototypes -----------------------------------------------*/
void APP_CAN_MonitorTask(void const* argument);
void APP_CAN_TransmitTask(void const* argument);
void APP_CAN_MarkLogTask(void const* argument);
static size_t APP_CAN_FormatSDData(uint8_t* dest, CANRxMessage* srcRxMsg);

/* Exported functions --------------------------------------------------------*/
/**
  * @brief  CAN Init Function
  * @retval None
  */
void APP_CAN_Init(void)
{
    CAN_FilterTypeDef canFilterConfig;

    hcan.Instance = CAN;
    hcan.Init.Prescaler = 18;
    hcan.Init.Mode = CAN_MODE_LOOPBACK;
    hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
    hcan.Init.TimeSeg1 = CAN_BS1_15TQ;
    hcan.Init.TimeSeg2 = CAN_BS2_4TQ;
    hcan.Init.TimeTriggeredMode = DISABLE;
    hcan.Init.AutoBusOff = DISABLE;
    hcan.Init.AutoWakeUp = DISABLE;
    hcan.Init.AutoRetransmission = DISABLE;
    hcan.Init.ReceiveFifoLocked = DISABLE;
    hcan.Init.TransmitFifoPriority = DISABLE;
    if (HAL_CAN_Init(&hcan) != HAL_OK)
        Error_Handler();

    // Set up CAN filters to receive all incoming messages from the bus
    canFilterConfig.FilterBank = CAN_FILTER_BANK;
    canFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    canFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    canFilterConfig.FilterIdHigh = CAN_FILTER_ID_HIGH;
    canFilterConfig.FilterIdLow = CAN_FILTER_ID_LOW;
    canFilterConfig.FilterMaskIdHigh = CAN_FILTER_MASK_ID_HIGH;
    canFilterConfig.FilterMaskIdLow = CAN_FILTER_MASK_ID_LOW;
    canFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
    canFilterConfig.FilterActivation = ENABLE;
    canFilterConfig.SlaveStartFilterBank = CAN_SLAVE_START_FILTER_BANK;
    if (HAL_CAN_ConfigFilter(&hcan, &canFilterConfig) != HAL_OK)
        Error_Handler();

    if (HAL_CAN_Start(&hcan) != HAL_OK)
        Error_Handler();

    if (HAL_CAN_ActivateNotification(&hcan, CAN_IT_START) != HAL_OK)
        Error_Handler();

    // Turn on LED1 to notify that the CAN Controller has started
    BSP_LED_On(LED1);

#if defined(CAN_TX_ON)
    if ((CANTxPool = osPoolCreate(osPool(CANTxPool))) == NULL)
        Error_Handler();
#endif

    if ((CANRxPool = osPoolCreate(osPool(CANRxPool))) == NULL)
        Error_Handler();

    mAppConfiguration.SDStorage = APP_ENABLE;
    mAppConfiguration.USBTransfer = APP_DISABLE;
    mAppConfiguration.CANTransmit = APP_ENABLE;
}

/**
  * @brief  Initializes RTOS queues and tasks used by the CAN Controller
  * @retval None
  */
void APP_CAN_InitTasks(void)
{
    osThreadDef(CANMonitorTask, APP_CAN_MonitorTask, osPriorityNormal, 0, 512);
    CANMonitorTaskHandle = osThreadCreate(osThread(CANMonitorTask), NULL);

    osThreadDef(MarkLogTask, APP_CAN_MarkLogTask, osPriorityNormal, 0, 512);
    MarkLogTaskHandle = osThreadCreate(osThread(MarkLogTask), NULL);

#if defined(CAN_TX_ON)
    osThreadDef(CANTransmitTask, APP_CAN_TransmitTask, osPriorityNormal, 0, 512);
    CANTransmitTaskHandle = osThreadCreate(osThread(CANTransmitTask), NULL);
    osMessageQDef(CANTxQueue, TX_BUFFER_SIZE, CANTxMessage);
    CANTxQueueHandle = osMessageCreate(osMessageQ(CANTxQueue), NULL);
#endif

    osMessageQDef(CANRxQueue, RX_BUFFER_SIZE, CANRxMessage);
    CANRxQueueHandle = osMessageCreate(osMessageQ(CANRxQueue), NULL);
}

/**
  * @brief  Initializes the CAN MSP.
  * @param  canHandle pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (canHandle->Instance == CAN) {
        /* CAN clock enable */
        __HAL_RCC_CAN1_CLK_ENABLE();

        __HAL_RCC_GPIOB_CLK_ENABLE();

        /*
            CAN GPIO Configuration
            PB8     ------> CAN_RX
            PB9     ------> CAN_TX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_CAN;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /* CAN interrupt Init */
        HAL_NVIC_SetPriority(USB_LP_CAN_RX0_IRQn, 6, 0);
        HAL_NVIC_EnableIRQ(USB_LP_CAN_RX0_IRQn);
    }
}

/**
  * @brief  DeInitializes the CAN MSP.
  * @param  canHandle pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{
    if (canHandle->Instance == CAN) {
        /* Peripheral clock disable */
        __HAL_RCC_CAN1_CLK_DISABLE();

        /*
            CAN GPIO Configuration
            PB8     ------> CAN_RX
            PB9     ------> CAN_TX 
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8 | GPIO_PIN_9);
        HAL_NVIC_DisableIRQ(USB_LP_CAN_RX0_IRQn);
    }
}

/**
  * @brief  Rx FIFO 0 msg pending callback.
  * @param  CanHandle: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* canHandle)
{
    CANRxMessage* msg;

    // Allocate memory pool for rx message
    msg = osPoolAlloc(CANRxPool);
    msg->handle = &hcan;
    msg->header = &CAN_RxHeader;

    // Get CAN RX data from the CAN module
    if (HAL_CAN_GetRxMessage(canHandle, CAN_RX_FIFO_0, msg->header, msg->data) != HAL_OK) {
        Error_Handler();
    }

    // Pass CAN RX data to the monitor thread
    osMessagePut(CANRxQueueHandle, (uint32_t)msg, 0);
}

/**
  * @brief  Rx FIFO 0 full callback.
  * @param  CanHandle: pointer to a CAN_HandleTypeDef structure that contains
  *         the configuration information for the specified CAN.
  * @retval None
  */
void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef* canHandle)
{
    CANRxMessage* msg;

    // Allocate memory pool for rx message
    msg = osPoolAlloc(CANRxPool);
    msg->handle = &hcan;
    msg->header = &CAN_RxHeader;

    // Get CAN RX data from the CAN module
    if (HAL_CAN_GetRxMessage(canHandle, CAN_RX_FIFO_0, msg->header, msg->data) != HAL_OK) {
        Error_Handler();
    }

    // Pass CAN RX data to the monitor thread
    osMessagePut(CANRxQueueHandle, (uint32_t)msg, 0);
}

/**
  * @brief  Toggles the CAN module.
  * @retval None
  */
void APP_CAN_StartStop(void)
{
    if (hcan.State == HAL_CAN_STATE_LISTENING) {
        APP_CAN_Stop();
    } else if (hcan.State == HAL_CAN_STATE_READY) {
        APP_CAN_Start();
    }
}

/**
  * @brief  Starts the CAN module.
  * @retval None
  */
void APP_CAN_Start(void)
{
    // Changes the hcan.State to HAL_CAN_STATE_LISTENING
    if (HAL_CAN_Start(&hcan) == HAL_OK) {
        HAL_CAN_ActivateNotification(&hcan, CAN_IT_START);
        BSP_LED_On(LED1);
    }
}

/**
  * @brief  Stops the CAN module.
  * @retval None
  */
void APP_CAN_Stop(void)
{
    if (HAL_CAN_Stop(&hcan) == HAL_OK) {
        HAL_CAN_DeactivateNotification(&hcan, CAN_IT_START);
        BSP_LED_Off(LED1);
    }
}

/**
 * @brief Queue CAN data for transmission.
 * @retval None
 */
void APP_CAN_TransmitData(uint8_t* txData, uint32_t id, uint32_t dlc)
{
#if defined(CAN_TX_ON)
    CANTxMessage* msg;
    msg = osPoolAlloc(CANTxPool);
    CAN_TxHeader.StdId = id;
    CAN_TxHeader.DLC = dlc;
    msg->handle = &hcan;
    msg->header = &CAN_TxHeader;
    memcpy(msg->data, txData, dlc);
    osMessagePut(CANTxQueueHandle, (uint32_t)msg, 0);
#endif // CAN_TX_ON
}

/**
  * @brief  Sets the APP Configuration
  * @param  newConfig: the configuration to set
  * @retval None
  */
void APP_CAN_SetConfiguration(APP_ConfigType newConfig)
{
    mAppConfiguration = newConfig;
}

/**
  * @brief Resumes the Mark Log Task
  * @retval None
  */
void APP_CAN_MarkLog(void)
{
    osThreadResume(MarkLogTaskHandle);
}

/**
  * @brief  Function implementing the APP_CAN_MonitorTask thread.
  *         Monitors incoming CAN data.
  * @retval None
  */
void APP_CAN_MonitorTask(void const* argument)
{
    uint8_t usbTxCnt = 0;
    osEvent event;
    CANRxMessage* canRxMsg;
    size_t usbMaxMsgLen = CAN_USB_DATA_SZ_BYTES + PROTO_BUFFER_OVERHEAD; // Max length of the serialized data
    uint8_t usbTxMsg[usbMaxMsgLen]; // Serialized (packaged) protobuf data
    size_t usbTxNumBytes = 0; // Number of bytes in serialized data
    FromEmbedded fromEmbeddedMsg = FromEmbedded_init_zero;
    uint8_t sdTxMsg[CAN_SD_DATA_SZ_BYTES];

    for (;;) {
        // Pend on any CAN Rx data
        event = osMessageGet(CANRxQueueHandle, 0);
        if (event.status == osEventMessage) {
            canRxMsg = event.value.p;

            // Pack the protobuf message
            fromEmbeddedMsg.contents.canDataChunk.data.size = CAN_RX_MSG_DATA_SZ_BYTES;
            fromEmbeddedMsg.contents.canDataChunk.has_id = true;
            fromEmbeddedMsg.contents.canDataChunk.has_data = true;
            fromEmbeddedMsg.contents.canDataChunk.has_dlc = true;
            fromEmbeddedMsg.which_contents = FromEmbedded_canDataChunk_tag;

            memcpy(fromEmbeddedMsg.contents.canDataChunk.data.bytes, canRxMsg->data, canRxMsg->header->DLC);
            fromEmbeddedMsg.contents.canDataChunk.id = (canRxMsg->header->StdId & CAN_RX_MSG_STDID_MASK);
            fromEmbeddedMsg.contents.canDataChunk.dlc = canRxMsg->header->DLC;
            usbTxNumBytes = APP_PROTO_HANDLE_bufferFromEmbeddedMsg(&fromEmbeddedMsg, (uint8_t*)usbTxMsg, usbMaxMsgLen);

            usbTxCnt = 0;
            while (APP_USB_Transmit((uint8_t*)usbTxMsg, usbTxNumBytes) == USBD_BUSY) {
                // USB TX State is BUSY. Wait for it to be free.
                osDelay(1);
                if (++usbTxCnt >= CAN_USB_TX_MAX_TRY) {
                    usbTxCnt = 0;
                    break;
                }
            }

            // Write data to SD card
            uint8_t formattedMsgLen = 0;
            formattedMsgLen = APP_CAN_FormatSDData(sdTxMsg, canRxMsg);
            APP_FATFS_LogSD((const uint8_t*)sdTxMsg, formattedMsgLen, canLogIdentifier);
            osPoolFree(CANRxPool, canRxMsg);
        }
        osDelay(1);
    }
}

/**
  * @brief  Function implementing the APP_CAN_TransmitTask thread.
  *         Send outgoing CAN data.
  * @retval None
  */
#if defined(CAN_TX_ON)
void APP_CAN_TransmitTask(void const* argument)
{
    osEvent event;
    CANTxMessage* msg;

    for (;;) {
        // Pend on any CAN Tx data
        event = osMessageGet(CANTxQueueHandle, 0);
        if (event.status == osEventMessage) {
            msg = event.value.p;
            if (mAppConfiguration.CANTransmit == APP_ENABLE) {
                if (HAL_CAN_GetTxMailboxesFreeLevel(msg->handle) > 1) {
                    if (CAN_TxMailbox != CAN_TX_MAILBOX2) {
                        HAL_CAN_AddTxMessage(msg->handle, msg->header, msg->data, &CAN_TxMailbox);
                    }
                } else {
                    // Dropped a message!
                }
            }
            osPoolFree(CANTxPool, msg);
        }
        osDelay(1);
    }
}
#endif // CAN_TX_ON

/**
  * @brief  Function implementing the APP_CAN_MarkLogTask thread.
  *         Writes the current linecount to the Mark Data Log file.
  * @retval None
  */
void APP_CAN_MarkLogTask(void const* argument)
{
    uint8_t markData[6];
    volatile uint32_t lineCount = 0;
    osThreadSuspend(NULL);
    for (;;) {
        lineCount = APP_FATFS_GetLineCount();
        sprintf((char* restrict)markData, "%lu\r\n", lineCount);
        APP_FATFS_LogSD((const uint8_t*)markData, sizeof(uint32_t), MARK_LOG_IDENTIFIER);
        osThreadSuspend(NULL);
    }
}

/**
  * @brief  Helper function for transforming CAN Data to SD format
  * @retval Returns the number of bytes in formatted message
  */
static size_t APP_CAN_FormatSDData(uint8_t* dest, CANRxMessage* srcRxMsg)
{
    char data_str[80];
    int str_idx = 0;
    // Should stop at min(dlc, sizeof(data))
    for (int i = 0; i < srcRxMsg->header->DLC; i++) {
        str_idx += sprintf(&data_str[str_idx], " %02X", srcRxMsg->data[i] & 0xFF);
    }

    return sprintf((char* restrict)dest, "%X [%X]%s\r\n", (uint8_t)srcRxMsg->header->StdId, (uint8_t)srcRxMsg->header->DLC, data_str);
}
