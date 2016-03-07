#include "sys.h"
#include "delay.h"

#include "usart.h"

#include "led.h"


int main(void)
{
	delay_init(168);
	LED_Init();

	while(1)
		{
			/*GPIO_SetBits(GPIOD, GPIO_Pin_12);
			delay_ms(500);
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);

			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			delay_ms(500);
			GPIO_ResetBits(GPIOD, GPIO_Pin_13);

			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			delay_ms(500);
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);

			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			delay_ms(500);
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);
                        */
                        LED0 = 1;
                        delay_ms(500);
                        //LED0 = 0;
                        
                        LED1 = 1;
                        delay_ms(500);
                        //LED1 = 0;
                        
                        //LED2 = 1;
                        delay_ms(500);
                        //LED2 = 0;
                        
                        LED3 = 1;
                        delay_ms(500);
                        //LED3 = 0;
                        LED0 = 0;
                        LED1= 0;
                        LED2= 0;
                        LED3= 0;
                        delay_ms(500);
						
					
                        
		}
}
