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









//water level



int main ()
{
	// enable SYSCLK
	RCC_voidSysClkInt();
	//	enable portA CLk
	RCC_voidEnablePerClk(RCC_APB2, 2);
	//enable portB
	RCC_voidEnablePerClk(RCC_APB2, 3);

	// button like levels
	DIO_voidSetPinDirection(PORTB, PIN3, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTB, PIN4, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTB, PIN5, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_INPUT_PULL_UP_DOWN);

	//DIO_voidSetPinValue(PORTB, PIN3, GPIO_HIGH); // inv ****************************** vip


	//led
Led_init(PIN9, PORTA);
Led_init(PIN10, PORTA);
Led_init(PIN11, PORTA);
Led_init(PIN12, PORTA);

	 LCD_INIT_DIR();
	LCD_INIT();

	LCD_sendString("welecom to ");
	LCD_ChangePOS_XY(0, 1);
	LCD_sendString("water detect ");

	_delay_ms(2000);

	LCD_Send_Command(0x01); // clear screen
	while(1)
	{
		if ((DIO_u8GetPinValue(PORTB, PIN3)==1)&&(DIO_u8GetPinValue(PORTB, PIN4)==0)&&(DIO_u8GetPinValue(PORTB, PIN5)==0)&&(DIO_u8GetPinValue(PORTB, PIN6)==0))
		{
			//while(DIO_u8GetPinValue(PORTB, PIN3)==1)
			LCD_Send_Command(0x01); // clear screen
				Led_on(PIN9, PORTA);
				LCD_sendString("water detect 25%");
				//LCD_ChangePOS_XY(0, 1);
			//	LCD_sendString("                ");

		}

		else if ((DIO_u8GetPinValue(PORTB, PIN3)==1)&&(DIO_u8GetPinValue(PORTB, PIN4)==1)&&(DIO_u8GetPinValue(PORTB, PIN5)==0)&&(DIO_u8GetPinValue(PORTB, PIN6)==0))
				{
			LCD_Send_Command(0x01); // clear screen
			Led_on(PIN10, PORTA);
			LCD_sendString("water detect 50%");
			//LCD_ChangePOS_XY(0, 1);
			//LCD_sendString("                ");
		}

		else if ((DIO_u8GetPinValue(PORTB, PIN3)==1)&&(DIO_u8GetPinValue(PORTB, PIN4)==1)&&(DIO_u8GetPinValue(PORTB, PIN5)==1)&&(DIO_u8GetPinValue(PORTB, PIN6)==0))
				{
			LCD_Send_Command(0x01); // clear screen
			Led_on(PIN11, PORTA);
			LCD_sendString("water detect 75%");
			//LCD_ChangePOS_XY(0, 1);
			//LCD_sendString("                ");
		}

		else if ((DIO_u8GetPinValue(PORTB, PIN3)==1)&&(DIO_u8GetPinValue(PORTB, PIN4)==1)&&(DIO_u8GetPinValue(PORTB, PIN5)==1)&&(DIO_u8GetPinValue(PORTB, PIN6)==1))
				{
			LCD_Send_Command(0x01); // clear screen
			Led_on(PIN12, PORTA);
			LCD_sendString("water detect100%");
			//LCD_ChangePOS_XY(0, 1);
		//	LCD_sendString("                ");
		}

		else
				{
					LCD_Send_Command(0x01); // clear screen
					led_off(PIN9, PORTA);
					LCD_sendString("water empty");
				}
	}
	return 0;
}


