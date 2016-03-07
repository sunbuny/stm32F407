#include "timer.h"
#include "led.h"

void TIM3_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructInit;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    TIM_TimeBaseStructInit.TIM_Period = arr;
    TIM_TimeBaseStructInit.TIM_Prescaler = psc;
    TIM_TimeBaseStructInit.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructInit.TIM_ClockDivision = TIM_CKD_DIV1;

    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructInit);

    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM3, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}      

void TIM3_IRQHandler(void)
{
    if ( TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
    {
        LED1 = !LED1;
    }
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
}
