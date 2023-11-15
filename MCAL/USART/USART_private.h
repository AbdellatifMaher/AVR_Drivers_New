/*
 * USART_private.h
 *
 *  Created on: Apr 9, 2021
 *      Author: 8
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define UCSRA  *((volatile u8*)0x2B)
#define UCSRB  *((volatile u8*)0x2A)
#define UCSRC  *((volatile u8*)0x40)
#define UBRRL  *((volatile u8*)0x29)
#define UBRRH  *((volatile u8*)0x40)
#define UDR    *((volatile u8*)0x2C)

#ifndef NULL
       #define NULL 0
#endif


#endif /* =USART_PRIVATE_H_ */
