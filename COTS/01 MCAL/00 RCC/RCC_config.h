#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

/*
 * you can config speed between 4 choices
 * 1- RCC_HSE_bypass
 * 2-RCC_HSE_Crystal
 * 3-RCC_HSI
 * 4-RCC_PLL
 * NOTE THAT : if PLL Choise speed and the input of pll
 */

#define		RCC_SYS_CLK			RCC_HSI
#define		PLL_INPUT			PLL_HSE
#define 	PLL_MUL_Factor		PLL_MUL_2



#endif
