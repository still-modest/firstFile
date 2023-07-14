#ifndef __MYIIC_H__
#define __MYIIC_H__

#include "stm32f4xx.h"
#include "gpio.h"

#define IIC_SCL_H HAL_GPIO_WritePin(IIC_SCL_GPIO_Port, IIC_SCL_Pin, GPIO_PIN_SET)
#define IIC_SCL_L HAL_GPIO_WritePin(IIC_SCL_GPIO_Port, IIC_SCL_Pin, GPIO_PIN_RESET)

#define IIC_SDA_H HAL_GPIO_WritePin(IIC_SDA_GPIO_Port, IIC_SDA_Pin, GPIO_PIN_SET)
#define IIC_SDA_L HAL_GPIO_WritePin(IIC_SDA_GPIO_Port, IIC_SDA_Pin, GPIO_PIN_RESET)

#define SDA_read HAL_GPIO_ReadPin(IIC_SDA_GPIO_Port, IIC_SDA_Pin)

void delay_us(uint32_t us);
void SDA_IN(void);
void SDA_OUT(void);
void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
uint8_t IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);
void IIC_Send_Byte(uint8_t txd);
uint8_t IIC_Read_Byte(uint8_t ack);

#endif
