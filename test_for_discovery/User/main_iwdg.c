#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "iwdg.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init();
	KEY_Init();
	delay_ms(100);
	IWDG_Init(4, 1000);
	LED0 = 1;
	while ( 1 )
	{
	    if(KEY_Scan(0) == 1)
	    	{
	    	    IWDG_Feed();
	    	}
		delay_ms(10);
	}
}
