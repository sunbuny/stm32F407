#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init(168);
    LED_Init();

    TIM3_Init(5000 - 1, 8400 - 1);
    while ( 1 )
    {
        LED0 = !LED0;
        delay_ms(200);
    }
}