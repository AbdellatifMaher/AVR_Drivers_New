/*
 * Calc.c
 *
 *  Created on: Mar 28, 2021
 *      Author: 8
 */
/*
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include <util/delay.h>


int main(void){

	KPD_voidInit();
	CLCD_voidInit();

	while(1){
		CLCD_voidClear();
		CLCD_voidSetPosition(0,0);
		volatile u8 LOC_u8LastData = 0   ;
		volatile u8 LOC_u8CurrentData    ;
		volatile u8 LOC_arrInputData[18] ={0} ;
		volatile u8 LOC_u8EqualFlag = 0;
		volatile u8 LOC_u8OutFlag = 0 ;
		for(volatile u8 LOC_u8Iterator = 1 ; LOC_u8Iterator <= 17 ; LOC_u8Iterator ++ )
		{
			if ( LOC_u8OutFlag == 1)
				break;

			LOC_u8CurrentData = KPD_u8GetPressed();
			while( LOC_u8CurrentData == 0 )
			{
				LOC_u8CurrentData = KPD_u8GetPressed();
			}
			if (LOC_u8CurrentData >= '0' && LOC_u8CurrentData <= '9' )
			{
				LOC_arrInputData[LOC_u8Iterator] = LOC_u8CurrentData -48 ;
				CLCD_voidSendData( LOC_u8CurrentData );
				LOC_u8LastData = LOC_u8CurrentData ;
			}
			else if ( LOC_u8CurrentData >= '*' && LOC_u8CurrentData <= '/' )
			{
				if ( (LOC_u8CurrentData == '*' || LOC_u8CurrentData == '/' ) && LOC_u8Iterator == 1)
				{
					CLCD_voidSetPosition(2 , 0);
					CLCD_voidSendString((u8 *)"ERROR ");
					CLCD_voidSetPosition(1,0);
					LOC_u8Iterator -- ;
					_delay_ms(500);
					CLCD_voidClear();
				}
				else {
				 if( LOC_u8LastData >= '*' && LOC_u8LastData <= '/')
				    {
					 if ( LOC_u8CurrentData != '-' ){
					   CLCD_voidSetPosition(1 , --LOC_u8Iterator );
					 }
				    }
				 LOC_arrInputData[LOC_u8Iterator] = LOC_u8CurrentData ;
				 CLCD_voidSendData( LOC_u8CurrentData );
				 LOC_u8LastData = LOC_u8CurrentData ;
				}
			}
			else if ( LOC_u8CurrentData == '=' )
			{
				volatile f64 LOC_arrFinalFunc[17] = {0};
				volatile u8 LOC_u8ArrCounter = 1;
				volatile u8 LOC_u8PreviousData = '0' ;
				volatile u8 LOC_u8Sign = 0 ;
				LOC_u8EqualFlag = 1 ;
				for( volatile u8 LOC_u8SecondIterator = 1 ; LOC_u8SecondIterator < LOC_u8Iterator ; LOC_u8SecondIterator++ )
				{
					if(LOC_arrInputData[LOC_u8SecondIterator] >= 0 && LOC_arrInputData[LOC_u8SecondIterator] <= 9 )
					{
						if( (LOC_u8PreviousData  >= 0 && LOC_u8PreviousData  <= 9) || LOC_u8PreviousData == '0' )
						{
						  LOC_arrFinalFunc[LOC_u8ArrCounter] = LOC_arrFinalFunc[LOC_u8ArrCounter] * 10 + LOC_arrInputData[LOC_u8SecondIterator];
						  LOC_u8PreviousData = LOC_arrInputData[LOC_u8SecondIterator];
						}
						else{
							if(LOC_u8PreviousData = '/' && (LOC_arrInputData[LOC_u8SecondIterator] == 0) )
							{
								CLCD_voidSetPosition(2,0);
							   CLCD_voidSendString((u8 *)"Error");
							  _delay_ms(1000);
							  LOC_u8OutFlag = 1;
								break;

							}
							++LOC_u8ArrCounter;
							LOC_arrFinalFunc[LOC_u8ArrCounter] = LOC_arrInputData[LOC_u8SecondIterator];
							LOC_u8PreviousData = LOC_arrInputData[LOC_u8SecondIterator];
						}
						if ( LOC_u8Sign == 1)
						{
							LOC_arrFinalFunc[LOC_u8ArrCounter] *= -1 ;
							LOC_u8Sign = 0;
						}
					}
					else if ( LOC_arrInputData[LOC_u8SecondIterator] >= '*' && LOC_arrInputData[LOC_u8SecondIterator] <= '/' )
					{
						if( LOC_u8SecondIterator == 1 || (LOC_arrInputData[LOC_u8PreviousData] >= '*' && LOC_arrInputData[LOC_u8PreviousData] <= '/' ) )
						{
							if( LOC_arrInputData[LOC_u8SecondIterator] == '-' )
							{
								LOC_u8Sign = 1 ;
							}
						}
						else
						{
							++LOC_u8ArrCounter;
							LOC_arrFinalFunc[LOC_u8ArrCounter] = LOC_arrInputData[LOC_u8SecondIterator];
							LOC_u8PreviousData = LOC_arrInputData[LOC_u8SecondIterator];
						}
					}
				}
				if(LOC_u8OutFlag != 1)
				{
				for( volatile u8 LOC_u8ThirdIterator = 1 ; LOC_u8ThirdIterator <= LOC_u8ArrCounter ; LOC_u8ThirdIterator++ )
				{
					if( LOC_arrFinalFunc[LOC_u8ThirdIterator] == '*' )
					{
						volatile u8 LOC_u8FastCheck = LOC_u8ThirdIterator -1 ;
						 while ( LOC_arrFinalFunc[LOC_u8FastCheck] == 'x')
						 {
							 LOC_u8FastCheck--;
						 }
						 LOC_arrFinalFunc[LOC_u8FastCheck] = LOC_arrFinalFunc[LOC_u8FastCheck] * LOC_arrFinalFunc[LOC_u8ThirdIterator + 1];
						 LOC_arrFinalFunc[LOC_u8ThirdIterator ] = 'x';
						 LOC_arrFinalFunc[LOC_u8ThirdIterator + 1] = 'x';
					}
					else if ( LOC_arrFinalFunc[LOC_u8ThirdIterator] == '/'  )
					{
						volatile u8 LOC_u8FastCheck = LOC_u8ThirdIterator -1 ;
						 while ( LOC_arrFinalFunc[LOC_u8FastCheck] == 'x')
						{
						 LOC_u8FastCheck--;
						}
				    	 LOC_arrFinalFunc[LOC_u8FastCheck] = LOC_arrFinalFunc[LOC_u8FastCheck] / (f32) LOC_arrFinalFunc[LOC_u8ThirdIterator + 1];
		                 LOC_arrFinalFunc[LOC_u8ThirdIterator ] = 'x';
				         LOC_arrFinalFunc[LOC_u8ThirdIterator + 1] = 'x';
					}
				}
				for( volatile u8 LOC_u8FourthIterator = 1 ; LOC_u8FourthIterator <= LOC_u8ArrCounter ; LOC_u8FourthIterator++ )
				{
					if( LOC_arrFinalFunc[LOC_u8FourthIterator] == '+' )
					{

						volatile u8 LOC_u8FastCheck = LOC_u8FourthIterator -1 ;
						 while ( LOC_arrFinalFunc[LOC_u8FastCheck] == 'x')
						 {
						  LOC_u8FastCheck--;
						 }
				     LOC_arrFinalFunc[LOC_u8FourthIterator + 1] = LOC_arrFinalFunc[LOC_u8FastCheck] + LOC_arrFinalFunc[LOC_u8FourthIterator + 1];
				     LOC_arrFinalFunc[LOC_u8FourthIterator ] = 'x';
				     LOC_arrFinalFunc[LOC_u8FastCheck] = 'x';
					}
					else if ( LOC_arrFinalFunc[LOC_u8FourthIterator] == '-')
					{
						volatile u8 LOC_u8FastCheck = LOC_u8FourthIterator -1 ;
						while ( LOC_arrFinalFunc[LOC_u8FastCheck] == 'x')
						{
							LOC_u8FastCheck--;
						}
						LOC_arrFinalFunc[LOC_u8FourthIterator + 1] = LOC_arrFinalFunc[LOC_u8FastCheck] - LOC_arrFinalFunc[LOC_u8FourthIterator + 1];
					    LOC_arrFinalFunc[LOC_u8FourthIterator ] = 'x';
					    LOC_arrFinalFunc[LOC_u8FastCheck] = 'x';
					}
				}
			for( volatile u8 LOC_u8FifthIterator = 1 ; LOC_u8FifthIterator <= LOC_u8ArrCounter ; LOC_u8FifthIterator++ )
			{
				if(LOC_arrFinalFunc[LOC_u8FifthIterator] != 'x')
				{
					CLCD_voidSetPosition(2,0);
					CLCD_voidSendData('=');
					if(LOC_arrFinalFunc[LOC_u8FifthIterator] < 0)
					{
						CLCD_voidSendData('-');
						LOC_arrFinalFunc[LOC_u8FifthIterator] *=-1;
					}
					CLCD_voidSendNumber(LOC_arrFinalFunc[LOC_u8FifthIterator]);
					if((((u64)(LOC_arrFinalFunc[LOC_u8FifthIterator] * 100)) % 100) != 0 )
					{
							CLCD_voidSendData('.');
							CLCD_voidSendNumber((((u64)(LOC_arrFinalFunc[LOC_u8FifthIterator] * 100)) % 100));
					}
					LOC_u8OutFlag = 1;
					break;
				}
			}
				}

			}
			else if ( LOC_u8CurrentData == 'C' )
			{
				if (LOC_u8Iterator == 1 )
				{

				}
				else {
					CLCD_voidSetPosition(1 , --LOC_u8Iterator );
					CLCD_voidSendData(' ');
					CLCD_voidSetPosition(1 , LOC_u8Iterator );
					LOC_arrInputData[LOC_u8Iterator] = 0;

				}
			}
		}

		if ( LOC_u8EqualFlag == 0)
		{
			CLCD_voidSetPosition(2,0);
			CLCD_voidSendString((u8 *)"Error");
			_delay_ms(1000);
			CLCD_voidClear();
		}
		else
		{
		volatile u8 LOC_u8ExitFlag = KPD_u8GetPressed();
		while( LOC_u8ExitFlag == 0 )
		{
			LOC_u8ExitFlag = KPD_u8GetPressed();
		}
		CLCD_voidClear();
		}
	}

	return 0;
}

*/
