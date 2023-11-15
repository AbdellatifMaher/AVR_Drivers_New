/*
 * Double_SSD.c
 *
 *  Created on: Feb 12, 2021
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
#include "../HAL/SSD/SSD_interface.h"
#include <util/delay.h>


int main(void){

	SSD_Type SSD1 = { SSD_COMMON_CATHODE , DIO_PORTA , DIO_PORTC , DIO_PIN0 , SSD_CLOSE_DOT };
	SSD_Type SSD2 = { SSD_COMMON_CATHODE , DIO_PORTD , DIO_PORTC , DIO_PIN1 , SSD_CLOSE_DOT };
	//Data Port
	DIO_enumSetPortDirection( SSD1.DataPort , 255 );
	DIO_enumSetPortDirection( SSD2.DataPort , 255 );
	//Enable PORT , Enable Pin
	DIO_enumSetPinDirection ( SSD1.EnablePort , SSD1.EnablePin , DIO_OUTPUT );
	DIO_enumSetPinDirection ( SSD2.EnablePort , SSD2.EnablePin , DIO_OUTPUT );

	while(1){

		for( u8 i = 0 ; i < 10 ; i++ ){

			SSD_voidSendNumber( SSD2 ,  i );
			SSD_voidEnable( SSD2 );
			for(u8 j = 0 ; j < 10 ; j++)
			{
				SSD_voidSendNumber( SSD1 ,  j );
				SSD_voidEnable( SSD1 );
				_delay_ms(500);
			}

		}

	}

	return 0;
}
*/
