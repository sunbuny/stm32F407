#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#define USE_FULL_ASSERT

int main(void)
{
	u8 t,len;
	u16 times = 0;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	uart_init(115200);
	LED_Init();
	LED0 = 1;

	while ( 1 )
	{
	    if(USART_RX_STA&0x8000)
	    	{
	    		len = USART_RX_STA&0x3fff;
				printf("\r\n您发送的消息为:\r\n");
				for ( t = 0 ; t < len; t++ )
				{
				    USART1->DR = USART_RX_BUF[t];
					while ( (USART1->SR&0x40) == 0)
					{
					    ;
					}
				}
				printf("\r\n\r\n");
				USART_RX_STA = 0;
	    	}
		else 
		{
		    times++;
			if ( times%5000 == 0 )
			{
			    printf("\r\n串口实验\r\n");
				printf("孙斌");
			}
			if(times%200 == 0) printf("请输入数据，回车键结束\r\n");
			if(times%30 == 0) LED0 =!LED0;
			delay_ms(10);
		}
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif