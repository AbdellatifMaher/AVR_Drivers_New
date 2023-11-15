/*
 * Timer1_private.h
 *
 *  Created on: Mar 27, 2021
 *      Author: 8
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define TCNT1  *((volatile u16*)0x4C)
#define OCR1A  *((volatile u16*)0x4A)
#define OCR1B  *((volatile u16*)0x48)
#define ICR1   *((volatile u16*)0x46)
#define TIMSK  *((volatile u8 *)0x59)
#define TIFR   *((volatile u8 *)0x58)

#ifndef NULL
       #define NULL 0
#endif

#endif /* TIMER1_PRIVATE_H_ */
