#include	"Std_Types.h"
#include	"Bit_Math.h"


#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"NVIC_interface.h"
#include 	"EXTI_interface.h"
#include 	"STK_interface.h"
#include	"DMA_interface.h"
#include	"ADC_interface.h"
#include	"UART.interface.h"
#include 	"SPI.interface.h"
#include	"Delay.h"
#include	"led.h"
#include 	"lcd.h"
#include 	"SevenSEG.h"
#include 	"Motor.h"
#include 	"Keypad.h"




int main ()
{
	RCC_voidSysClkInt();
	//enable RCC portA
	RCC_voidEnablePerClk(RCC_APB2, 2);
	//enable RCC portB
			RCC_voidEnablePerClk(RCC_APB2, 3);

	//enable UART RCC
	RCC_voidEnablePerClk(RCC_APB2, 14);
	// A9 init the TX output AFPP
	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_10MHZ_AFPP);
	//	A10 for RX input float
	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_FLOAT);
	UART_init();
	Led_init(PIN10,PORTB);
	u8 data;
		while(1)
		{
			UART_RXdata(&data);

			if (data==1)
			{
				led_blink(PIN10, PORTB);
			}

		}

}



