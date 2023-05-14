/*
 * lcd.h
 *
 * Created: 2/22/2023 2:24:38 AM
 *  Author: yahia
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "Std_Types.h"
#include "Bit_Math.h"
#include "LCD_CONFIG.h"
#include "DIO_interface.h"


void LCD_INIT_DIR();

void LCD_Send_Command(u8 command);

void LCD_Send_Data(u8 Data);

void LCD_INIT();

void LCD_sendString(const char* string);

void LCD_ChangePOS_XY(u8 POSX,u8 POSY);

void LCD_sendSpecial_char(u8* pattern_Data_Array,u8 pattern_no,u8 XPOS,u8 YPOS);  //when we use array we must assign by (*)



#endif /* LCD_H_ */
