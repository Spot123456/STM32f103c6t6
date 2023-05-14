
/*
 * led.c
 *
 * Created: 1/25/2023 9:47:02 PM
 *  Author: yahia
 */ 

#include "led.h"


void Led_init(u8 pin_id , u8 port_id)
{
	DIO_voidSetPinDirection(port_id, pin_id,GPIO_OUTPUT_10MHZ_PP );
}

void Led_on(u8 pin_id , u8 port_id)
{
	DIO_voidSetPinValue(port_id,pin_id,GPIO_HIGH);
}

void led_off(u8 pin_id , u8 port_id)
{
	DIO_voidSetPinValue(port_id,pin_id,GPIO_LOW);
}

void led_blink(u8 pin_id , u8 port_id) // delay for 500 ms
{
	Led_on(pin_id,port_id);
	_delay_ms(500);
	led_off(pin_id,port_id);
	_delay_ms(500);
	
}
