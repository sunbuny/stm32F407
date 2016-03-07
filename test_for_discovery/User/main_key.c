#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"

int main(void)
{
	u8 key;
	delay_init(168);
	LED_Init();
	KEY_Init();

	LED0 = 1;
	while(1)
		{
			key = KEY_Scan(0);
			if(key)
				{
					switch ( key)
					{
					    case 1:
					        LED0 = !LED0;
					        break;
					    default:
					        break;
					}
				}
		}
	
}