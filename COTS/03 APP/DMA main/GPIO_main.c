#include	"Std_Types.h"
#include	"Bit_Math.h"


#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"NVIC_interface.h"
#include 	"EXTI_interface.h"
#include 	"STK_interface.h"
#include	"DMA_interface.h"
#include	"ADC_interface.h"
#include 	"ADC_private.h"
#include	"UART.interface.h"
#include	"SPI.interface.h"
#include	"Delay.h"
#include	"led.h"
#include 	"lcd.h"
#include 	"SevenSEG.h"
#include 	"Motor.h"
#include 	"Keypad.h"




u32	Processor_Arr1[100];
u32	Processor_Arr2[100];

u32	DMA_Arr3[100];
u32	DMA_Arr4[100];

void	Tog	(void)
{

}
int main()
{
	DMA1_voidSetCallBack(Tog);
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr1[i]	=	i;
		DMA_Arr3[i]			=	i;
	}

	//	System init
	RCC_voidSysClkInt();
	//DMA1_voidChannelInit();
	DMA1_voidChannelInit( 0 ,Arr_TO_Arr);
	RCC_voidEnablePerClk(RCC_AHB, 0); // DMA
	//DMA1 Channel Transfere Round
	DMA1_voidStartChannel(DMA_Arr3,DMA_Arr4,500);

	//	Processor Transfere Round
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr2[i]	=	Processor_Arr1[i];
	}



while(1)
{

}

return 0;
}




