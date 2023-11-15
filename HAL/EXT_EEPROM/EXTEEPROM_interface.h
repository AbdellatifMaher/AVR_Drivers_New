/*
 * EXTEEPROM_interface.h
 *
 *  Created on: Apr 23, 2021
 *      Author: 8
 */

#ifndef EXTEEPROM_INTERFACE_H_
#define EXTEEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWrite_Byte(u16 Address , u8 Data);
u8   EEPROM_u8Read_Byte(u16 Address);

#endif /* EXTEEPROM_INTERFACE_H_ */
