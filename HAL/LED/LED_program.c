#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidInit  ( LED_Type LED_Configuration )
{
	DIO_enumSetPinDirection( LED_Configuration.Port , LED_Configuration.Pin , DIO_OUTPUT);
}
void LED_voidOn    ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_HIGH);
	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_LOW );
	}
}
void LED_voidOff   ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_LOW );
	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_HIGH);
	}	
}
void LED_voidToggle( LED_Type LED_Configuration )
{
	u8 LOC_u8LastState ;
	DIO_enumGetPinValue( LED_Configuration.Port , LED_Configuration.Pin , &LOC_u8LastState  );
	DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , !LOC_u8LastState  );
	

	//DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , TOG_BIT(LED_Configuration.Port,LED_Configuration.Pin) );
}
