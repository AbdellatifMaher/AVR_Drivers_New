/*
 * ADC_interface.h
 *
 *  Created on: Mar 19, 2021
 *      Author: 8
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*
 * Select your channel
 * select V Reference
 * Select Adjustment
 * Select PreScaller
 * Select Mode
 * Enable ADC
 */



#define ADC_DISABLE    0
#define ADC_ENABLE     1

#define AREF           0
#define AVCC           1
#define INTERNAL_2_56  3


#define RIGHT_ADJUSTMENT   0
#define LEFT_ADJUSTMENT    1

#define ADC_CHANNEL0		0
#define ADC_CHANNEL1 		1
#define ADC_CHANNEL2 		2
#define ADC_CHANNEL3 		3
#define ADC_CHANNEL4 		4
#define ADC_CHANNEL5 		5
#define ADC_CHANNEL6 		6
#define ADC_CHANNEL7  		7
#define ADC_DIFF_0_0_x10 	8
#define ADC_DIFF_1_0_x10  	9
#define ADC_DIFF_0_0_x200 	10
#define ADC_DIFF_1_0_x200 	11
#define ADC_DIFF_2_2_x10 	12
#define ADC_DIFF_3_2_x10 	13
#define ADC_DIFF_2_2_x200 	14
#define ADC_DIFF_3_2_x200 	15
#define ADC_DIFF_0_1_x1		16
#define ADC_DIFF_1_1_x1		17
#define ADC_DIFF_2_1_x1		18
#define ADC_DIFF_3_1_x1		19
#define ADC_DIFF_4_1_x1		20
#define ADC_DIFF_5_1_x1		21
#define ADC_DIFF_6_1_x1		22
#define ADC_DIFF_7_1_x1		23
#define ADC_DIFF_0_2_x1		24
#define ADC_DIFF_1_2_x1		25
#define ADC_DIFF_2_2_x1		26
#define ADC_DIFF_3_2_x1		27
#define ADC_DIFF_4_2_x1		28


#define ADC_SINGLE_CONVERSION   0
#define ADC_FREE_RUNNING        1
#define ADC_ANALOG_COMPARATOR   2
#define ADC_EXTI0               3
#define ADC_TIM0_CTC            4
#define ADC_TIM0_OVF            5
#define ADC_TIM1_CTC_CHANNEL_B  6
#define ADC_TIM1_OVF            7
#define ADC_TIM1_ICU            8


#define ADC_INTERRUPT_DISABLE 0
#define ADC_INTERRUPT_ENABLE  1


#define ADC_PRE_2               0
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7

void ADC_voidInit(void);
u16  ADC_u16GetResultSync( void );
void ADC_voidSelectChannel(u8 LOC_u8Channel);
#endif /* ADC_INTERFACE_H_ */
