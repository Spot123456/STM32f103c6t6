/*
 * Motor.c
 *
 * Created: 3/14/2023 7:33:22 PM
 *  Author:  Ahmed Nour
 */ 


#include "Motor.h"
void motor_Init()
{
	DIO_voidSetPinDirection(Motor_Port,In1,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(Motor_Port,In2,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(Motor_Port,In3,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(Motor_Port,In4,GPIO_OUTPUT_10MHZ_PP);

}
void motor_forward()
{
	DIO_voidSetPinValue(Motor_Port,In1,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In2,GPIO_HIGH);
	DIO_voidSetPinValue(Motor_Port,In3,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In4,GPIO_HIGH);
	
}

void motor_backward()
{
	DIO_voidSetPinValue(Motor_Port,In1,GPIO_HIGH);
	DIO_voidSetPinValue(Motor_Port,In2,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In3,GPIO_HIGH);
	DIO_voidSetPinValue(Motor_Port,In4,GPIO_LOW);
}


void motor_stop()
{
	DIO_voidSetPinValue(In1,Motor_Port,GPIO_LOW);
	DIO_voidSetPinValue(In2,Motor_Port,GPIO_LOW);
	DIO_voidSetPinValue(In3,Motor_Port,GPIO_LOW);
	DIO_voidSetPinValue(In4,Motor_Port,GPIO_LOW);
}

void motor_MoveRight()
{
	/* to move right we need to move the left wheel to turn right */
	DIO_voidSetPinValue(Motor_Port,In1,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In2,GPIO_HIGH);
	DIO_voidSetPinValue(Motor_Port,In3,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In4,GPIO_LOW);
}



void motor_MoveLeft()
{
	/*we need to move left so move the wheel right */
	DIO_voidSetPinValue(Motor_Port,In1,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In2,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In3,GPIO_LOW);
	DIO_voidSetPinValue(Motor_Port,In4,GPIO_HIGH);
}
