/*
 * led.h
 *
 * Created: 1/25/2023 9:47:13 PM
 *  Author: yahia
 */ 


#ifndef LED_H_
#define LED_H_
#include "DIO_interface.h"
#include "Delay.h"


void Led_init(u8 pin_id , u8 port_id);
void Led_on(u8 pin_id , u8 port_id);
void led_blink(u8 pin_id , u8 port_id);
void led_off(u8 pin_id , u8 port_id);


#endif /* LED_H_ */
