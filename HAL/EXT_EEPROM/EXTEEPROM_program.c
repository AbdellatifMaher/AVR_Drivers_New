/*
 * EXTEEPROM_program.c
 *
 *  Created on: Apr 23, 2021
 *      Author: 8
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include "EXTEEPROM_interface.h"
#include "util/delay.h"

void EEPROM_voidInit(void){
	I2C_VidInitMaster();
}

void EEPROM_voidWrite_Byte(u16 Address , u8 Data){

	I2C_ERROR_STATUS State = NOK;
	State = I2C_StartCondition();
	if(State == OK){
		State = I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
		if(State == OK){
			State = I2C_Maste_Write_Byte_To_Slave((u8)Address);
			if(State == OK){
				State = I2C_Maste_Write_Byte_To_Slave(Data);
				if(State == OK){
					I2C_StopCondition();
				}
			}
		}
	}

}

u8 EEPROM_u8Read_Byte(u16 Address){
	u8 LOC_u8Data;
	I2C_ERROR_STATUS State = NOK;
	State = I2C_StartCondition();
	if(State == OK){
		State = I2C_Master_Send_Slave_Address_With_Write( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
		if(State == OK){
			State = I2C_Maste_Write_Byte_To_Slave((u8)Address);
			if(State == OK){
				State = I2C_RepeatedStart();
				if(State == OK){
					State = I2C_Master_Send_Slave_Address_With_Read( 0x50 | ( ( Address & 0x0700 ) >> 8 ) );
					if( State == OK ){
						State = I2C_Master_Read_Byte_From_Slave_NACK(&LOC_u8Data);
						if(State == OK){
							I2C_StopCondition();
						}
					}
				}
			}
		}
	}
	return LOC_u8Data;
}
