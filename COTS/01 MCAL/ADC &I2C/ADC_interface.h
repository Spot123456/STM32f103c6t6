


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define single_conv		0
#define Scan_conv		1
/*
void	ADC_Init();
u16	ADC_Start_Single_Conversion(u8 channel);

*/

/*
#ifndef		ADC_interface
#define		ADC_interface

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"ADC_private.h"
#include  "ADC_config.h"






//Adc_flags
enum{
	AWD,	// Analog watchdog flag
	EOC,	// End of conversion
	JEOC,   // Injected channel end of conversion
	JSTRT,  //Injected channel Start flag
	STRT  //Regular channel Start flag
};

void ADC_getStatusflag(u8 flag);
void ADC_clearStatusflag(u8 flag);

void	ADC_voidInit(void);
void	ADC_voidEnable(void);
void ADC_Start(void);

void ADC_channelSetup(u8 channel , u8 SEQuance,u8 SamplingTime);
void ADC_ScanConvMode(void);
void ADC_singOrcontainusConvMode(void);
void ADC_ExternalTrigConv(void);
void ADC_DataAligment(void);
void ADC_NbrOfConversion(void);
void ADC_tempSenEnable(void);
void ADC_DMAenable (void);
*/
/*
void ADC_watchdoginterupt(void);
void ADC_EOCinterupt(void);
void ADC_Resolution(void);
void ADC_ReferenceVoltage(void);
void ADC_ScanConvOrder(void);
void ADC_DiscontinuousConvMode(void);
void ADC_ExternalTrigConvEdge(void);

*/


//#endif

	/*******************    Public Macros    ********************/

typedef enum
{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7,
	CHANNEL_8,
	CHANNEL_9
}Channel_ID;

	/******************* Functions Prototypes ********************/
void	_delay_ms(u32 _ms);

//void	ADC_void_init	(void);
//u16		ADC_u16_read	(Channel_ID Copy_enuChannel);

void	ADC_Init();
u16	ADC_Start_Single_Conversion(u8 channel);


#endif
