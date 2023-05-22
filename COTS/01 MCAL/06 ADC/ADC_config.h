#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H








#define mode  single_conv


/*


#ifndef		ADC_config
#define		ADC_config


//mode config
enum {
	ADC_ENABLE,
	ADC_DISABLE
};


//data alligment config
enum{
	ADC_DATAALIGN_Right,
	ADC_DATAALIGN_Left
};


//ADC_channels
enum{
	ADC_channe0,
	ADC_channe1,
	ADC_channe2,
	ADC_channe3,
	ADC_channe4,
	ADC_channe5,
	ADC_channe6,
	ADC_channe7,
	ADC_channe8,
	ADC_channe9,
	ADC_channe10,
	ADC_channe11,
	ADC_channe12,
	ADC_channe13,
	ADC_channe14,
	ADC_channe15,
	ADC_channe16,
	ADC_channe17,
};

//Adc channel sampling time
enum{
	cycles_1_5,
	cycles_7_5,
	cycles_13_5,
	cycles_28_5,
	cycles_41_5,
	cycles_55_5,
	cycles_71_5,
	cycles_239_5

};

//single or containus mode
enum{
	ADC_singleMode,
	ADC_containusMode
};

//external trigers starting
enum{
	timer1_cc1,
	timer1_cc2,
	timer1_cc3,
	timer2_cc2,
	timer3_trgo,
	timer4_cc4,
	Ext1_line11,
	SWSTART
};
//sequance values
enum{
	SEQ1,
	SEQ2,
	SEQ3,
	SEQ4,
	SEQ5,
	SEQ6,
	SEQ7,
	SEQ8,
	SEQ9,
	SEQ10,
	SEQ11,
	SEQ12,
	SEQ13,
	SEQ14,
	SEQ15,
	SEQ16,

};

#define ADC1_ScanConvMode	ADC_DISABLE //enable or disable// Enable scan mode conversions on multiple channels, respectively. need to clear the flag (EOC) after each conversion per each channel
#define ADC1_singOrcontainusConvMode 	ADC_singleMode//enable single conv mode perform one-time conversions or containus to perform a sequance
#define ADC1_ExternalTrigConv  SWSTART  // how you wont the conversion to start
#define ADC1_DataAlign  ADC_DATAALIGN_Right //ADC_DATAALIGN_Right,ADC_DATAALIGN_Left
#define ADC1_NbrOfConversion  1// num from 1 to 16
#define ADC1_tempSenEnable  ADC_DISABLE   //enable or disable
#define ADC1_DMAenable  ADC_DISABLE//enable or disable
*/
/*
//####not done yet#######################
#define ADC1_watchdoginterupt   ADC_DISABLE // enable or disable
#define ADC1_EOCinterupt 	ADC_DISABLE//enable or disable
#define ADC1_JEOcie_interupt	ADC_DISABLE //enable or disable
#define ADC1_Resolution
#define ADC1_ReferenceVoltage //
#define ADC1_ScanConvOrder
#define ADC1_DiscontinuousConvMode
#define ADC1_ExternalTrigConvEdge
*/


/*
//######tempreture sensor configrature#############################
#define ADC1_ScanConvMode	ADC_DISABLE //enable or disable// Enable scan mode conversions on multiple channels, respectively. need to clear the flag (EOC) after each conversion per each channel
#define ADC1_singOrcontainusConvMode 	ADC_containusMode//enable single conv mode perform one-time conversions or containus to perform a sequance
#define ADC1_ExternalTrigConv  SWSTART  // how you wont the conversion to start
#define ADC1_DataAlign  ADC_DATAALIGN_Right //ADC_DATAALIGN_Right,ADC_DATAALIGN_Left
#define ADC1_NbrOfConversion  1// num from 1 to 16
#define ADC1_tempSenEnable  ADC_ENABLE    //enable or disable
#define ADC1_DMAenable  ADC_DISABLE//enable or disable
*/

/*
//#####channels config############################
Channel = ADC_channe16
sequance = SEQ1;
SamplingTime = cycles_239_5;

*/


//#endif


#endif
