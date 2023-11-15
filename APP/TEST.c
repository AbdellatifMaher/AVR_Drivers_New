/*
 * TEST.c
 *
 *  Created on: Apr 8, 2021
 *      Author: 8
 */
/*
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../MCAL/TIMER1/TIMER1_private.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
//#include "../HAL/KPD/KPD_interface.h"
#include <util/delay.h>

u64 volatile Counter = 0;
u32 volatile S1 = 0;
u32 volatile S2 = 0;
u32 volatile S3 = 0;
u8  volatile flag = 0;
void func(void)
{
	Counter++;
}
void func2(void)
{
	if(flag == 0)
	{
		S1 = TIMER1_u16GetICR1();
		Counter=0;
		TIMER1_voidChangeEdge(INPUT_CAPTURE_FALLING_EDGE);
	}
	else if(flag == 1)
	{
		S2 = TIMER1_u16GetICR1() + (65536 * Counter);
		TIMER1_voidChangeEdge(INPUT_CAPTURE_RISING_EDGE);
	}
	else if(flag == 2)
	{
		S3 = TIMER1_u16GetICR1() + (65536 * Counter);
		TIMER1_voidDisableInterrupt();
	}
	flag++;
}
int main(void)
{

	TIMER1_voidInit();
	TIMER0_voidInit();
	CLCD_voidInit();
	DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_INPUT);
	TIMER0_voidPWM(200);
	TIMER1_voidSetCallBack(&func,TIMER1_INT_OVERFLOW);
	TIMER1_voidSetCallBack(&func2,TIMER1_INT_INPUT_CAPTURE);
	EXTI_voidEnableGlobalInterrupt();
	while(1)
	{
		u32 freq =0;
		u32 Duty =0;
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
			_delay_ms(1000);
			CLCD_voidClear();
			flag = 0 ;
			TIMER1_voidClearFlag(TIMER1_INT_OVERFLOW);
			TIMER1_voidClearFlag(TIMER1_INT_INPUT_CAPTURE);
			TIMER1_voidEnableInterrupt(TIMER1_INT_OVERFLOW);
			TIMER1_voidEnableInterrupt(TIMER1_INT_INPUT_CAPTURE);

		}
	}
	return 0;
}
*/
