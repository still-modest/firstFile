#ifndef __NORFLASH_H__
#define __NORFLASH_H__

#include "stm32f4xx.h"
#include "gpio.h"

#define SPI1_CS_H HAL_GPIO_WritePin(SPI1_MOSI_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET)
#define SPI1_CS_L HAL_GPIO_WritePin(SPI1_MOSI_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET)

void norflash_Read(uint8_t* pBuffer, uint32_t readAddr, uint16_t len);
uint8_t norflash_Wait_Busy(void);
void norflash_erase_sector(uint32_t CleanDddr);
void norflash_Write_Page(uint8_t* pBuffer, uint32_t writeAddr, uint16_t len);

#endif
