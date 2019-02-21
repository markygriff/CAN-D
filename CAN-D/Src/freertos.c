/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "bridge.h"
#include "cmsis_os.h"
#include "main.h"
#include "task.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern osThreadId bridgeConfigTaskHandle;
extern osThreadId USBStreamTaskHandle;
extern osThreadId GPSMonitorTaskHandle;

extern osMessageQId USBStreamQueueHandle;
extern osMessageQId UARTGprmcQueueHandle;

/* Private function prototypes -----------------------------------------------*/
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Exported functions --------------------------------------------------------*/
/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void)
{
    /* add mutexes, ... */

    /* add semaphores, ... */

    /* start timers, add new ones, ... */

    /* Create the thread(s) */
    osThreadDef(bridgeConfigTask, APP_BRIDGE_CANConfigTask, osPriorityNormal, 0, 128);
    bridgeConfigTaskHandle = osThreadCreate(osThread(bridgeConfigTask), NULL);

    osThreadDef(USBStreamTask, APP_BRIDGE_USBStreamTask, osPriorityNormal, 0, 128);
    USBStreamTaskHandle = osThreadCreate(osThread(USBStreamTask), NULL);

    osThreadDef(GPSMonitorTask, APP_BRIDGE_GPSMonitorTask, osPriorityNormal, 0, 128);
    GPSMonitorTaskHandle = osThreadCreate(osThread(GPSMonitorTask), NULL);

    /* add threads, ... */

    /* add queues, ... */
    osMessageQDef(USBStreamQueue, 8, uint8_t);
    USBStreamQueueHandle = osMessageCreate(osMessageQ(USBStreamQueue), NULL);

    osMessageQDef(UARTGprmcQueue, 128, char);
    UARTGprmcQueueHandle = osMessageCreate(osMessageQ(UARTGprmcQueue), NULL);
}

/* Private functions ---------------------------------------------------------*/
