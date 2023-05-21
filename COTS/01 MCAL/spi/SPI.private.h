
#ifndef UART_PRIVATE_h
#define	UART_PRIVATE_h





typedef struct
{
	u32		CR1;
	u32		CR2;
	u32		SR;
	u32		DR;
	u32		CRCPR;
	u32		RXCRCR;
	u32		TXCRCR;

	//we didn't use this reg
	u32		I2SSCFGR;
	u32		I2SPR;

}SPI_Type;

#define			SPI1     ((SPI_Type*)(0x40013000))





#endif // !SPI_PRIVATE_h