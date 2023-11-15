/*
 * ADC_private.h
 *
 *  Created on: Mar 20, 2021
 *      Author: 8
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX  *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCL   *((volatile u8 *)0x24)
#define ADCH   *((volatile u8 *)0x25)
#define SFIOR  *((volatile u8 *)0x50)


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
