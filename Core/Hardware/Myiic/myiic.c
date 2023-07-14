#include "myiic.h"
#include "main.h"
#include "gpio.h"
#include <stdio.h>

void delay_us(uint32_t us)
{
	uint32_t Delay = us * 168/4;
	do
	{
		__NOP();
	}
	while (Delay --);
}


void SDA_IN(void)
{
	GPIO_InitTypeDef GPIO_InitStruct= {0};
	GPIO_InitStruct.Pin = IIC_SDA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
void SDA_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = IIC_SDA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void IIC_Init(void)
{
	IIC_SDA_H;
	IIC_SCL_H;
}

/*产生起始信号*/
void IIC_Start(void)
{
	SDA_OUT();
	IIC_SDA_H;
	IIC_SCL_H;
	delay_us(5);

	IIC_SDA_L;
	delay_us(5);

	IIC_SCL_L;
}

/*产生停止信号*/
void IIC_Stop(void)
{
	SDA_OUT();
	IIC_SCL_L;
	IIC_SDA_L;
	delay_us(4);

	IIC_SCL_H;
	IIC_SDA_H;
	delay_us(4);
}

/* 等待应答信号到来
 * 返回值：1，接收应答失败
 * 		0，接收应答成功
 * */
uint8_t IIC_Wait_Ack(void)
{
	uint8_t ucErrTime = 0;
	SDA_IN();
	IIC_SDA_H;delay_us(1);
	IIC_SCL_H;delay_us(1);
	while(SDA_read)
	{
		ucErrTime++;
		if(ucErrTime > 250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL_L;
	return 0;
}

/*产生应答信号*/
void IIC_Ack(void)
{
	IIC_SCL_L;
	SDA_OUT();
	IIC_SDA_L;
	delay_us(2);

	IIC_SCL_H;
	delay_us(2);

	IIC_SCL_L;
}

/*产生非应答信号*/
void IIC_NAck(void)
{
	IIC_SCL_L;
	SDA_OUT();
	IIC_SDA_H;
	delay_us(2);

	IIC_SCL_H;
	delay_us(2);

	IIC_SCL_L;
}

/*发送一个字节*/
void IIC_Send_Byte(uint8_t txd)
{
	uint8_t t;
	SDA_OUT();
	IIC_SCL_L;
	for(t = 0; t < 8; t++)
	{
		if((txd&0x80) >> 7)
			IIC_SDA_H;
		else
			IIC_SDA_L;
		txd<<=1;
		delay_us(2);
		IIC_SCL_H;
		delay_us(2);
		IIC_SCL_L;
		delay_us(2);
	}
}

/*读取一个字节*/
uint8_t IIC_Read_Byte(uint8_t ack)
{
	uint8_t receive = 0;
	SDA_IN();
	for(int i = 0; i < 8; i++)
	{
		IIC_SCL_L;
		delay_us(2);
		IIC_SCL_H;
		receive<<=1;
		if(SDA_read)receive++;
		delay_us(1);
	}
	if(!ack)
		IIC_NAck();
	else
		IIC_Ack();

	return receive;
}






