


#ifndef		NULL
#define		NULL			((void *)0)
#endif
#include "Std_Types.h"
#include "Bit_math.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"





static	void	(*EXTI0_CallBack)	(void)	= NULL;

void		EXTI0_voidInit(void)
{
	// to select the input for extI0 : port a,b,...
	// if PORTA
#ifndef			AFIO_EXTICR
		#define		AFIO_EXTICR_ADD		(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_EXTICR_ADD+0x08))
	#endif
#if EXTI_0	==	PORTA
	CLR_BIT(AFIO_EXTICR1,0);
	CLR_BIT(AFIO_EXTICR1,1);
	CLR_BIT(AFIO_EXTICR1,2);
	CLR_BIT(AFIO_EXTICR1,3);


	//select PORTB
#elif EXTI_0	==	PORTB
	SET_BIT(AFIO_EXTICR1,0);
	CLR_BIT(AFIO_EXTICR1,1);
	CLR_BIT(AFIO_EXTICR1,2);
	CLR_BIT(AFIO_EXTICR1,3);
#endif

	//EXTI_voidDisableInt(0);

}
void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}
void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR,line_num);
}

void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}

void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		//Fptr = EXTI0_CallBack;
		EXTI0_CallBack= Fptr;
	}
}

//void	EXTI0_IRQHandler(void)
//{
//	EXTI0_CallBack();
	/*	Clear the Flag			*/
//}


