/*
 * TIMERsAPP.c
 *
 *  Created on: Apr 2, 2021
 *      Author: 8
 */
/*#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../MCAL/TIMER1/TIMER1_private.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include <util/delay.h>


//u32 volatile X=1;
u8 volatile flag = 0;
u32 volatile S1 = 0;
u32 volatile S2 = 0;
u32 volatile S3 = 0;
u64 volatile Counter = 0;

void func2(void)
{
	Counter++;
}
void EXT_func(void)
{
	if(flag == 0)
	{
		S1 = TCNT1 ;
		Counter = 0;
		EXTI_voidSetSignalLatch(EXTI_FALLING_EDGE,EXTI_LINE0);
	}
	else if (flag == 1){

		S2 = TCNT1 + (65536 * Counter) ;
		EXTI_voidSetSignalLatch(EXTI_RISING_EDGE,EXTI_LINE0);

	}
	else if (flag == 2 )
	{
		S3 = TCNT1 + (65536 * Counter) ;
		EXTI_voidDisableInterrupt(EXTI_LINE0);
		TIMER1_voidDisableInterrupt();
	}
	flag++;
}*/
/*void func(void)
{
	if(X == 1)
	{
		DIO_enumSetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);
		TIMER0_voidSetCounter(254);
		X = 0;
	}
	else{
		DIO_enumSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LOW);
		TIMER0_voidSetCounter(248);
		X = 1;
	}
}*/
/*int main(void)
{
	u16  freq = 0;
	u8  Duty = 0;
	//LED_Type LED = {DIO_PORTD , DIO_PIN0,ACTIVE_HIGH};
	TIMER0_voidInit();
	TIMER1_voidInit();
	EXTI_voidInit();
	EXTI_voidEnableInterrupt(EXTI_LINE0);
	CLCD_voidInit();
	DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	//TIMER0_voidSetCallBack(&func,TIMER0_INT_OVERFLOW);
	TIMER0_voidPWM(200);
	TIMER1_voidSetCallBack(&func2,TIMER1_INT_OVERFLOW);
	EXTI_voidSetCallBack(&EXT_func,EXTI_LINE0);
	EXTI_voidEnableGlobalInterrupt();*///here
/*	DIO_enumSetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);
	TIMER0_voidSetCounter(254);*/

/*	while(1)
	{
		if(flag == 3)
		{
			CLCD_voidSetPosition(1,1);
			CLCD_voidSendString((u8 *)"Freq = ");
			freq = 1000000 / (S3 - S1) ;
			CLCD_voidSendNumber(freq);
			CLCD_voidSetPosition(2,1);
			CLCD_voidSendString((u8 *)"Duty = ");
			Duty = ( (S2 - S1)*100 /(f32)(S3 - S1) ) ;
			CLCD_voidSendNumber(Duty);
			flag = 0 ;
			EXTI_voidClearFlag(EXTI_LINE0);
			TIMER1_voidClearFlag(TIMER1_INT_OVERFLOW);
			EXTI_voidEnableInterrupt(EXTI_LINE0);
			TIMER1_voidEnableInterrupt(TIMER1_INT_OVERFLOW);
		}  *///here
		/*TIMER0_voidSetOCR(100);
		_delay_ms(1000);
		TIMER0_voidSetOCR(200);
		_delay_ms(1000);*/
	/*	TIMER0_voidPWM(70); // Servo
		_delay_ms(5000);
		TIMER0_voidPWM(170);
		_delay_ms(5000);
		TIMER0_voidPWM(128);
		_delay_ms(5000);*/


/*	}
	return 0 ;
}*/

/*
 *
 *
 *  Created on: Feb 10, 2021
 *      Author: Abdellatif Maher
 */
/*
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIMER1/TIMER1_private.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include <util/delay.h>*/
/*
u32 GLO_u32Counter = 0;
u16 GLO_u16Flag = 0;
u16 GLO_u16Snap1 = 0;
u16 GLO_u16Snap2 = 0;
u16 GLO_u16Snap3 = 0;
void OVFT1(void)
{
	GLO_u32Counter++;
}
void ICUT1(void)
{
	if(GLO_u16Flag == 0)
	{
		GLO_u16Snap1 = TIMER1_u16GetICR1();
		TCCR1B=1;

	}
	else if(GLO_u16Flag == 1)
	{
		GLO_u16Snap2 = TIMER1_u16GetICR1() + (65536 * GLO_u32Counter);
		TCCR1B=0b01000001;
	}
	else if(GLO_u16Flag == 2)
	{
			GLO_u16Snap3 = TIMER1_u16GetICR1() + (65536 * GLO_u32Counter);
			TCCR1B=0b00000001;
			TIMSK = 0 ;
			GLO_u32Counter = 0;
	}
	GLO_u16Flag++;
}*/
//int main(void){
/*	TIMER0_voidInit();
	TIMER1_voidInit();
	CLCD_voidInit();
	TIMER0_voidPWM(128);
	TIMER1_voidSetCallBack(OVFT1,0);
	TIMER1_voidSetCallBack(ICUT1,3); */
	/*TIMER1_voidInit();
	TIMER1_voidSetICR1(2500);*/
/*	u32 volatile LOC_u32Value =0;
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

	while(1){*/
/*	u32 freq = (8000000/(GLO_u16Snap3 - GLO_u16Snap1));
	u32 Duty = ((GLO_u16Snap2 - GLO_u16Snap1)/(GLO_u16Snap3 - GLO_u16Snap1))*100;
	CLCD_voidSetPosition(1,1);
	CLCD_voidSendString("Freq = ");
	CLCD_voidSendNumber(freq);
	CLCD_voidSetPosition(2,1);
	CLCD_voidSendString("Duty = ");
	CLCD_voidSendNumber(Duty);
	_delay_ms(2000);
	TIMSK= 0b00100100;
	GLO_u16Flag = 0;
	CLCD_voidClear();*/

	/*	TIMER1_voidPWM(240,1);
		_delay_ms(2000);
		TIMER1_voidPWM(188,1);
		_delay_ms(2000);
		TIMER1_voidPWM(275,1);
		_delay_ms(2000); */
/*		    ADC_voidSelectChannel(ADC_CHANNEL0);
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
	}

	return 0;
}*/
