/*
 * I2C_program.c
 *
 *  Created on: Apr 23, 2021
 *      Author: 8
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

void I2C_voidInitMaster(void){
	TWBR = 32;//I2C Speed = 100khzbs
	/*Set Prescaller*/
	CLR_BIT(TWSR , 0);
	CLR_BIT(TWSR , 1);
	SET_BIT(TWCR,2);//Enable I2c
}

void I2C_voiddInitSlave(void){
	TWAR = (SLAVE_ADDRESS <<1) | GENERAL_CALL;
	SET_BIT(TWCR,2);//Enable I2c
}

I2C_ERROR_STATUS I2C_enumStartCondition(void){

	I2C_ERROR_STATUS State = NOK;

	SET_BIT(TWCR,5);//Set Start
	SET_BIT(TWCR,7);//Clear Flag
	//Wait until Flag Set
	while((GET_BIT(TWCR,7))==0);
	if( (TWSR & 0xF8) == 0x08 ){
		State = OK;
	}
	return State;
}

I2C_ERROR_STATUS I2C_enumRepeatedStart(void){
	I2C_ERROR_STATUS State = NOK;
	SET_BIT(TWCR,5);//Set Start
	SET_BIT(TWCR,7);//Clear Flag
	//Wait until Flag Set
	while((GET_BIT(TWCR,7))==0);
	if( (TWSR & 0xF8) == 0x10 ){
		State = OK;
	}
	return State;
}

void I2C_voidStopCondition(void){
	SET_BIT(TWCR,4);//Stop bit
	SET_BIT(TWCR,7);//ClearFlag
}

I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Write(u8 Address){
	I2C_ERROR_STATUS State = NOK;
	TWDR = (Address<<1);//Set Slave Addr
	CLR_BIT(TWCR,5);//Clear Start bit
	SET_BIT(TWCR,7);//Clear Flag
	/*Wait Untill Flag set*/
	while((GET_BIT(TWCR,7)) == 0 );
	if( ( TWSR & 0xF8 ) == 0x18 ){
		State = OK;
	}
	return State;
}

I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Read(u8 Address){
	I2C_ERROR_STATUS State = NOK;
	TWDR = (Address<<1);//Set Slave Addr
	SET_BIT(TWDR,0);//SET R/W Bit To Read From Slave
	CLR_BIT(TWCR,5);//Clear Start bit
	SET_BIT(TWCR,7);//Clear Flag
	/*Wait Untill Flag set*/
	while((GET_BIT(TWCR,7)) == 0 );
	if( ( TWSR & 0xF8 ) == 0x40 ){
		State = OK;
	}
	return State;
}

I2C_ERROR_STATUS I2C_Master_Write_Byte_To_Slave(u8 Data){
	I2C_ERROR_STATUS State =NOK;
	TWDR = Data;
	SET_BIT(TWCR,7);//Clear Flag
	while((GET_BIT(TWCR,7)) == 0);
	if( ( TWSR & 0xF8 ) == 0x28 ){
		State = OK;
	}
	return State;
}

I2C_ERROR_STATUS I2C_Master_Read_Byte_From_Slave_NACK(u8 * ptr){
	I2C_ERROR_STATUS State = NOK;
	SET_BIT(TWCR,7);
	while((GET_BIT(TWCR,7)) == 0);
	if( ( TWSR & 0xF8 ) == 0x58 ){
		State = OK;
		*ptr = TWDR;
	}
	return State;
}

/////////////////////////////////////Slave/////////////////////////
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Write(void){
	I2C_ERROR_STATUS State = NOK;
	SET_BIT(TWCR,6);//Enable Ack
	SET_BIT(TWCR,7);//Clear
	while((GET_BIT(TWCR,7)) == 0);
	if(( TWSR & 0xF8) == 0x60 ){
		State = OK;
	}
	return State;
}

I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Read(void){
	I2C_ERROR_STATUS State = NOK;
	SET_BIT(TWCR,6);//Enable Ack
	SET_BIT(TWCR,7);//Clear
	while((GET_BIT(TWCR,7)) == 0);
	if(( TWSR & 0xF8) == 0xA8 ){
		State = OK;
	}
	return State;
}

I2C_ERROR_STATUS I2C_Slave_Read_Byte_From_Master(u8 * ptr){
	I2C_ERROR_STATUS State = NOK;
	SET_BIT(TWCR,7);
	while( (GET_BIT(TWCR,7)) == 0 );
	if( (TWSR & 0xF8) == 0x80 ){
		State = OK;
		*ptr = TWDR;
	}
	return State;
}

I2C_ERROR_STATUS I2C_Slave_Write_Byte_To_Master_NACK(u8 Data){
	I2C_ERROR_STATUS State = NOK;
	TWDR = Data;
	SET_BIT(TWCR,7);
	while( (GET_BIT(TWCR,7)) == 0 );
	if( (TWSR & 0xF8) == 0xC0 ){
		State = OK;
	}
	return State;
}

