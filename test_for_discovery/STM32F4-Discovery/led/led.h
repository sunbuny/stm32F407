#ifndef __LED_H
#define __LED_H
#include "sys.h"
// LEDd的端口定义
#define LED0 PDout(12) //DS0
#define LED1 PDout(13) //DS1
#define LED2 PDout(14) //DS2
#define LED3 PDout(15) //DS3

void LED_Init(void);
#endif