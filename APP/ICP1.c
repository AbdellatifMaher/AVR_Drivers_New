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



int main(void)
{
	u32 a,b,c,high,period;
	CLCD_voidInit();
	DIO_enumSetPortValue(DIO_PORTD,0xFF);
	while(1)
	{
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<5);  */	/* Clear ICF (Input Capture flag) flag */

		//TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		//while ((TIFR&(1<<5)) == 0);
		//a = ICR1;  		/* Take value of capture register */
		//TIFR = (1<<5);  	/* Clear ICF flag */

		//TCCR1B = 0x01;  	/* Falling edge, no prescaler */
		//while ((TIFR&(1<<5)) == 0);
		//b = ICR1;  		/* Take value of capture register */
		//TIFR = (1<<5);  	/* Clear ICF flag */

		//TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		//while ((TIFR&(1<<5)) == 0);
		//c = ICR1;  		/* Take value of capture register */
		//TIFR = (1<<5);  	/* Clear ICF flag */

		//TCCR1B = 0;  		/* Stop the timer */
		//if(a<b && b<c)  	/* Check for valid condition,
		//					to avoid timer overflow reading */
		//{
			//high=b-a;
			//period=c-a;

	/*		long freq= 8000000/period;*//* Calculate frequency */

			/* Calculate duty cycle */
	//	     float duty_cycle =((float) high /(float)period)*100;
	//	     CLCD_voidSendCommend(0x80);
	/*	     CLCD_voidSendString("Freq= ");
			 CLCD_voidSendNumber(freq);
		     CLCD_voidSendCommend(0xC0);
		    CLCD_voidSendString("Duty= ");
		    CLCD_voidSendNumber(duty_cycle);
		}
		else
		{
			CLCD_voidClear();//LCD_Clear
			CLCD_voidSendString("OUT OF RANGE!!");//LCD_String("OUT OF RANGE!!");
		}
				_delay_ms(50);
	}

	return 0;

}*/
