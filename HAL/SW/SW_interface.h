#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_FLOATING 0
#define SW_PULL_UP  1

typedef struct
{
	u8 Port      ;
	u8 Pin       ;
	u8 Pull_State;
}SW_Type;

void SW_voidInit    ( SW_Type SW_Configuration);
u8   SW_u8GetPressed( SW_Type SW_Configuration);

#endif