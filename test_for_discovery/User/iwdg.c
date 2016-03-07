#include "iwdg.h"


void IWDG_Init(u8 prer, u16 rlr)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(prer);
    IWDG_SetReload(rlr);
	IWDG_ReloadCounter();
	IWDG_Enable();
	
}

/*****************************************************************************
 Prototype    : IWDG_Feed
 Description  : Œπ∂¿¡¢ø¥√≈π∑
 Input        : void  
 Output       : None
 Return Value : 
 Calls        : 
 Called By    : 
 
  History        :
  1.Date         : 2016/3/3
    Author       : sun
    Modification : Created function

*****************************************************************************/
void IWDG_Feed(void)
{
    IWDG_ReloadCounter();
}