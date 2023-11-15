/*
 * USART_interface.h
 *
 *  Created on: Apr 9, 2021
 *      Author: 8
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
void USART_voidTransmit(u8 Copy_u8Data);
u8   USART_u8Receive(void);
void USART_voidTransmitString(u8* Copy_ptrString);
u8*  USART_ptrReceiveString(void);

#endif /* MCAL_USART_USART_INTERFACE_H_ */
