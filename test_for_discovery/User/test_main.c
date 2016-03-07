#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStructure

void Delay(__IO uint32_t nCount);

int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	while(1)
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			Delay(0x3fffff);

			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			Delay(0x3fffff);

			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			Delay(0x3fffff);

			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			Delay(0x3fffff);

			GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			
		}
		
}

void Delay(__IO uint32_t nCount)
{
	while(nCount--);
}
