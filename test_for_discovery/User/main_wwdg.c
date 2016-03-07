#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "wwdg.h"

int main(void)
{
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
   delay_init(168);
   LED_Init();
   KEY_Init();
   LED0 = 1;
   delay_ms(300);
   WWDG_Init(0x7f, 0x5f, WWDG_Prescaler_8);

   while ( 1 )
   {
       LED0 = 0;
   }
}
