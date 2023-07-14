#include "norflash.h"
#include "main.h"
#include "gpio.h"
#include "spi.h"
#include <stdio.h>

void norflash_Read(uint8_t* pBuffer, uint32_t readAddr, uint16_t len)
{
	SPI1_CS_L;
	//1、发送读命令
	SPI1_ReadWriteByte(0x03);

	//2、发送地址
	SPI1_ReadWriteByte(readAddr >> 16);
	SPI1_ReadWriteByte(readAddr >> 8);
	SPI1_ReadWriteByte(readAddr);

	//3、读取数据
	for(int i = 0; i < len; i++)
	{
		pBuffer[i] = SPI1_ReadWriteByte(0xff);
	}
	SPI1_CS_H;
}

uint8_t norflash_Wait_Busy(void)
{
	SPI1_CS_L;
	SPI1_ReadWriteByte(0x05);
	uint8_t busy_flag = SPI1_ReadWriteByte(0xff);
	SPI1_CS_H;

	return busy_flag;
}

void norflash_erase_sector(uint32_t CleanDddr)
{
	//1、写使能
	SPI1_CS_L;
	SPI1_ReadWriteByte(0x06);
	SPI1_CS_H;

	//2、等待空闲
	while(norflash_Wait_Busy()&0x01);

	//3、发送扇区擦除指令
	SPI1_CS_L;
	SPI1_ReadWriteByte(0x20);

	//4、发送地址
	SPI1_ReadWriteByte(CleanDddr >> 16);
	SPI1_ReadWriteByte(CleanDddr >> 8);
	SPI1_ReadWriteByte(CleanDddr);
	SPI1_CS_H;

	//5、等待空闲
	while(norflash_Wait_Busy()&0x01);
}

void norflash_Write_Page(uint8_t* pBuffer, uint32_t writeAddr, uint16_t len)
{
	//1、擦除扇区
	norflash_erase_sector(writeAddr);

	//2、写使能
	SPI1_CS_L;
	SPI1_ReadWriteByte(0x06);
	SPI1_CS_H;

	//3、发送页写指令
	SPI1_CS_L;
	SPI1_ReadWriteByte(0x02);

	//4、发送地址
	SPI1_ReadWriteByte(writeAddr >> 16);
	SPI1_ReadWriteByte(writeAddr >> 8);
	SPI1_ReadWriteByte(writeAddr);

	//5、要写入的数据
	for(int i = 0; i < len; i++)
	{
		SPI1_ReadWriteByte(pBuffer[i]);
	}

	//6、等待写入完成
	while(norflash_Wait_Busy()&0x01);
}
