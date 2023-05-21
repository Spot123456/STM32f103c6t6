/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/


#include "Std_Types.h"
#include "Bit_Math.h"

#include "UART.interface.h"
#include "UART.config.h"
#include "UART.private.h"

void UART_init()
{
	// for 8 MHz sys freq and 9600 boudrate
	//boud rate from the eq write to reg
	// 52 for mantissa 0.083 div --> 0.083*16=1.328 =1

	UART1->BRR|=(1<<0)|(52<<4);

	//usart enable & 8 bit word
	SET_BIT(UART1->CR1,13);
	// enable the interrupt TX&Rx
	SET_BIT(UART1->CR1,7);
	SET_BIT(UART1->CR1,5);

	// enable the TX&Rx
	SET_BIT(UART1->CR1,3);
	SET_BIT(UART1->CR1,2);
	// one stop bit 0

}
  
//enable transmitter
void UART_enableTX(void)
{
	SET_BIT(UART1->CR1,3);
	
}
//enable receiver
void UART_enableRX(void)
{
	SET_BIT(UART1->CR1,2);
}
//transmit data
void UART_TXdata(u8 data)
{
	//wait Transmit data register empty
	while(GET_BIT(UART1->SR,7)==0);
	UART1->DR=data;
	//wait Transmit data complete
	while(GET_BIT(UART1->SR,6)==0);
}
//receive data
void UART_RXdata (u8 *data )
{
	//wait RX data register received data
	while(GET_BIT(UART1->SR,5)==0);
	*data=UART1->DR;
	
}

void UART1_voidSendString(u8 * const str)
{
	
}
u8 * const UART1_StrReceiveString()
{
	return 0;
}
