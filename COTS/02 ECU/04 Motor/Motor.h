/*
 * Motor.h
 *
 * Created: 3/14/2023 7:33:39 PM
 *  Author:  Ahmed Nour
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "Motor_config.h"
void motor_Init();
void motor_forward();
void motor_backward();
void motor_stop();
void motor_MoveRight();
void motor_MoveLeft();



#endif /* MOTOR_H_ */
