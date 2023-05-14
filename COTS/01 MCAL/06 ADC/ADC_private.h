
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H



typedef		struct
{
	u32				SR;
	u32				CR1;
	u32				CR2;    //reserved
	u32				SMPR1;	//ADC sample time register 1
	u32				SMPR2;	//ADC sample time register 2
	u32				JOFR;		//ADC injected channel data offset register
	u32				HTR;
	u32				LTR;
	u32				SQR1; // lenght only other reserved
	u32				SQR2;
	u32				SQR3;
	u32				JSQR; //ADC injected sequence only for channel
	u32				JDRx;	// conversion result from injected channel x
	u32				DR;	// regular data
}ADC1_Type;

#define		ADC1	((volatile ADC1_Type*)(0x40012400))


































/*
typedef		struct
{
	u32			SMPR1;	//ADC sample time register 1
	u32			SMPR2;	//ADC sample time register 2
	u32			JOFR;		//ADC injected channel data offset register
	u32			HTR;
	u32			LTR;
	u32			SQR1; // lenght only other reserved
	u32			SQR2;
	u32			SQR3;
	u32			JSQR; //ADC injected sequence only for channel
	u32			JDRx;	// conversion result from injected channel x
	u32			DR;	// regular data 
}ADC_Channel;

typedef		struct
{
	u32				SR;
	u32				CR1;
	u32				CR2;    //reserved
	ADC_Channel		Channel[10]	;
}ADC1_Type;

#define		ADC1	((volatile ADC1_Type*)(0x40012400))
*/

#endif


