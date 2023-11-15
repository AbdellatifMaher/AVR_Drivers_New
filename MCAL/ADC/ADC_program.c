/*
 * ADC_program.c
 *
 *  Created on: Mar 20, 2021
 *      Author: 8
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include <util/delay.h>

void ADC_voidInit(void){

#if  ADC_STATUS == ADC_ENABLE

	#if    ADC_VREF == AREF

		CLR_BIT( ADMUX , 6 ); CLR_BIT( ADMUX , 7 );

	#elif  ADC_VREF == AVCC

		SET_BIT( ADMUX , 6 ); CLR_BIT( ADMUX , 7 );

	#elif  ADC_VREF == INTERNAL_2_56

		SET_BIT( ADMUX , 6 ); SET_BIT( ADMUX , 7 );

	#endif


	#if    ADC_ADJUSTMENT == RIGHT_ADJUSTMENT

			CLR_BIT( ADMUX , 5 );

	#elif  ADC_ADJUSTMENT == LEFT_ADJUSTMENT

			SET_BIT( ADMUX , 5 );

	#endif

	#if ADC_CHANNEL >= ADC_CHANNEL0 && ADC_CHANNEL <= ADC_DIFF_4_2_x1
				ADMUX &= 0b11100000;
				ADMUX |= ADC_CHANNEL;

	#else

			#warning  " Wrong ADC Channel "

	#endif

	#if      ADC_PRESCALLER  == ADC_PRE_2
				CLR_BIT( ADCSRA , 0 ); CLR_BIT( ADCSRA , 1 ); CLR_BIT( ADCSRA , 2 );
	#elif    ADC_PRESCALLER  == ADC_PRE_4
				CLR_BIT( ADCSRA , 0 ); SET_BIT( ADCSRA , 1 ); CLR_BIT( ADCSRA , 2 );
	#elif    ADC_PRESCALLER  == ADC_PRE_8
				SET_BIT( ADCSRA , 0 ); SET_BIT( ADCSRA , 1 ); CLR_BIT( ADCSRA , 2 );
	#elif    ADC_PRESCALLER  == ADC_PRE_16
				CLR_BIT( ADCSRA , 0 ); CLR_BIT( ADCSRA , 1 ); SET_BIT( ADCSRA , 2 );
	#elif    ADC_PRESCALLER  == ADC_PRE_32
				SET_BIT( ADCSRA , 0 ); CLR_BIT( ADCSRA , 1 ); SET_BIT( ADCSRA , 2 );
	#elif    ADC_PRESCALLER  == ADC_PRE_64
				CLR_BIT( ADCSRA , 0 ); SET_BIT( ADCSRA , 1 ); SET_BIT( ADCSRA , 2 );
	#elif    ADC_PRESCALLER  == ADC_PRE_128
			SET_BIT( ADCSRA , 0 ); SET_BIT( ADCSRA , 1 ); SET_BIT( ADCSRA , 2 );

	#endif

	#if     ADC_TRIGGERING_SOURCE == ADC_SINGLE_CONVERSION

				CLR_BIT( ADCSRA , 5 );

	#elif   ADC_TRIGGERING_SOURCE == ADC_FREE_RUNNING

				SET_BIT( ADCSRA , 5 );
				CLR_BIT( SFIOR , 5 );CLR_BIT( SFIOR , 6 );CLR_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_ANALOG_COMPARATOR

				SET_BIT( ADCSRA , 5 );
				SET_BIT( SFIOR , 5 );CLR_BIT( SFIOR , 6 );CLR_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_EXTI0

				SET_BIT( ADCSRA , 5 );
				CLR_BIT( SFIOR , 5 );SET_BIT( SFIOR , 6 );CLR_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_TIM0_CTC

				SET_BIT( ADCSRA , 5 );
				SET_BIT( SFIOR , 5 );SET_BIT( SFIOR , 6 );CLR_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_TIM0_OVF

				SET_BIT( ADCSRA , 5 );
				CLR_BIT( SFIOR , 5 );CLR_BIT( SFIOR , 6 );SET_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_TIM1_CTC_CHANNEL_B

				SET_BIT( ADCSRA , 5 );
				SET_BIT( SFIOR , 5 );CLR_BIT( SFIOR , 6 );SET_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_TIM1_OVF

				SET_BIT( ADCSRA , 5 );
				CLR_BIT( SFIOR , 5 );SET_BIT( SFIOR , 6 );SET_BIT( SFIOR , 7  );

	#elif   ADC_TRIGGERING_SOURCE == ADC_TIM1_ICU

				SET_BIT( ADCSRA , 5 );
				SET_BIT( SFIOR , 5 );SET_BIT( SFIOR , 6 );SET_BIT( SFIOR , 7  );

	#endif

	SET_BIT( ADCSRA , 7 );

#endif

}

u16 ADC_u16GetResultSync( void ){

	u16 LOC_u16Result = 0 ;

	SET_BIT( ADCSRA , 6 );

	while( GET_BIT( ADCSRA , 4 ) == 0 );
	_delay_us(10);

	LOC_u16Result = ADCL | ( ADCH << 8 ) ;

	SET_BIT( ADCSRA , 4 );

	return LOC_u16Result ;

}
void ADC_voidSelectChannel(u8 LOC_u8Channel)
{
	CLR_BIT( ADCSRA , 7 );
	_delay_ms(10);
	if (LOC_u8Channel >= ADC_CHANNEL0 && LOC_u8Channel <= ADC_DIFF_4_2_x1)
	{
		ADMUX &= 0b11100000 ;
		ADMUX |= LOC_u8Channel  ;
	}
	SET_BIT( ADCSRA , 7 );
	_delay_ms(10);
}
