/*
 *
 *  Created on: Feb 10, 2021
 *      Author: Abdellatif Maher
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIMER1/TIMER1_private.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include <util/delay.h>

int main(void){
	u32 volatile LOC_u32Value =0;
	u32 volatile LOC_u32Value2 =0;
	    LED_Type YLED = { DIO_PORTA , DIO_PIN2 , ACTIVE_HIGH };
		LED_Type GLED = { DIO_PORTA , DIO_PIN3 , ACTIVE_HIGH };
		LED_Type RLED = { DIO_PORTA , DIO_PIN4 , ACTIVE_HIGH };
		CLCD_voidInit();
		ADC_voidInit();
		LED_voidInit(YLED);
		LED_voidInit(GLED);
		LED_voidInit(RLED);
		DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
		DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_INPUT);

	while(1){
			 LOC_u32Value =  ( ( (u32)ADC_u16GetResultSync() * 5000) / 1023) ;
			CLCD_voidSendString("Temp = ");
			CLCD_voidSendNumber( LOC_u32Value / 10);
			CLCD_voidSendString("C");
			CLCD_voidSetPosition(2,1);
			ADC_voidSelectChannel(ADC_CHANNEL1);
			 LOC_u32Value2 =  ADC_u16GetResultSync() ;
			CLCD_voidSendString("LDR = ");
			CLCD_voidSendNumber( LOC_u32Value2);
			_delay_ms(1000);
			CLCD_voidClear();
			CLCD_voidSetPosition(1,1);
			ADC_voidSelectChannel(ADC_CHANNEL0);
	}

	return 0;
}


