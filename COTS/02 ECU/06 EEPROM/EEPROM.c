/*
 * EEPROM.c
 *
 * Created: 4/26/2023 1:51:51 AM
 *  Author: yahia
 */ 
#include "Std_Types.h"
#include "Bit_Math.h"

#include "EEPROM.h"
#include "EEPROM_Private.h"
void EEPROM_Write(u16 location_Address,u8 Copy_Data)
{
	// data is 10 bit bec EEPROM 8 K
	// 1010 000 --> 1010 A2 B10 B9 
	u8 location_Address_Packet=EEPROM_FIXED_ADDRESS | (A2_Connection<<2) |(u8)(Copy_Data>>8);
	//send start condition
	TWI_SendStartCondition();
	//send the addressPacket
	TWI_SendSlaveAddressWithWrite(location_Address_Packet);
	// send the rest 8bit of the location address
	TWI_MasterWriteDataByte((u8)location_Address);
	// send the data 
	TWI_MasterWriteDataByte(Copy_Data);
	//stop the condition of TWI
	TWI_SendStopCondition();
	//delay for 10 ms to write in the memory 
	_delay_ms(10);
}


u8 EEPROM_Read(u16 location_Address)
{
	u8 data;
	u8 local_AddressPacket=EEPROM_FIXED_ADDRESS | (A2_Connection<<2) |(u8)(location_Address>>8);
	TWI_SendStartCondition();
	// 7 bit slave with write to can be able to send the rest 8 bit of location address
	TWI_SendSlaveAddressWithWrite(local_AddressPacket);
	// send the rest of 8 bits 
	TWI_MasterWriteDataByte((u8)local_AddressPacket);
	// read the send data 
	TWI_MasterReadDataByte(&data);
	//send stop condition
	TWI_SendStopCondition();
	return data;
}
