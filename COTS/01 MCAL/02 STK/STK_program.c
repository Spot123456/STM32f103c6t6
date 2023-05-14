#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"STK_interface.h"
#include	"STK_private.h"
#include	"STK_config.h"

#ifndef		NULL
#define		NULL		(void *)0
#endif

static	void	(*STK_CallBack)	(void)	=	NULL;
static	u8		STK_u8ModeOfInterval;

void	STK_voidInit()
{
		/*		RCC == HSI		*/
		#if		STK_CLK_SRC	==	STK_AHB_DIV_8
		STK	->CTRL = 0x00000000;
		#elif	STK_CLK_SRC	==	STK_AHB
			STk -> CTRL = 0x00000004;
		#elif	#error	"Wrong choice of SysTick Clock Source!"
		#endif
}
void	STK_voidSetBusyWait(u32	Ticks)
{
	/*	Load ticks to Load Register 	*/
	STK	 -> LOAD = Ticks;
	/*	Start the timer 				*/
	SET_BIT(STK	 -> CTRL , 0);
	/*	Wait till the flag is raised 	*/
	while((GET_BIT(STK	 -> CTRL , 16 ))==0)
	{
		asm("NOP");
	}
	/*	Stop the timer					*/
	CLR_BIT(STK -> CTRL , 0);
	STK ->	LOAD	=	0;
	STK ->	VAL		=	0;
}
void	STK_voidSetIntervalSingle(u32	Ticks, void (*Pf)(void))
{
	/*	Load ticks to Load Register 	*/
	STK -> LOAD = Ticks;
	/*	Start the timer 				*/
	SET_BIT(STK -> CTRL , 0);
	/*	Save Call Back Function		 	*/
	STK_CallBack =	Pf;
	/*	Enable STK Interrupt		 	*/
	SET_BIT(STK -> CTRL , 1);
	/*	Set the mode single Intervale	*/
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
}
void	STK_voidSetIntervalPeriodic(u32	Ticks, void (*Pf)(void))
{
		/*	Load ticks to Load Register 	*/
	STK -> LOAD = Ticks;
	/*	Start the timer 				*/
	SET_BIT(STK -> CTRL , 0);
	/*	Save Call Back Function		 	*/
	STK_CallBack =	Pf;
	/*	Enable STK Interrupt		 	*/
	SET_BIT(STK -> CTRL , 1);
	/*	Set the mode single Intervale	*/
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
}
void	STK_voidStopInterval()
{
		/*	Disable The Interrupt			*/
		CLR_BIT(STK -> CTRL , 1);
		/*	Stop the timer					*/
		CLR_BIT(STK -> CTRL , 0);
		STK ->	LOAD	=	0;
		STK ->	VAL		=	0;	
}
u32		STK_u32GetElapsedTime()
{
	u32	Local_u32ElapsedTime;
	Local_u32ElapsedTime	=	((STK -> LOAD)-(STK -> VAL));
	return	Local_u32ElapsedTime;	
}
u32		STK_u32GetRemainingTime()
{
	u32	Local_u32Remaining;
	Local_u32Remaining	=	STK -> VAL;
	return	Local_u32Remaining;
}


void	SysTick_Handler()
{
	u8 Local_u8Temp;
	if(STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{	
		/*	Disable The Interrupt			*/
		CLR_BIT(STK -> CTRL , 1);
		/*	Stop the timer					*/
		CLR_BIT(STK -> CTRL , 0);
		STK ->	LOAD	=	0;
		STK ->	VAL		=	0;
	}
	STK_CallBack();
	/*	to clear the timer flag just read it */
	Local_u8Temp	=	GET_BIT(STK -> CTRL,16);
}





