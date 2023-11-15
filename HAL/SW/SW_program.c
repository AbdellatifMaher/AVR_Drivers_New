#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

void SW_voidInit    ( SW_Type SW_Configuration)
{
	DIO_enumSetPinDirection( SW_Configuration.Port , SW_Configuration.Pin , DIO_INPUT);
	if( SW_Configuration.Pull_State == SW_PULL_UP )
	{
		DIO_enumSetPinValue( SW_Configuration.Port , SW_Configuration.Pin , DIO_HIGH);
	}
	else if( SW_Configuration.Pull_State == SW_FLOATING )
	{
		DIO_enumSetPinValue( SW_Configuration.Port , SW_Configuration.Pin , DIO_LOW );
	}
}
u8   SW_u8GetPressed( SW_Type SW_Configuration)
{
	u8 LOC_u8Result = 0;
	DIO_enumGetPinValue ( SW_Configuration.Port , SW_Configuration.Pin , &LOC_u8Result);
	return LOC_u8Result;
}
