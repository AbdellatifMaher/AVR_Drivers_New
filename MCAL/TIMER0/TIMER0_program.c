/*
 * TIMER0_program.c
 *
 *  Created on: Mar 29, 2021
 *      Author: 8
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

void (*TIMER0_CallBack[2])(void) ={NULL} ;

void TIMER0_voidInit(void)
{
		#if     TIMER0_MODE ==  TIMER0_NORMAL_MODE

				CLR_BIT(TCCR0,6); CLR_BIT(TCCR0,3);

		#elif	TIMER0_MODE ==	TIMER0_CTC_MODE

				CLR_BIT(TCCR0,6); SET_BIT(TCCR0,3);

		#elif   TIMER0_MODE == TIMER0_PWM_Phase_MODE

				SET_BIT(TCCR0,6); CLR_BIT(TCCR0,3);

		#elif   TIMER0_MODE == TIMER0_FAST_PWM_MODE

				SET_BIT(TCCR0,6); SET_BIT(TCCR0,3);
		#endif

		TCCR0 |= TIMER0_PRESCALLER ;

		TCCR0 |= (TIMER0_OCR0_MODE << 4 ) ;

		TIMSK |= TIMER0_INTERRUPT ;

}

void TIMER0_voidSetCounter(u8 Copy_u8Counter)
{
	TCNT0 = Copy_u8Counter ;
}
u8  TIMER0_u16GetCounter(void)
{
	return TCNT0;
}
void TIMER0_voidSetOCR(u8 Copy_u8OCR)
{
	OCR0 = Copy_u8OCR ;
	DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
}
void TIMER0_voidClearFlag(u8 Copy_u8Interrupt)
{
	TIFR |= (1 << (Copy_u8Interrupt -1)) ;
}
u8   TIMER0_u8GetFlag(u8 Copy_u8Interrupt)
{
	return GET_BIT(TIFR,Copy_u8Interrupt -1 );
}
void TIMER0_voidDisableInterrupt(void)
{
	TIMSK |= TIMER0_INT_DISABLE ;
}
void TIMER0_voidEnableInterrupt(u8 Copy_u8Interrupt)
{
	TIMSK |= Copy_u8Interrupt ;
}
void TIMER0_voidPWM(u8 Copy_u8TimeOn)
{
	TIMER0_voidSetOCR(Copy_u8TimeOn);
	DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
}
void TIMER0_voidmSecDelay(u64 Copy_u64MilliSeconds)
{
	TCCR0 &=0b11111011; /* PreScaller 64 */
	for(u64 Iterator = 1 ; Iterator <= Copy_u64MilliSeconds ; Iterator++)
	{
		TIMER0_voidSetCounter(131);
		while( TIMER0_u8GetFlag(TIMER0_INT_OVERFLOW) != 1 )
		{ }
		TIMER0_voidClearFlag(TIMER0_INT_OVERFLOW);
	}

}
void TIMER0_voiduSecDelay(u64 Copy_u64MicroSeconds)
{
	TCCR0 &=0b11111010;
	if(Copy_u64MicroSeconds < 256)
	{
		TIMER0_voidSetCounter(256 - Copy_u64MicroSeconds);
		while( TIMER0_u8GetFlag(TIMER0_INT_OVERFLOW) != 1 ){ }
		TIMER0_voidClearFlag(TIMER0_INT_OVERFLOW);
	}
	else if (Copy_u64MicroSeconds >= 256 )
	{
		u64 LOC_u64Number = Copy_u64MicroSeconds / 256;
		u8 LOC_u8Number = ((f32)Copy_u64MicroSeconds / 256 - LOC_u64Number) * 256 ;

	for(u64 Iterator = 1 ; Iterator <= LOC_u64Number ; Iterator++)
		{
			while( TIMER0_u8GetFlag(TIMER0_INT_OVERFLOW) != 1 )
			{ }
			TIMER0_voidClearFlag(TIMER0_INT_OVERFLOW);
		}
	TIMER0_voidSetCounter(256 - LOC_u8Number);
	while( TIMER0_u8GetFlag(TIMER0_INT_OVERFLOW) != 1 ){ }
	TIMER0_voidClearFlag(TIMER0_INT_OVERFLOW);

	}
}

void TIMER0_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt )
{
	if( Copy_pvoidCallBack != NULL ){
		TIMER0_CallBack[Copy_u8Interrupt - 1] = Copy_pvoidCallBack ;
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_CallBack[1] != NULL)
	{
		TIMER0_CallBack[1]();
		TIMER0_voidClearFlag(TIMER0_INT_OVERFLOW);
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_CallBack[0] != NULL)
		{
			TIMER0_CallBack[0]();
			TIMER0_voidClearFlag(TIMER0_INT_COMP_MATCH);
		}
}

