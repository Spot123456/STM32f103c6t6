#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"RCC_private.h"
#include	"RCC_config.h"

void		RCC_voidSysClkInt(void)
{
	/*choose the source of clk speed */

#if RCC_SYS_CLK	== RCC_HSE_bypass
//set_bit(RCC_CR,RCC_CR_HSEBYP);
RCC_CR|=(1<<RCC_CR_HSEBYP)|(1<<RCC_CR_HSEON); // HSE_bypass(RC) enable
while(!RCC_CR_HSERDY); // read the enable HSE **

/*system CLK SWITCH : if the EXTrenal CLK in case of failure or Standby mode*/
SET_BIT(RCC_CFGR,0);
CLR_BIT(RCC_CFGR,1);


#elif RCC_SYS_CLK == RCC_HSE_Crystal
SET_BIT(RCC_CR,RCC_CR_HSEON); // HSE Crystal enable
while(!RCC_CR_HSERDY); // read the enable HSE **

/*system CLK SWITCH : if the EXTrenal CLK in case of failure or Standby mode*/
SET_BIT(RCC_CFGR,0);
CLR_BIT(RCC_CFGR,1);

#elif RCC_SYS_CLK == RCC_HSI
SET_BIT(RCC_CR,RCC_CR_HSION); // enable HSI

while(!RCC_CR_HSIRDY); // read if its enable
/*system CLK SWITCH : if the EXTrenal CLK in case of failure or Standby mode*/
CLR_BIT(RCC_CFGR,0);
CLR_BIT(RCC_CFGR,1);

#elif RCC_SYS_CLK == RCC_PLL
/*
 * selection of HSI oscillator divided by 2 or HSE oscillator for PLL
input clock, and multiplication factor) must be done before enabling the PLL. Once the PLL
enabled, these parameters cannot be changed.
 */

	#if PLL_INPUT == PLL_HSI

	CLR_BIT(RCC_CFGR,16); // select HSI/2


	#elif PLL_INPUT == PLL_HSE // select HSI/2
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
	#endif
#if PLL_MUL_Factor == PLL_MUl_2  // input clk MUL by 2
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);

#elif PLL_MUL_Factor == PLL_MUl_3 // input clk MUL by 3
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_3);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_2);
	CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_1);
	SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL_0);
#endif
#endif

	
}
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	SET_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}
	
}
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	CLR_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}	
}


void RCC_voidEnableADC_Prescaler()
{
	RCC_CFGR |= (2<<14);  // Prescaler 6, ADC Clock = 72/6 = 12 MHz ******************
}




