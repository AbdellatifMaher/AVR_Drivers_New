/*
 * I2C_interface.h
 *
 *  Created on: Apr 23, 2021
 *      Author: 8
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define DISBLE_GENERAL_CALL 0
#define ENABLE_GENERAL_CALL 1

typedef enum{

	NOK,  //NOK = 0
	OK    //OK = 1

}I2C_ERROR_STATUS;

void I2C_voidInitMaster(void);
void I2C_voidInitSlave(void);
I2C_ERROR_STATUS I2C_enumStartCondition(void);
I2C_ERROR_STATUS I2C_enumRepeatedStart(void);//New
void I2C_voidStopCondition(void);
I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Write(u8 Address);
I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Read(u8 Address);
I2C_ERROR_STATUS I2C_Master_Write_Byte_To_Slave(u8 Data);
I2C_ERROR_STATUS I2C_Master_Read_Byte_From_Slave_NACK(u8 * ptr);//New
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Write(void);
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Read(void);//New
I2C_ERROR_STATUS I2C_Slave_Read_Byte_From_Master(u8 * ptr);
I2C_ERROR_STATUS I2C_Slave_Write_Byte_To_Master(u8 Data);//New


#endif /* I2C_INTERFACE_H_ */
