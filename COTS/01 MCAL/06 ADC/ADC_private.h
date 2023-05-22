
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H



typedef		struct
{
	u32				SR;
	u32				CR1;
	u32				CR2;    //reserved
	u32				SMPR1;	//ADC sample time register 1
	u32				SMPR2;	//ADC sample time register 2
	u32				JOFR1;		//ADC injected channel data offset register
	u32				JOFR2;		//ADC injected channel data offset register
	u32				JOFR3;		//ADC injected channel data offset register
	u32				JOFR4;		//ADC injected channel data offset register
	u32				HTR;
	u32				LTR;
	u32				SQR1; // lenght only other reserved
	u32				SQR2;
	u32				SQR3;
	u32				JSQR; //ADC injected sequence only for channel
	u32				JDR1;	// conversion result from injected channel x
	u32				JDR2;	// conversion result from injected channel x
	u32				JDR3;	// conversion result from injected channel x
	u32				JDR4;	// conversion result from injected channel x
	u32				DR;	// regular data
}ADC1_Type;

#define		ADC1 ((volatile ADC1_Type*)(0x40012400))

/*

#define ADC_SINGLE_CONVERSION_MODE              1
#define ADC_CONTINUOUS_CONVERSION_MODE          2


#define ADC_RIGHT_ALIGNMENT                     1
#define ADC_LEFT_ALIGNMENT                      2


#define ENABLE                                  1
#define DISABLE                                 2


#define CYCLES1                                 0b000
#define CYCLES2                                 0b001
#define CYCLES3                                 0b010
#define CYCLES4                                 0b011
#define CYCLES5                                 0b100
#define CYCLES6                                 0b101
#define CYCLES7                                 0b110
#define CYCLES8                                 0b110


#define CHANNEL0                                0
#define CHANNEL1                                1
#define CHANNEL2                                2
#define CHANNEL3                                3
#define CHANNEL4                                4
#define CHANNEL5                                0
#define CHANNEL6                                1
#define CHANNEL7                                2
#define CHANNEL8                                3
#define CHANNEL9                                4




#define ADC_TIMER1CC1                           0b00000000000000000000000000000000
#define ADC_TIMER1CC2                           0b00000000000000100000000000000000
#define ADC_TIMER1CC3                           0b00000000000001000000000000000000
#define ADC_TIMER2CC2                           0b00000000000001100000000000000000
#define ADC_TIMER3TRGO                          0b00000000000010000000000000000000
#define ADC_TIMER4CC4                           0b00000000000010100000000000000000
#define ADC_EXTI11                              0b00000000000011000000000000000000
#define ADC_SWSTART                             0b00000000000011100000000000000000

*/





























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


