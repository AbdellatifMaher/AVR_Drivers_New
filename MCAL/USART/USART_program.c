/*
 * USART_program.c
 *
 *  Created on: Apr 9, 2021
 *      Author: 8
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void (*USART_CallBack[3]) (void) = { NULL } ;

void USART_voidInit(void)
{
	UCSRA = 0;
	UCSRB = 0b00011000 ;
	UCSRC = 0b10000110 ;
	UBRRL = 51 ;
	UBRRH = 0  ;

	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);
}
void USART_voidTransmit(u8 Copy_u8Data)
{
	UDR = Copy_u8Data ; // Write Operation Clear The Flag
	while (GET_BIT(UCSRA,5) == 0);
}
u8   USART_u8Receive(void)
{
	while (GET_BIT(UCSRA,7) == 0);
	return UDR ; // Read Operation Clear The Flag

}
void USART_voidTransmitString(u8* Copy_ptrString)
{
	u8 LOC_u8Iterator = 0;
	while(Copy_ptrString[LOC_u8Iterator] != '\0')
	{
		USART_voidTransmit(Copy_ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}
u8*  USART_ptrReceiveString(void)
{
	u8 LOC_u8ReceiveChar = 0;
	u8 LOC_u8Iterator = 0;

	LOC_u8ReceiveChar = USART_u8Receive();
	while(LOC_u8ReceiveChar != 13)
	{
		LOC_u8Arr[LOC_u8Iterator] = LOC_u8ReceiveChar;
		LOC_u8ReceiveChar = USART_u8Receive();
		LOC_u8Iterator++;
	}
	LOC_u8Arr[LOC_u8Iterator]='\0';
	return LOC_u8Arr ;
}

void USART_voidSetCallBack(void (*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt)
{
	if(Copy_pvoidCallBack !=  NULL)
	{
		USART_CallBack[Copy_u8Interrupt] = Copy_pvoidCallBack;
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(USART_CallBack[0] != NULL)
	{
		USART_CallBack[0]();
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if(USART_CallBack[1] != NULL)
	{
		USART_CallBack[1]();
	}
}
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(USART_CallBack[2] != NULL)
	{
		USART_CallBack[2]();
	}
}
