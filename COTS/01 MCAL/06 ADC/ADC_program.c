
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"ADC_interface.h"
#include	"ADC_private.h"
#include	"ADC_config.h"
#include 	"DIO_interface.h"
#include 	"led.h"








/*
 * ADC_prg.c
 *
 *  Created on: Mar 9, 2023
 *      Author: abdal
 */

	/*******************       Includes      ********************/



	/******************* Functions Definition ********************/
/*void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}*/
/*void	ADC_Init()	(void)
{
	// ON ADC -> ADON -> 1
	SET_BIT(ADC->CR2 , 0);
	_delay_ms(20);

	// Set External event select for regular group -> SWSTART -> 111
	SET_BIT(ADC->CR2 , 19);
	SET_BIT(ADC->CR2 , 17);
	SET_BIT(ADC->CR2 , 18);

	SET_BIT(ADC->CR2 , 20);
	// Set  Data alignment -> Right Alignment -> ALIGN > 0
	SET_BIT(ADC->CR2 , 11);
	// Set Single conversion mode -> CONT -> 0
	CLR_BIT(ADC->CR2 , 1);
	// Set Channel x Sample time selection -> Default -> 1.5 Cycle

	// Set Number of Conversion in Regular Mode -> Default -> 1


	// Start Calibration -> CAL -> 1
	SET_BIT(ADC->CR2 , 2);
	while(GET_BIT(ADC->CR2 , 2) != 0);

}
u16		ADC_u16_read	(Channel_ID Copy_enuChannel)
{
	u32 Local_u32Reading;
	// Set Channel
	if(Copy_enuChannel <= CHANNEL_9)
	{

		//ADC->SQR3 &= 0xfffffff0; // Clear 0 -> 4 bits
		//ADC->SQR3 |= Copy_enuChannel;
		CLR_BIT(ADC->SQR3 , 0);
		CLR_BIT(ADC->SQR3 , 1);
		CLR_BIT(ADC->SQR3 , 2);
		CLR_BIT(ADC->SQR3 , 3);
		CLR_BIT(ADC->SQR3 , 4);

	}

	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC->CR2 , 22);
	// Wait until the end of conversion -> SWSTART -> 0
	//while(GET_BIT(ADC->CR2 , 22) == 1);

	while((GET_BIT(ADC->SR , 1)) != 1);
	//led_blink(PIN10,PORTA);

	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC->CR2 , 0);
	// Wait until the end of conversion -> SWSTART -> 0
	while(GET_BIT(ADC->SR , 1) != 1);

	// Get data -> 0 -> 15
//	Local_u32Reading = (ADC->DR) & 0x0000ffff;
	// Return Data
	return ADC->DR;
}*/

























/*

#include "ADC_interface.h"

void	ADC_voidInit(void){

	ADC_ScanConvMode() ;  // SCAN mode enabled
	ADC_singOrcontainusConvMode();    // enable continuous conversion mode
	ADC_ExternalTrigConv();  // External Event selection pointed to SWSTART bit
	ADC_DataAligment();   // Data Alignment RIGHT
	//Set the Regular channel sequence length in ADC_SQR1
	ADC_NbrOfConversion();
	// Set the TSVREFE Bit to wake the sensor
	ADC_tempSenEnable();
	// Enable or disable  DMA for ADC
	ADC_DMAenable();

}


//adc enable
void	ADC_voidEnable(void){
SET_BIT(ADC1->CR2,0);  // ADON =1 enable ADC1
	u32 delay = 10000;
	while (delay--);
}
//ADC_start adc
void ADC_Start(void){
	 // Clear Status register
	CLR_BIT(  ADC1->SR,0);
	CLR_BIT(  ADC1->SR,1);
	CLR_BIT(  ADC1->SR,2);
	CLR_BIT(  ADC1->SR,3);
	CLR_BIT(  ADC1->SR,4);

	SET_BIT(ADC1->CR2 ,20);// Conversion on external event enabled
	SET_BIT(ADC1->CR2,22);// Start conversion
}

void ADC_channelSetup(u8 channel , u8 SEQuance,u8 SamplingTime){
switch(SEQuance){
case SEQ1:	ADC1->SQR3 |= (channel<<0); 		  break;
case SEQ2:	ADC1->SQR3 |= (channel<<5); 		  break;
case SEQ3:	ADC1->SQR3 |= (channel<<10); 		  break;
case SEQ4:	ADC1->SQR3 |= (channel<<15); 		  break;
case SEQ5:	ADC1->SQR3 |= (channel<<20); 		  break;
case SEQ6:	ADC1->SQR3 |= (channel<<25); 		  break;
case SEQ7:	ADC1->SQR2 |= (channel<<0); 		  break;
case SEQ8:	ADC1->SQR2 |= (channel<<5);			  break;
case SEQ9:	ADC1->SQR2 |= (channel<<10);		  break;
case SEQ10:	ADC1->SQR2 |= (channel<<15);		  break;
case SEQ11:	ADC1->SQR2 |= (channel<<20);		  break;
case SEQ12:	ADC1->SQR2 |= (channel<<25);		  break;
case SEQ13:	ADC1->SQR1 |= (channel<<0);			  break;
case SEQ14:	ADC1->SQR1 |= (channel<<5);			  break;
case SEQ15:	ADC1->SQR1 |= (channel<<10);		  break;
case SEQ16:	ADC1->SQR1 |= (channel<<15);		  break;
}
switch (channel){
case ADC_channe0: ADC1->SMPR2 |= (SamplingTime<<0);		break;
case ADC_channe1: ADC1->SMPR2 |= (SamplingTime<<3);		break;
case ADC_channe2: ADC1->SMPR2 |= (SamplingTime<<6);		break;
case ADC_channe3: ADC1->SMPR2 |= (SamplingTime<<9);		break;
case ADC_channe4: ADC1->SMPR2 |= (SamplingTime<<12);		break;
case ADC_channe5: ADC1->SMPR2 |= (SamplingTime<<15);		break;
case ADC_channe6: ADC1->SMPR2 |= (SamplingTime<<18);		break;
case ADC_channe7: ADC1->SMPR2 |= (SamplingTime<<21);		break;
case ADC_channe8: ADC1->SMPR2 |= (SamplingTime<<24);		break;
case ADC_channe9: ADC1->SMPR2 |= (SamplingTime<<27);		break;

case ADC_channe10: ADC1->SMPR1 |= (SamplingTime<<0);		break;
case ADC_channe11: ADC1->SMPR1 |= (SamplingTime<<3);		break;
case ADC_channe12: ADC1->SMPR1 |= (SamplingTime<<6);		break;
case ADC_channe13: ADC1->SMPR1 |= (SamplingTime<<9);		break;
case ADC_channe14: ADC1->SMPR1 |= (SamplingTime<<12);		break;
case ADC_channe15: ADC1->SMPR1 |= (SamplingTime<<15);		break;
case ADC_channe16: ADC1->SMPR1 |= (SamplingTime<<18);		break;
case ADC_channe17: ADC1->SMPR1 |= (SamplingTime<<21);		break;

}

}



//get flag status
void ADC_getStatusflag(u8 flag){
	if (flag == AWD){
		GET_BIT(ADC1->SR,0);
	}else if (flag ==EOC ){
		GET_BIT(ADC1->SR,1);
	}else if (flag ==JEOC ){
		GET_BIT(ADC1->SR,2);
	}else if (flag == JSTRT){
		GET_BIT(ADC1->SR,3);
	}else if (flag==STRT ){
		GET_BIT(ADC1->SR,4);
	}else {
		//wrong status flag select
	}
}


//clear flag status
void AD_clearStatusflag(u8 flag){
	if (flag == AWD){
			CLR_BIT(ADC1->SR,0);
		}else if (flag ==EOC ){
			CLR_BIT(ADC1->SR,1);
		}else if (flag ==JEOC ){
			CLR_BIT(ADC1->SR,2);
		}else if (flag == JSTRT){
			CLR_BIT(ADC1->SR,3);
		}else if (flag==STRT ){
			CLR_BIT(ADC1->SR,4);
		}else {

		}
}

void ADC_ScanConvMode(void){

	if(ADC1_ScanConvMode == ADC_ENABLE){
		SET_BIT(ADC1->CR1,8);
	}else if(ADC1_ScanConvMode == ADC_DISABLE){
		CLR_BIT(ADC1->CR1,8);
	}else{
		//error in config
	}
}

void ADC_singOrcontainusConvMode(void){

	if(ADC1_singOrcontainusConvMode == ADC_containusMode){
		SET_BIT(ADC1->CR2,1);
	}else if(ADC1_singOrcontainusConvMode == ADC_singleMode){
		CLR_BIT(ADC1->CR2,1);
	}else{
		//error in config
	}
}

void ADC_ExternalTrigConv(void){
	if(ADC1_ExternalTrigConv==timer1_cc1){
		ADC1->CR2 |= (0<<17);
	}else if(ADC1_ExternalTrigConv==timer1_cc2){
		ADC1->CR2 |= (1<<17);
	}else if(ADC1_ExternalTrigConv==timer1_cc3){
		ADC1->CR2 |= (2<<17);
	}else if(ADC1_ExternalTrigConv==timer2_cc2){
		ADC1->CR2 |= (3<<17);
	}else if(ADC1_ExternalTrigConv==timer3_trgo){
		ADC1->CR2 |= (4<<17);
	}else if(ADC1_ExternalTrigConv==timer4_cc4){
		ADC1->CR2 |= (5<<17);
	}else if(ADC1_ExternalTrigConv==Ext1_line11){
		ADC1->CR2 |= (6<<17);
	}else if(ADC1_ExternalTrigConv==SWSTART){
		ADC1->CR2 |= (7<<17);
	}else{
		//error selecting external trigger
	}

}
void ADC_DataAligment(void){
	if(ADC1_DataAlign == ADC_DATAALIGN_Right){
		CLR_BIT(ADC1->CR2,11);
	}else if (ADC1_DataAlign ==ADC_DATAALIGN_Left ){
		SET_BIT(ADC1->CR2,11);
	}else{
		//error inalligment config
	}

}
void ADC_NbrOfConversion(void){
	ADC1->SQR1 |= ((ADC1_NbrOfConversion-1)<<20);
}

void ADC_tempSenEnable(void){

	if(ADC1_tempSenEnable == ADC_ENABLE){
		SET_BIT(ADC1->CR2,23);
	}else if(ADC1_tempSenEnable == ADC_DISABLE){
		CLR_BIT(ADC1->CR2,23);
	}else{
		//error in temp config
	}
}


void ADC_DMAenable (void){
	if(ADC1_DMAenable == ADC_ENABLE){
			SET_BIT(ADC1->CR2,8);
		}else if(ADC1_DMAenable == ADC_DISABLE){
			CLR_BIT(ADC1->CR2,8);
		}else{
			//error in DMA config
		}
}

void ADC_watchdoginterupt(void);
void ADC_EOCinterupt(void);
void ADC_Resolution(void);
void ADC_ReferenceVoltage(void);
void ADC_ScanConvOrder(void);
void ADC_DiscontinuousConvMode(void);

void ADC_ExternalTrigConvEdge(void);
void ADC_NbrOfConversion(void);
void ADC_tempSenEnable(void);
void ADC_DMAenable (void);*/

































//	NOTE : dont forget init the pins input analog



/*
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

	// SW trigger
		ADC1->CR2|=(0b111<<17);

	//enable external trigger : sw trigger
		ADC1 -> CR2 |= 1 << 20;
	//Discontinuous mode on regular channels
	SET_BIT(ADC1->CR1,11);

	// Interrupt enable for EOC
	SET_BIT(ADC1->CR1,5);
	//single conv
	CLR_BIT(ADC1->CR2,1);

	ADC1->SMPR1|=(0<<3); 	// sampling time channel 1 (1.5) cycles

	// SW trigger
	//ADC1->CR2|=(0b111<<17);




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
	//SET_BIT(ADC1->SR,1);
	return data;
}

*/


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
	CLR_BIT(ADC1->SMPR2,0);
	CLR_BIT(ADC1->SMPR2,1);
	CLR_BIT(ADC1->SMPR2,2);
	// max sampling rate
	SET_BIT(ADC1->SMPR2,3);
	SET_BIT(ADC1->SMPR2,4);
	SET_BIT(ADC1->SMPR2,5);

	//direct memory access disable
	CLR_BIT(ADC1->CR2,8);

	//read right Alignment
	CLR_BIT(ADC1->CR2,11);

	//Set External event select for regular group -> SWSTART -> 111
	SET_BIT(ADC1->CR2,17);
	SET_BIT(ADC1->CR2,18);
	SET_BIT(ADC1->CR2,19);


	SET_BIT(ADC1->CR2,20);
	//Enable ADC start conv
	SET_BIT(ADC1->CR2,0);

}

u16	ADC_Start_Single_Conversion(u8 channel)
{
ADC1->SR = 0;  // Clear Status register
	u16 local_EndConv;

	// select length = 0 : i.e 1 conversion
	ADC1->SQR1 |=(0<<20);

	// select channel any channel
	ADC1->SQR3 |=(channel<<0);

	//Enable ADC start conv


	SET_BIT(ADC1->CR2,22);
	//wait to get the read from conversion
	while((GET_BIT(ADC1->SR,1))==1);
	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC1->CR2 , 0);
	while((GET_BIT(ADC1->SR,1))==1);
	//read the data from regular channel
	local_EndConv=ADC1->DR;
	return local_EndConv;



}


/*
reading=ADC_Start_Conversion(pin0); // temp oin port A pin 0
analog= ((uint32)reading*5000)/(256); // equation for temp to work
Temp=analog/10;
*/


/*
void	ADC_Init()
{
	  // Turn off the ADC1
	  ADC1->CR2 &= ~(1<<0);
	//config sampling for channel 1
	ADC1->SMPR2 = 0x0038;
	// select channel 1 for seq
	ADC1->SQR3 = 0x0001;
	// enable ADC for first time
	ADC1->CR2=	0x0003;
	// enable ADC for sec time
	ADC1->CR2=	0x0003;
	SET_BIT(ADC1->CR2,20);
	SET_BIT(ADC1->CR2,22);
	// on calibration
		ADC1->CR2=0x0007;


}

u16	ADC_Start_Single_Conversion(u8 channel)
{
	u16 local_val;
	//ADC start conv on reg channel
	ADC1->CR2 |=0x40000000;
	// monitoring on EOC bit in status reg
	while(!(ADC1->SR &2));

	ADC1->CR2|=0x00400000;
	while(!(ADC1->SR &2));
	local_val=ADC1->DR;
	//_delay_ms(50);
	return local_val;
}*/

/*
void ADC_Init()
{
  // Enable the ADC1 clock
 // RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

  // Set the prescaler to divide the input clock by 8
  //RCC->CFGR |= RCC_CFGR_ADCPRE_DIV8;

  // Turn off the ADC1
  ADC1->CR2 &= ~(1<<0);

  // Start calibration
  ADC1->CR2 |= 0x0007;
  while (ADC1->CR2 & (1<<2));

  // Set the sampling time for channel 1 to 84 cycles
  ADC1->SMPR2 |= 0x0038;

  // Set the sequence to channel 1
  ADC1->SQR3 |= 0x0001;

  // Turn on the ADC1
  ADC1->CR2 |= (1<<0);
  ADC1->CR2 |= (1<<0); // Turn on ADC1 again (required by hardware)
}


u16 ADC_Start_Single_Conversion(u8 channel)
{
  // Set the sequence to the specified channel
  ADC1->SQR3 = channel;

  // Start the conversion
  ADC1->CR2 |=(1<<20);

  // Wait for the end of conversion
  while (!(ADC1->SR & 2));

  // Return the ADC value
  return ADC1->DR;
}*/








