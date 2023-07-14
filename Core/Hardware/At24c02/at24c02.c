#include "../At24c02/at24c02.h"

#include "myiic.h"
#include "main.h"
#include "gpio.h"
#include <stdio.h>

/*at24c02写一个字节*/
void at24c02_write_one_byte(uint16_t addr, uint8_t data)
{
	//1、发送其实信号
	IIC_Start();
	//2、发送通信地址（写操作地址）
	IIC_Send_Byte(0xA0);
	//3、等待应答信号
	IIC_Wait_Ack();
	//4、发送内存地址
	IIC_Send_Byte(addr);
	//5、等待应答信号
	IIC_Wait_Ack();
	//6、发送写入数据
	IIC_Send_Byte(data);
	//7、等待应答信号
	IIC_Wait_Ack();
	//8、发送停止信号
	IIC_Stop();
	//9、等待EEPROM写入完成
	HAL_Delay(10);
}

/*at24c02读取一个字节*/
uint8_t at24c02_read_one_byte(uint16_t addr)
{
	//1、发送起始信号
	IIC_Start();
	//2、发送通信地址（写操作地址）
	IIC_Send_Byte(0xA0);
	//3、等待应答信号
	IIC_Wait_Ack();
	//4、发送内存地址
	IIC_Send_Byte(addr);
	//5、等待应答信号
	IIC_Wait_Ack();

	//6、发送起始信号
	IIC_Start();
	//7、发送通信地址（读操作地址）
	IIC_Send_Byte(0xA1);
	//8、等待应答信号
	IIC_Wait_Ack();
	//9、等待接收数据
	uint8_t rec = IIC_Read_Byte(0);
	//10、发送非应答信号（获取地址即可）

	//11、发送停止信号
	IIC_Stop();

	return rec;
}

/*at24c02写多个字节*/
void at24c02_write(uint16_t addr, uint8_t *pBuffer, uint16_t len)
{
	while(len--)
	{
		at24c02_write_one_byte(addr, *pBuffer);
		addr++;
		pBuffer++;
	}
}
/*at24c02读取多个字节*/
void at24c02_read(uint16_t addr, uint8_t *pBuffer, uint16_t len)
{
	while(len)
	{
		*pBuffer++= at24c02_read_one_byte(addr++);
		len--;
	}
}

uint8_t at24c02_check(void)
{
	uint8_t temp;
	temp = at24c02_read_one_byte(255);
	if(temp == 0x55)	return 0;
	else
	{
		at24c02_write_one_byte(255, 0x55);
		temp = at24c02_read_one_byte(255);
		if(temp == 0x55)	return 0;
	}
	return 1;
}
