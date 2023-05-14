/*
 * SevenSEG.c
 *
 * Created: 2/24/2023 6:47:05 PM
 *  Author:  Ahmed Nour
 */ 

#include "SevenSEG.h"
#include "Delay.h"
void sev_segment_init()
{
	
	DIO_voidSetPinDirection(seven_SEG_Port,PIN1,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(seven_SEG_Port,PIN2,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(seven_SEG_Port,PIN3,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(seven_SEG_Port,PIN4,GPIO_OUTPUT_10MHZ_PP);
	
}

void seven_segment_enable(EN_Enable_segment EN)
{
	if(EN<=EN2)
	switch (EN)
	{
		case EN1 :DIO_voidSetPinDirection(Enable_seven_port,PIN10,GPIO_OUTPUT_10MHZ_PP); DIO_voidSetPinValue(Enable_seven_port,PIN10,GPIO_HIGH) ; break;
		case EN2 :DIO_voidSetPinDirection(Enable_seven_port,PIN11,GPIO_OUTPUT_10MHZ_PP); DIO_voidSetPinValue(Enable_seven_port,PIN11,GPIO_HIGH) ; break;
	}
}

void seven_segment_Disable(EN_Enable_segment EN)
{
	if(EN<=EN2)
	switch (EN)
	{
		case EN1 :DIO_voidSetPinValue(Enable_seven_port,PIN10,GPIO_LOW) ; break;
		case EN2 : DIO_voidSetPinValue(Enable_seven_port,PIN11,GPIO_LOW) ; break;
	}
}

void seven_segment_write_NO(u8 No)
{
	//No =3  ----> 0b0000 0011
	//					  dcba
	if(No<10)
	{
		DIO_voidSetPinValue(seven_SEG_Port,PIN1,GET_BIT(No,0));  //a
		DIO_voidSetPinValue(seven_SEG_Port,PIN2,GET_BIT(No,1));  //b
		DIO_voidSetPinValue(seven_SEG_Port,PIN3,GET_BIT(No,2));  //c
		DIO_voidSetPinValue(seven_SEG_Port,PIN4,GET_BIT(No,3));  //d
	}
}

void two_sev_seg(u8 No)
{
	//please don't forget the INIT fun. 
	//NO = 48 ----> 4  8 use remender and divider
	
	u8 right=No%10;
	u8 left=No/10;
	//seven_segment_Disable(EN1);
	//seven_segment_Disable(EN2);
	seven_segment_write_NO(right);
	seven_segment_enable(EN1);
	_delay_ms(100);
	seven_segment_Disable(EN1);
	seven_segment_write_NO(left);
	seven_segment_enable(EN2);
	_delay_ms(100);
	seven_segment_Disable(EN2);
}
