
#ifndef UART_PRIVATE_h
#define	UART_PRIVATE_h





typedef struct
{
	u32		SR;
	u32		DR;
	u32		BRR;
	u32		CR1;
	u32		CR2;
	u32		CR3;
	u32		GPTR;

}UART_type;

#define			UART1     ((UART_type*)(0x40013800))





#endif // !UART_PRIVATE_h
