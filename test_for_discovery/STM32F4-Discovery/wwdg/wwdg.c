#include "wwdg.h"
#include "led.h"

u8 WWDG_CNT = 0x7f;

void WWDG_Init(u8 tr,u8 wr, u32 fprer)
{
    NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

	WWDG_CNT = tr&WWDG_CNT;
	WWDG_SetPrescaler(fprer);
	WWDG_SetWindowValue(wr);
	WWDG_Enable(WWDG_CNT);

	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

	WWDG_ClearFlag();
	WWDG_EnableIT();
}

void WWDG_IRQHandler(void)
{
    WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag();
	LED1 = !LED1;
}