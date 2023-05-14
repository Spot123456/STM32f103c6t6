
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"ADC_interface.h"
#include	"ADC_private.h"
#include	"ADC_config.h"



//	NOTE : dont forget init the pins input analog




void	ADC_Init()
{
	// enable ADC1 clock      --> RCC
	// sampling time
	//adc Prescalar pclk2/2		--> RCC
	//analog input channel 1
	// sw trigger
	// conversion seq start at ch 1
	// //			// length 1
	// enable ADC



	//Enable ADC on
	SET_BIT(ADC1->CR2,0);
	//Discontinuous mode on regular channels
	SET_BIT(ADC1->CR1,11);

	// Interrupt enable for EOC
	SET_BIT(ADC1->CR1,5);
	//single conv
	CLR_BIT(ADC1->CR2,1);

	ADC1->SMPR1|=(0<<3); 	// sampling time channel 1 (1.5) cycles




}
u16	ADC_Start_Single_Conversion(u8 channel)
{
	u16 data;

	// regular channel seq lenght -->1 7alyan
		ADC1->SQR1|=(1<<20);

	// sq1 --_ hyb2a feha channel 1 aly ana m5tarha fe el config
	ADC1->SQR3|=(1<<0);

	// start conv
	SET_BIT(ADC1->CR2,22);
	//	wait for conv com
	while(GET_BIT(ADC1->SR,1)==0);
	// read data
	data= ADC1->DR;
	return data;
}



/*
void	ADC_Init()
{
	//select the analog watch dog guard
	// select channel 0
	CLR_BIT(ADC1->CR1,0);
	CLR_BIT(ADC1->CR1,1);
	CLR_BIT(ADC1->CR1,2);
	CLR_BIT(ADC1->CR1,3);
	CLR_BIT(ADC1->CR1,4);
	
	//select mode : single mode or Scan mode
#if mode == single_conv
	CLR_BIT(ADC1->CR1,8);	// disable the Scan mode
	SET_BIT(ADC1->CR1,9);	// Enable watchdog single channel
	CLR_BIT(ADC1->CR2,1);	// single conv mode


	#elif	mode == Scan_conv
	SET_BIT(ADC1->CR1,8);	// Enable Scane mode
	CLR_BIT(ADC1->CR1,9);	// Enable watchdog all channel
#endif

	//sample tim of reg is 1.5 cycle
	CLR_BIT(ADC1->Channel[0].SMPR2,0);
	CLR_BIT(ADC1->Channel[0].SMPR2,1);
	CLR_BIT(ADC1->Channel[0].SMPR2,2);

	//direct memory access disable
	CLR_BIT(ADC1->CR2,8);

	//read right Alignment
	CLR_BIT(ADC1->CR2,11);


}

u16	ADC_Start_Single_Conversion(u8 channel)
{
	u16 local_EndConv;

	// select length = 0 : i.e 1 conversion
	ADC1->Channel[0].SQR1 &=~(1<<20);

	// select channel any channel
	ADC1->Channel[0].SQR3 |=(channel<<0);

	//Enable ADC start conv
	SET_BIT(ADC1->CR2,0);

	//wait to get the read from conversion
	while((GET_BIT(ADC1->SR,1))==1);

	//read the data from regular channel
	local_EndConv=ADC1->Channel[0].DR;
	return local_EndConv;

}*/


/*
reading=ADC_Start_Conversion(pin0); // temp oin port A pin 0
analog= ((uint32)reading*5000)/(256); // equation for temp to work
Temp=analog/10;
*/








