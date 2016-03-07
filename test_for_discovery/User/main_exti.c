#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(128);
	uart_init(115200);
	LED_Init();
	EXTIX_Init();

	LED0 = 1;
	while ( 1 )
	{
	    printf("OK\r\n");
		delay_ms(1000);
	}
}
