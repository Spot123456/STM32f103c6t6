/*
 * Button.c
 *
 * Created: 1/25/2023 9:28:34 PM
 *  Author: yahia
 */ 

#include "Button.h"

void Button_init(u8 pin_id, u8 port_id)
{
	DIO_voidSetPinDirection(port_id,pin_id,GPIO_INPUT_PULL_UP_DOWN);
}
u8 Button_read(u8 pin_id, u8 port_id )
{
	u8 val;
	val =DIO_u8GetPinValue(port_id, pin_id);
	return val ; 
}
