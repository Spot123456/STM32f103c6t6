#ifndef SPI_INTERFACE_H
#define	SPI_INTERFACE_H


/*set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(u8 Copy_Address);

void TWI_voidInitSlave(u8 Copy_address);

void TWI_SendStartCondition();

void TWI_SendRepeatedStart();

void TWI_SendSlaveAddressWithWrite(u8 copy_Slaveaddress);

void TWI_SendSlaveAddressWithRead(u8 copy_Slaveaddress);

void TWI_MasterWriteDataByte(u8 copy_DataByte);

void TWI_MasterReadDataByte(u8* copy_DataByte);

void TWI_SendStopCondition(void);






#endif 
