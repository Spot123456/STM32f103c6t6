
#ifndef 	_EXTI_PRIVATE_H
#define 	_EXTI_PRIVATE_H





#define		EXTI_BASE_ADD			0x40010400

//#define		AFIO_BASE_ADD	     	(0x40010000)
//#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))

typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))


#define			LINE_0			0
#define			LINE_1			1
#define			LINE_2			2
#define			LINE_3			3

#define			LINE_4			4
#define			LINE_5			5
#define			LINE_6			6
#define			LINE_7			7

#define			LINE_8			8
#define			LINE_9			9
#define			LINE_10			10
#define			LINE_11			11

#define			LINE_12			12
#define			LINE_13			13
#define			LINE_14			14
#define			LINE_15			15


#define			RISING_EDGE		0
#define			FALLING_EDGE	1
#define 		IOC				2




#endif
