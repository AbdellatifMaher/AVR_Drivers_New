/*
 * CLCD_program.c
 *
 *  Created on: Feb 12, 2021
 *      Author: 8
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_extrachar.h"
#include "util/delay.h"

void CLCD_voidInit        ( void ){

	DIO_enumSetPortDirection ( CLCD_DATA_PORT    , 255                   );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_OUTPUT  );

	_delay_ms(50);
	/*FUNCTION SET COMMEND*/
	CLCD_voidSendCommend( 0b00111000 );
	_delay_ms(1);
	/* DISPLAY ON / OFF */
	CLCD_voidSendCommend( 0b00001100 );
	_delay_ms(1);
	/* DISPLAY CLEAR */
	CLCD_voidSendCommend( 0b00000001 );
	_delay_ms(2);
	/* DISPLAY ENTRY MODE */
	CLCD_voidSendCommend( 0b00000010 );
	_delay_ms(1);

}
void CLCD_voidClear        ( void )
{

	/* Clear Screen */
	CLCD_voidSendCommend( 0x01 );

}

void CLCD_voidSendData    ( u8 Copy_u8Data ){

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Data        );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_LOW  );

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_HIGH );
	_delay_ms(1);
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_LOW  );
	_delay_ms(1);

}

void CLCD_voidSendCommend ( u8 Copy_u8Commend ){

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Commend     );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_LOW  );

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_HIGH );
	_delay_ms(1);
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_LOW  );
	_delay_ms(1);


}


void CLCD_voidSendString  ( u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}


void CLCD_voidSendNumber   ( u64 Copy_s64Number    ){

	u64 LOC_u64Reversed = 1 ;
	if( Copy_s64Number == 0 ){ CLCD_voidSendData('0'); }

	else{

		while( Copy_s64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_s64Number % 10 );
			Copy_s64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}
void CLCD_voidSendFloatNumber   ( f64 Copy_f64Number    )
{
	CLCD_voidSendNumber((u64)Copy_f64Number);
	if((((u64)(Copy_f64Number * 100)) % 100) != 0 )
	{
		CLCD_voidSendData('.');
		CLCD_voidSendNumber((((u64)(Copy_f64Number * 100)) % 100));
	}
}


void CLCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	if( Copy_u8Row == CLCD_ROW_1 ){

		CLCD_voidSendCommend( ( 0x80 ) + ( Copy_u8Col - 1 ) );

	}else if( Copy_u8Row == CLCD_ROW_2 ){

		CLCD_voidSendCommend( ( 0x80 ) + (64) + ( Copy_u8Col - 1 ) );

	}

}



void CLCD_voidSendExtraChar( void ){

	u8 LOC_u8Iterator = 0 ;
	/* 1- Go To CGRAM            */
	CLCD_voidSendCommend( 0b01000000 );
	/* 2- Draw Character         */
	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ; LOC_u8Iterator++){

		CLCD_voidSendData( CLCD_u8ExtraChar[LOC_u8Iterator] );

	}

}

void CLCD_voidDisplayExtraChar( u8 Copy_u8CharNumber , u8 Copy_u8Row , u8 Copy_u8Col )
{
	/* 3- Back To DDRAM          */
	CLCD_voidSetPosition(Copy_u8Row,Copy_u8Col);

	/* 4- Send Character Address */

		CLCD_voidSendData( Copy_u8CharNumber );

}

