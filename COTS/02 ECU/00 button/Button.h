/*
 * Button.h
 *
 * Created: 1/25/2023 9:28:51 PM
 *  Author: yahia
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"

void Button_Init(u8 pin_id, u8 port_id);
u8 Button_read(u8 pin_id, u8 port_id );


#endif /* BUTTON_H_ */
