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





void	ToggleLed(void)
{
	static	u8 flag	=	0;
	if(flag	==	0)
	{
		//	Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		flag	=	1;
	}
	else
	{
		//		Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		flag	=	0;
	}
}

int main ()
{
	// enable system clk
	RCC_voidSysClkInt();
	//enable Rcc portc
	RCC_voidEnablePerClk(RCC_APB2, 4);
	// output led on c13
	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);

	STK_voidInit();

	STK_voidSetIntervalPeriodic(1000000, ToggleLed);

	//_delay_ms(2000);

	//STK_voidSetIntervalPeriodic(1000000, ToggleLed);

	while(1)
	{
		//DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		STK_voidSetBusyWait(1000000);
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		STK_voidSetBusyWait(1000000);
	}
}






































/

