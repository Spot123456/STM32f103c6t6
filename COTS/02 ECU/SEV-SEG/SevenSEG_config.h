/*
 * SevenSEG_config.h
 *
 * Created: 2/24/2023 6:47:37 PM
 *  Author:  Ahmed Nour
 */ 


#ifndef SEVENSEG_CONFIG_H_
#define SEVENSEG_CONFIG_H_
#include "DIO_interface.h"


#define seven_SEG_Port   PORTA //
#define Enable_seven_port  PORTB  //10 11

typedef enum
{
	EN1,
	EN2
	}EN_Enable_segment;
	


#endif /* SEVENSEG_CONFIG_H_ */
