/*
 * Keypad.c
 *
 *  Created on: May 5, 2023
 *      Author: yahia
 */


#include "Keypad.h"

u8 row[rows]={R0,R1,R2,R3};
u8 col[cols]={C0,C1,C2,C3};

// keypad 4x4 config

u8 keypad_no[rows][cols]= {
							{1,2,3,4},
							{5,6,7,8},
						 {9,10,11,12},
						 {13,14,15,16}
										};

void keypad_init()
{
	// row output
	DIO_voidSetPinDirection(Keypad_Port,R0,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(Keypad_Port,R1,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(Keypad_Port,R2,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(Keypad_Port,R3,GPIO_OUTPUT_10MHZ_PP);
	// col input
	DIO_voidSetPinDirection(Keypad_Port,C0,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(Keypad_Port,C1,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(Keypad_Port,C2,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(Keypad_Port,C3,GPIO_INPUT_PULL_UP_DOWN);
	// col high (to activate pull up res
	DIO_voidSetPinValue(Keypad_Port,C0, GPIO_HIGH);
	DIO_voidSetPinValue(Keypad_Port,C1, GPIO_HIGH);
	DIO_voidSetPinValue(Keypad_Port,C2, GPIO_HIGH);
	DIO_voidSetPinValue(Keypad_Port,C3, GPIO_HIGH);

}

u8 keypad_scan()
{
	u8 i , j,column ;
	for(i=0;i<rows;i++)
	{
		//activate rows
		DIO_voidSetPinValue(Keypad_Port,i, GPIO_LOW);
		for(j=0;j<cols;j++)
		{
			column=DIO_u8GetPinValue(Keypad_Port, j<<4);
			if(column==0)
			{
				while(column==0);
				return keypad_no[i][j];
			}

		}
		//deactivate Rows
		DIO_voidSetPinValue(Keypad_Port,i,GPIO_HIGH);
	}

	return 0;
}


