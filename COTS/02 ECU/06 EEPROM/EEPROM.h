/*
 * EEPROM.h
 *
 * Created: 4/26/2023 1:52:34 AM
 *  Author: yahia
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "I2Cconfig.h"
#include "I2Cinterface.h"
void EEPROM_Write(u16 location_Address,u8 Copy_Data);

u8 EEPROM_Read(u16 location_Address);

#endif /* EEPROM_H_ */
