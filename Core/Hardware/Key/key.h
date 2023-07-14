#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f4xx.h"

#define KEY0_RES	1
#define WK_UP_RES	2

uint8_t KEY_scan(uint8_t mode);
void USR_EXTI0_Callback(void);
void USR_EXTI4_Callback(void);
#endif
