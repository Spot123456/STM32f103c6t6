
#include "Std_Types.h"
#include "Bit_Math.h"

#include "SPI.interface.h"
#include "SPI.config.h"
#include "SPI.private.h"


void SPI_Master_init()
{
	//16 bit data frame format
//	SPI1->CR1|=(1<<11);
	//SW Slave managment
	SPI1->CR1|=(1<<9);
	SET_BIT(SPI1->CR1,8);

	//data 8bit data select (bit no in cr1-> 11)


	// baud rate Fpclk/16
	SPI1->CR1|=(3<<3);
	// master selection
	SPI1->CR1|=(1<<2);
	//clock polarty &clock phase
	SPI1->CR1|=(1<<1)|(1<<0);
	//NSS=1
	//enable spi
	SPI1->CR1|=(1<<6);

}

void SPI_Slave_init()
{
	//16 bit data frame format
//	SPI1->CR1|=(1<<11);
	//SW Slave managment
	//SPI1->CR1|=(1<<9);

	//data 8bit data select (bit no in cr1-> 11)


	// baud rate Fpclk/16
	SPI1->CR1|=(3<<3);
	// slave selection
	SPI1->CR1&=~(1<<2);
	//clock polarty &clock phase
	SPI1->CR1|=(1<<1)|(1<<0);
	//NSS=1
	//enable spi
	SPI1->CR1|=(1<<6);

}

u8 SPI_transceiver(u8 data)
{
	// if buffer TX is busy or not
			while ((GET_BIT(SPI1->SR,1))==0);
		SPI1->DR=data ;
		//Then wait until RXNE=1
		while ((GET_BIT(SPI1->SR,0))==0);
		// if buffer spi is busy or not
		while ((GET_BIT(SPI1->SR,7))==1);

		return SPI1->DR;


}
