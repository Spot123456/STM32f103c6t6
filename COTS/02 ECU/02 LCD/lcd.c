/*
 * lcd.c
 *
 * Created: 2/22/2023 2:24:03 AM
 *  Author: yahia
 */ 
#include "Delay.h"
#include "lcd.h"

void LCD_Send_Command(u8 command)
{
	
	/*1- Set RS to LOW : for command */
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_LOW);
	
	/*2- Set RW to LOW : for Write */
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_LOW);
	
	/*3- Send command */
	//DIO_Set_PortVal(LCD_DATA_PORT,command);
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN0, GET_BIT(command,0));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN1, GET_BIT(command,1));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN2, GET_BIT(command,2));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN3, GET_BIT(command,3));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN4, GET_BIT(command,4));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN5, GET_BIT(command,5));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN6, GET_BIT(command,6));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN7, GET_BIT(command,7));
	
	/*4- send the enable pulse :enable pin high */
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,GPIO_HIGH);
	_delay_ms(2);//Timer_delay(2); // delay 2 ms
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,GPIO_LOW);
	
}
void LCD_Send_Data(u8 Data)
{
	/*1- Set RS to high */ 
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_HIGH);
	
	/*2- set RW to LOW : Write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_LOW);
	
	/*3- send data*/
	//DIO_Set_PortVal(LCD_DATA_PORT,Data);
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN0, GET_BIT(Data,0));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN1, GET_BIT(Data,1));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN2, GET_BIT(Data,2));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN3, GET_BIT(Data,3));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN4, GET_BIT(Data,4));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN5, GET_BIT(Data,5));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN6, GET_BIT(Data,6));
	DIO_voidSetPinValue(LCD_DATA_PORT, PIN7, GET_BIT(Data,7));





	
	/*4- Send enable Pulse */ 
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,GPIO_HIGH);
	_delay_ms(2);//Timer_delay(2); // 2 ms
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,GPIO_LOW);
}

void LCD_INIT()
{
	
	/*1- wait more than 30ms*/
	_delay_ms(40);//Timer_delay(40); //br7ty
	/*2- function set command : 2 line , font size */
	LCD_Send_Command(0b00111000);
	
	/*display on / of : display enable ,cursor off , blink cursor off */ 
	LCD_Send_Command(0b00001100);
	/*display clear */
	LCD_Send_Command(1);
	
	
	
}

void LCD_sendString(const char* string)
{
	u8 local_count=0;
	while(string[local_count]!='\0')
	{
		
		LCD_Send_Data(string[local_count]);
		local_count++;
	}
	
}

void LCD_ChangePOS_XY(u8 POSX,u8 POSY)
{
	u8 POS_DDRAM=0;
	if(POSY==0)
	{
		POS_DDRAM= POSY*0x40+POSX;  // Now we have Address of DDRAM (3wd yasta)
	}
	if(POSY==1)
	{
		POS_DDRAM=POSY*0x40+POSX;	 // Now we have Address of DDRAM 
	}
	/*we need to go to address first then go write data on it*/
	/*we add 128 bec we send data and the last bit (D7) =1 look in data sheet so we can add 128 OR set_bit 7 =1 */
	LCD_Send_Command(POS_DDRAM+128);
}

void LCD_sendSpecial_char(u8* pattern_Data_Array,u8 pattern_no,u8 XPOS,u8 YPOS)
{
	u8 CGRAM_Address,local_counter;
	/* 1- calculate CGRAM Address*/
	CGRAM_Address=pattern_no*8;
	/*2- send setCGRAM address command with 6 bit*/
	LCD_Send_Command(CGRAM_Address+64);
	/* 3- send(write) the pattern in CGRAM */ 
	for(local_counter=0;local_counter<8;local_counter++)
	{
		LCD_Send_Data(pattern_Data_Array[local_counter]);
	} 
	/*4- to display the figure position back to DDRAM  (ht3rdha feen yasta)*/
	LCD_ChangePOS_XY(XPOS,YPOS);
	/*5- to display data that store in CGRAM : send the pattern Number */
	LCD_Send_Data(pattern_no);
}



void LCD_INIT_DIR()
{
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN0, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN1, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN2, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN3, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN4, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN6, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_DATA_PORT, PIN7, GPIO_OUTPUT_2MHZ_PP);


	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_E_PIN , GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN, GPIO_OUTPUT_10MHZ_PP);
}


