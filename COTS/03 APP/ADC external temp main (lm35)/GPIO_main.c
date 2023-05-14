#include	"Std_Types.h"
#include	"Bit_Math.h"


#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"NVIC_interface.h"
#include 	"EXTI_interface.h"
#include 	"STK_interface.h"
#include	"DMA_interface.h"
#include	"ADC_interface.h"
#include	"Delay.h"
#include	"led.h"
#include 	"lcd.h"
#include 	"SevenSEG.h"
#include 	"Motor.h"
#include 	"Keypad.h"


/*
int main()
{

	RCC_voidSysClkInt();

	// portA enable
	RCC_voidEnablePerClk(RCC_APB2, 2);

	// portB enable
	RCC_voidEnablePerClk(RCC_APB2, 3);

	//lcd direction
	LCD_INIT_DIR();

	//lcd init
	LCD_INIT();

	while(1)
	{

	}
	return 0 ;
}*/











































//water level


/*
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
}*/


///ADC


int main ()
{
	u8 temp ,reading;
	u16 analog;
	// system	CLK
	RCC_voidSysClkInt();

	//enable adc RCC
	RCC_voidEnablePerClk(RCC_APB2, 9);

	//enable portC RCC
	RCC_voidEnablePerClk(RCC_APB2, 4);

	//enable porta RCC
	RCC_voidEnablePerClk(RCC_APB2, 2);

	//set the A0 analog input
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_INPUT_ANALOG);

	//set the pin dio output push pull
	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_10MHZ_PP);

	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_OUTPUT_10MHZ_PP);
	RCC_voidEnableADC_Prescaler();
	ADC_Init();
	//temp=ADC_Start_Single_Conversion(0);

	while(1)
	{
		//temp=ADC_Start_Single_Conversion(0);
		reading=ADC_Start_Single_Conversion(0);
		analog= (((u32)reading*5000)/(256)); // equation for temp to work
		temp=analog/10;

		while (temp > 20)
		{

			//DIO_voidSetPinValue(PORTC, PIN13, GPIO_LOW);
			led_blink(PIN13,PORTC);
			led_blink(PIN10,PORTA);

		}
	}
	return 0 ;
}




































/*
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
}*/

/*
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
}*/





































// led on by interrupt
	//C13 ==> Built in led (Toggle Led)
/*int main()
{
	//	System Clock Init
	RCC_voidSysClkInt();
	//	Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);
	
	//	C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	
	while(1)
	{
		//		Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW); //portc
		_delay_ms(500);
		//		Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		_delay_ms(500);
	}
	return 0;


	//	system clk INIT

	RCC_voidSysClkInt();
	// Enable RCC for GPIO C
	RCC_voidEnablePerClk(RCC_APB2, 4);
	// Enable RCC for GPIO B
//	RCC_voidEnablePerClk(RCC_APB2, 3);
	// Enable RCC for GPIO A
	RCC_voidEnablePerClk(RCC_APB2, 2);

	RCC_voidEnablePerClk(RCC_APB2, 0); // ext INT


	// C 13 --> OUTput 10MHz PUSH PUll
	Led_init(13, PORTC);

	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_PULL_UP_DOWN);// button
	DIO_voidSetPinValue(PORTA, PIN0,GPIO_LOW); // low
	//NVIC_voidInit();
	EXTI0_voidInit();
	EXTI_voidEnableInt(0);
	EXTI_voidChangeSenseMode(0, RISING_EDGE);



	NVIC_voidEnablePerInt(6);


	//sev_segment_init();
	//seven_segment_enable(EN1);
	//seven_segment_enable(EN2);

	while(1)
	{



	}

return 0;
}



void	EXTI0_IRQHandler(void)
{

		Clear the Flag
	SET_BIT(EXTI->PR,0);


	led_blink( PIN13, PORTC);



}*/


