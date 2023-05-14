/*
 * Keypad_Config.h
 *
 *  Created on: May 5, 2023
 *      Author: yahia
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#define rows	4
#define cols	4

#define	Keypad_Port		PORTB
//row config
#define	R0		PIN0
#define	R1		PIN1
#define	R2		PIN2
#define	R3		PIN3

//Col config

#define	C0		PIN4
#define	C1		PIN5
#define	C2		PIN6
#define	C3		PIN7






#endif /* KEYPAD_CONFIG_H_ */
