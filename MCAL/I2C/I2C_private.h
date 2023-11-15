/*
 * I2C_private.h
 *
 *  Created on: Apr 23, 2021
 *      Author: 8
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWBR *((volatile u8 *)0x20)
#define TWCR *((volatile u8 *)0x56)
#define TWSR *((volatile u8 *)0x21)
#define TWDR *((volatile u8 *)0x23)
#define TWAR *((volatile u8 *)0x22)


#endif /* I2C_PRIVATE_H_ */
