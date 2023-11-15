/*
 * Stepper_Motor.c
 *
 *  Created on: Feb 18, 2021
 *      Author: 8
 */


/*
 *
 *  Created on: Feb 10, 2021
 *      Author: Abdellatif Maher
 */
/*
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include <util/delay.h>


int main(void){
	DIO_enumSetPinDirection( DIO_PORTB , DIO_PIN0 , DIO_OUTPUT);
	DIO_enumSetPinDirection( DIO_PORTB , DIO_PIN1 , DIO_OUTPUT);
	DIO_enumSetPinDirection( DIO_PORTB , DIO_PIN2 , DIO_OUTPUT);
	DIO_enumSetPinDirection( DIO_PORTB , DIO_PIN3 , DIO_OUTPUT);
	for(u32 i =0 ; i<2048 ; i++){
	DIO_enumSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_HIGH );
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW );
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW );
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN3 , DIO_LOW );
				_delay_ms(2);
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_HIGH );
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_LOW );
				_delay_ms(2);
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_HIGH );
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW );
				_delay_ms(2);
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN3 , DIO_HIGH );
				DIO_enumSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW );
				_delay_ms(2);
	}

	while(1){

	}

	return 0;
} */
