#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

#define		RCC_BASE_ADD		(0x40021000)

/*define clk speed of RCC*/
#define		RCC_HSE_bypass		0
#define		RCC_HSE_Crystal		1
#define		RCC_HSI				2
#define		RCC_PLL				3

/*define input for PLL*/
#define		PLL_HSI		0
#define		PLL_HSE		1

#define		RCC_CR				*((u32 *)(RCC_BASE_ADD+0x00))
/*Clock control register*/
#define RCC_CR_PLLRDY		25
#define RCC_CR_PLLON		24
#define	RCC_CR_CSSON		19
#define	RCC_CR_HSEBYP		18
#define	RCC_CR_HSERDY		17
#define	RCC_CR_HSEON		16
#define	RCC_CR_HSICAL_7		15
#define	RCC_CR_HSICAL_6		14
#define	RCC_CR_HSICAL_5		13
#define	RCC_CR_HSICAL_4		12
#define	RCC_CR_HSICAL_3		11
#define	RCC_CR_HSICAL_2		10
#define	RCC_CR_HSICAL_1		9
#define	RCC_CR_HSICAL_0		8
#define RCC_CR_HSITRIM_4	7
#define RCC_CR_HSITRIM_3	6
#define RCC_CR_HSITRIM_2	5
#define RCC_CR_HSITRIM_1	4
#define RCC_CR_HSITRIM_0	3
#define	RCC_CR_HSIRDY		1
#define	RCC_CR_HSION		0
/************************************/

#define		RCC_CFGR			*((u32 *)(RCC_BASE_ADD+0x04))
/* CLK config   REG*/
#define RCC_CFGR_MCO2		26			// Microcontroller clock output
#define RCC_CFGR_MCO1		25			//
#define RCC_CFGR_MCO0		24			//
#define RCC_CFGR_USBPRE		22			// USB Prescaler
#define RCC_CFGR_PLLMUL_3	21			// PLL Mul factor
#define RCC_CFGR_PLLMUL_2	20			///
#define RCC_CFGR_PLLMUL_1	19			///
#define RCC_CFGR_PLLMUL_0	18			///
#define	RCC_CFGR_PLLXTPRE	17			// HSE	diriver for PLL entry
#define RCC_CFGR_PLLSRC		16			// PLL entry clock source
#define RCC_CFGR_ADCPRE_1	15			// ADC Prescaler
#define RCC_CFGR_ADCPRE_0	14			///
#define	RCC_CFGR_PPRE2_2	13			// APB high_speed prescaler (APB2)
#define	RCC_CFGR_PPRE2_1	12			///
#define	RCC_CFGR_PPRE2_0	11			///
#define	RCC_CFGR_PPRE1_2	10			// APB Low_speed prescaler (APB1)
#define	RCC_CFGR_PPRE1_1	9			///
#define	RCC_CFGR_PPRE1_0	8			///
#define	RCC_CFGR_HPRE_3		7			// AHB prescaler (SYS CLK Divider)
#define	RCC_CFGR_HPRE_2		6			// AHB prescaler
#define	RCC_CFGR_HPRE_1		5			// AHB prescaler
#define	RCC_CFGR_HPRE_0		4			// AHB prescaler
#define	RCC_CFGR_SWS_1		3			// System clock switch status(read only)
#define	RCC_CFGR_SWS_0		2			///
#define	RCC_CFGR_SW_1		1			//System clock switch
#define	RCC_CFGR_SW_0		0			//System clock switch

/***************************************/
#define		RCC_CIR				*((u32 *)(RCC_BASE_ADD+0x08))
#define		RCC_APB2RSTR		*((u32 *)(RCC_BASE_ADD+0x0C))
#define		RCC_APB1RSTR		*((u32 *)(RCC_BASE_ADD+0x10))
#define		RCC_AHBENR			*((u32 *)(RCC_BASE_ADD+0x14))
#define		RCC_APB2ENR			*((u32 *)(RCC_BASE_ADD+0x18))
#define		RCC_APB1ENR			*((u32 *)(RCC_BASE_ADD+0x1C))
#define		RCC_BDCR			*((u32 *)(RCC_BASE_ADD+0x20))
#define		RCC_CSR				*((u32 *)(RCC_BASE_ADD+0x24))



#endif
