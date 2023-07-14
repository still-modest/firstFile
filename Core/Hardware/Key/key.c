#include "key.h"
#include "main.h"
#include "led.h"
#include "at24c02.h"
#include "norflash.h"
#include "usart.h"
uint8_t IIC_SendBuffer[] = {"test IIC success"};
#define IIC_SIZE sizeof(IIC_SendBuffer)
uint8_t IIC_RevBuffer[IIC_SIZE];

uint8_t SPI_SendBuffer[] = {"test SPI success"};
#define SPI_SIZE sizeof(SPI_SendBuffer)
uint8_t SPI_RevBuffer[SPI_SIZE];

uint8_t KEY_scan(uint8_t mode)
{
	static uint8_t key_up=1;     //按键松开标志
	if(mode==1)key_up=1;    //支持连按
	if(key_up &&( HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) || HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin)))
	{
		HAL_Delay(10);
		key_up = 0;
		if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)) return KEY0_RES;
		if(HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin)) return WK_UP_RES;
	}
	else if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == 0 &&HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin) == 0)
		key_up = 1;
	return 0;
}

void USR_EXTI0_Callback(void)
{
	if(HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin))
	{
		norflash_Write_Page(&SPI_SendBuffer, 0x123456, SPI_SIZE);
		printf("SPI write data \r\n");
		at24c02_write(0, &IIC_SendBuffer, IIC_SIZE);
		printf("IIC write data \r\n");
		led0_switch();
	}
}

void USR_EXTI4_Callback(void)
{
	if(HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin))
	{
		norflash_Read(&SPI_RevBuffer, 0x123456, SPI_SIZE);
		printf("SPI read data : %s \r\n", SPI_RevBuffer);
		at24c02_read(0, &IIC_RevBuffer, IIC_SIZE);
		printf("IIC read data : %s \r\n", IIC_RevBuffer);
		led1_switch();
	}
}
