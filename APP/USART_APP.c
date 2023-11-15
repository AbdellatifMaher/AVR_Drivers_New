/*
 * USART_APP.c
 *
 *  Created on: Apr 9, 2021
 *      Author: 8
 */
/*#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../MCAL/TIMER1/TIMER1_private.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include <util/delay.h>


int main(void)
{
	u8 * Y = "Abdellatif Maher\r\n";
	u8 * M;
	u8 R = 0;
	LED_Type LED1 = {DIO_PORTC , DIO_PIN0,ACTIVE_HIGH};
	LED_Type LED2 = {DIO_PORTC , DIO_PIN1,ACTIVE_HIGH};
	LED_Type LED3 = {DIO_PORTC , DIO_PIN2,ACTIVE_HIGH};
	USART_voidInit();
	CLCD_voidInit();
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);
	USART_voidTransmitString(Y);
	USART_voidTransmitString((u8*)"To Power on LEDs Send On\r\n");
	USART_voidTransmitString((u8*)"To Power off LEDs Send Off\r\n");
	while(1)
	{

			M = USART_ptrReceiveString();
			//CLCD_voidSendString(M);
			if( M[0] =='O' && M[1] == 'n')
			{
				LED_voidOn(LED1);
				LED_voidOn(LED2);
				LED_voidOn(LED3);
				CLCD_voidSendString(M);
			}
			else //if( M ==  (u8*)"Off")
			{
				LED_voidOff(LED1);
				LED_voidOff(LED2);
				LED_voidOff(LED3);
				CLCD_voidSendString(M);
			}*/
		/*	_delay_ms(1000);
			CLCD_voidSetPosition(2,1);
			M = USART_ptrReceiveString();
			CLCD_voidSendString(M);
			_delay_ms(1000);
			CLCD_voidClear();
			CLCD_voidSetPosition(1,1);*/
	/*	R = USART_u8Receive();

		if(R == '1')
		{
			LED_voidOn(LED1);
			CLCD_voidSendData('1');
			USART_voidTransmit('\r');
			USART_voidTransmit('\n');
		}
		else if (R == '2')
		{
			LED_voidOn(LED2);
			CLCD_voidSendData('2');
			USART_voidTransmit('\r');
			USART_voidTransmit('\n');
		}
		else if(R == '3')
		{
			LED_voidOn(LED3);
			CLCD_voidSendData('3');
			USART_voidTransmit('\r');
			USART_voidTransmit('\n');
		}
		if(R == '4')
		{
			LED_voidOff(LED1);
			CLCD_voidSendData('4');
			USART_voidTransmit('\r');
			USART_voidTransmit('\n');
		}
		else if (R == '5')
		{
					LED_voidOff(LED2);
					CLCD_voidSendData('5');
					USART_voidTransmit('\r');
					USART_voidTransmit('\n');
		}
		else if(R == '6')
		{
					LED_voidOff(LED3);
					CLCD_voidSendData('6');
					USART_voidTransmit('\r');
					USART_voidTransmit('\n');
		}*/
/*	}

	return 0;
}*/


