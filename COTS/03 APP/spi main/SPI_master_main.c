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



//spi master

int main ()
{
	RCC_voidSysClkInt();
	//enable RCC portA
	RCC_voidEnablePerClk(RCC_APB2, 2);
	//enable RCC portB
	//RCC_voidEnablePerClk(RCC_APB2, 3);

	//enable SPI RCC
	RCC_voidEnablePerClk(RCC_APB2, 12);

	SPI_Master_init();
	// init mosi output
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_10MHZ_AFPP);
	// init miso input
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT);
	//inti clk for master output
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_10MHZ_AFPP);
	// ss select out
	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_10MHZ_PP);
	//Led_init(PIN10,PORTB);

	u8 data;
		while(1)
		{
			DIO_voidSetPinValue(PORTA, PIN9, GPIO_LOW);	//SET SS PIN TO LOW
			data=SPI_transceiver(1);
			DIO_voidSetPinValue(PORTA, PIN9, GPIO_HIGH); //SET SS PIN TO HIGH
		}
}



