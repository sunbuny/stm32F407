#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

int main(void)
{
    u16 led0pwmval = 0;
    u8 dir = 1;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init(168);
    uart_init(115200);
    TIM4_PWM_Init(500 - 1, 84 - 1);
    //printf("initover\r\n");
    printf("\r\n您发送的消息为:\r\n");
    while ( 1 )
    {
        delay_ms(10);
      //printf("initover\r\n");
        if(dir)
        {
          led0pwmval++;
       printf("%d\r\n",led0pwmval);
        }
        else 
        {
          led0pwmval--;
           printf("%d\r\n",led0pwmval);
        }
        if(led0pwmval > 500)dir = 0;
        if(led0pwmval == 0 )dir = 1;

        TIM_SetCompare1(TIM4, led0pwmval);
        printf("over");
    }
}
