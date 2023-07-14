#ifndef __AT24C02_H__
#define __AT24C02_H__

#include "stm32f4xx.h"
#include "gpio.h"

void at24c02_write_one_byte(uint16_t addr, uint8_t data);
uint8_t at24c02_read_one_byte(uint16_t addr);
void at24c02_write(uint16_t addr, uint8_t *pBuffer, uint16_t len);
void at24c02_read(uint16_t addr, uint8_t *pBuffer, uint16_t len);
uint8_t at24c02_check(void);

#endif
