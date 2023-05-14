#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

#define		RCC_AHB				0
#define		RCC_APB1			1
#define		RCC_APB2			2

/*MUL factor to PLL for Input clock*/
#define		PLL_MUl_2			0		//multiplication factor by 2
#define		PLL_MUl_3			1		//multiplication factor by 3
#define		PLL_MUl_4			2		//multiplication factor by 4
#define		PLL_MUl_5			3		//multiplication factor by 5

/*APB high-speed prescaler (APB2) OR  APB low-speed prescaler (APB1)*/
#define		HCLK_not_div		0b000		//0xx: HCLK not divided
#define		HCLK_2				0b100		//HCLK divided by 2
#define		HCLK_4				0b101		//HCLK divided by 4
#define		HCLK_8				0b110		//HCLK divided by 8
#define		HCLK_16				0b111		//HCLK divided by 16

/*AHB	prescaler*/
#define		SYSCLK_not_div		0			//0xx x: SYSCLK not divided
#define		SYSCLK_2			8			//100 0: SYSCLK divide by 2
#define		SYSCLK_4			9			//100 1: SYSCLK divide by 4
#define		SYSCLK_8			10			//101 0: SYSCLK divide by 8
#define		SYSCLK_16			11			//101 1: SYSCLK divide by 16


void		RCC_voidSysClkInt(void);
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId);
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId);

void		RCC_voidEnableADC_Prescaler(); // work at less than 14mhz

#endif
