/**
  ******************************************************************************
  * File Name          : SPI.h
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __spi_H
#define __spi_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"


extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;


void MX_SPI1_Init(void);
void MX_SPI2_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__ spi_H */
