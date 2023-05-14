#ifndef	_EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H


#include "Std_Types.h"
#include "Bit_math.h"

#include "EXTI_private.h"
#include "EXTI_config.h"




void		EXTI0_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));


#define RISING_EDGE		0
#define	FALLING_EDGE	1
#define IOC				2			// interrupt on any change


// define all line on interrupt for pins : ( line_0) --> referred to (a0 or b0 or c0 or....)

#define LINE_0			0
#define LINE_1			1
#define LINE_2			2
#define LINE_3			3
#define LINE_4			4
#define LINE_5			5
#define LINE_6			6
#define LINE_7			7
#define LINE_8			8
#define LINE_9			9
#define LINE_10			10
#define LINE_11			11
#define LINE_12			12
#define LINE_13			13
#define LINE_14			14
#define LINE_15			15



#endif
