#include "Std_Types.h"
#include "Bit_Math.h"


#include "I2Cinterface.h"
#include "I2Cconfig.h"
#include "I2Cprivate.h"


void TWI_voidInitMaster(u8 Copy_Address)
{
	SET_BIT(I2C1->CR1,15);
	CLR_BIT(I2C1->CR1,15);
	// The FREQ bits must be configured with the APB clock frequency value:  2 MHz --> this is min and the max 50 MHz
//	I2C1->CR2=0b000010;
	//	For instance: in Sm mode, to generate a 100 kHz SCL frequency:
	//	If FREQR = 08, TPCLK1 = 125 ns so CCR must be programmed with 0x28
	I2C1->CR2 |= 8;
	I2C1->CCR |= 0x28;

	//	FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
	//	therefore the TRISE[5:0] bits must be programmed with 09h.

	I2C1->TRISE |= 9;
	//	enable master mode

	//	enable the prepheral I2C
	SET_BIT(I2C1->CR1,0);
}

void TWI_voidInitSlave(u8 Copy_address)
{
	//	enable slave mode
	//	CLR_BIT(I2C1->CR2,0);

	//	ADDMODE Addressing mode (slave mode) 7 bit address not acknowledged
	CLR_BIT(I2C1->OAR1,15);

	//	slave address 7 bit
	I2C1->OAR1|=( Copy_address<<1);

	//	enable the prepheral I2C
		SET_BIT(I2C1->CR1,0);
}

void TWI_SendStartCondition()
{
	// in master mode
	I2C1->CR1|=(1<<8);
	// ack on
	I2C1->CR1|=(1<<10);
	//	while Start condition not generated
	while (GET_BIT(I2C1->SR1,0)==0);
}

void TWI_SendRepeatedStart()
{
	// in master mode
	I2C1->CR1|=(1<<8);
	// ack on
	I2C1->CR1|=(1<<10);
}

void TWI_SendSlaveAddressWithWrite(u8 copy_Slaveaddress)
{
	I2C1->DR =  copy_Slaveaddress;
	// wait the ADDR to be 1
	while ((GET_BIT(I2C1->SR1,1)) ==0);

	u32 temp = I2C1->SR1 | I2C1->SR2; // read the sr1 sr2 to clear the addr bit
}

void TWI_SendSlaveAddressWithRead(u8 copy_Slaveaddress)
{
	I2C1->DR =  copy_Slaveaddress;
		// wait the ADDR to be 1
	while ((GET_BIT(I2C1->SR1,1)) ==0);

	u32 temp = I2C1->SR1 | I2C1->SR2; // read the sr1 sr2 to clear the addr bit
}

void TWI_MasterWriteDataByte(u8 copy_DataByte)
{
	// check the Data register empty (transmitters)
	while(GET_BIT(I2C1->SR1,7)==0);
	// transmission is started (TxE=1)
	I2C1->DR= copy_DataByte;
	// wait until the data send
	while(GET_BIT(I2C1->SR1,2)==0);
}

void TWI_MasterReadDataByte(u8* copy_DataByte)
{
	// check the Data register empty (RX) : i.e wait until receive data
	while(GET_BIT(I2C1->SR1,6)==0);
	// clock STRETCH:
	//recevied data from the same reg

	*copy_DataByte=I2C1->DR;

}

void TWI_SendStopCondition(void)
{
	//by master
	// Stop generation after the current byte transfer or after the current Start condition is sent.
	I2C1->CR1|=(1<<9);
}



