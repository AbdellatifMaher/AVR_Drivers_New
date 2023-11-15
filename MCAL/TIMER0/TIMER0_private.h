/*
 * TIMER0_private.h
 *
 *  Created on: Mar 29, 2021
 *      Author: 8
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define OCR0  *((volatile u8 *)0x5C)
#define TIMSK *((volatile u8 *)0x59)
#define TIFR  *((volatile u8 *)0x58)

#ifndef NULL
       #define NULL 0
#endif


#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
