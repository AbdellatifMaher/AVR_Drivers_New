/*
 * Timer1_interface.h
 *
 *  Created on: Mar 27, 2021
 *      Author: 8
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


/*
 * TIMER1 MODES
 */

#define TIMER1_NORMAL_MODE					0
#define TIMER1_PWM_PHASE_8_BIT_MODE			1
#define TIMER1_PWM_PHASE_9_BIT_MODE			2
#define TIMER1_PWM_PHASE_10_BIT_MODE		3
#define TIMER1_CTC_OCR1A_MODE				4
#define TIMER1_FAST_PWM_8_BIT_MODE			5
#define TIMER1_FAST_PWM_9_BIT_MODE			6
#define TIMER1_FAST_PWM_10_BIT_MODE			7
#define TIMER1_PWM_FREQUENCY_ICR1_MODE		8
#define TIMER1_PWM_FREQUENCY_OCR1A_MODE		9
#define TIMER1_PWM_PHASE_ICR1_MODE			10
#define TIMER1_PWM_PHASE_OCR1A_MODE			11
#define TIMER1_CTC_ICR1_MODE				12
#define TIMER1_FAST_PWM_ICR1_MODE			14
#define TIMER1_FAST_PWM_OCR1A_MODE			15


/*
 * TIMER1 COMPARE MATCH OUTPUT MODE
 */
#define TIMER1_DISCONNECTED_OC1  0
#define TIMER1_TOGGLE_OC1        1
#define TIMER1_CLEAR_OC1         2
#define TIMER1_SET_OC1           3

/*
 * TIMER1 PreScaller
 */

#define TIMER1_NO_CLOCK       0
#define TIMER1_NO_PRE         1
#define TIMER1_8_PRE          2
#define TIMER1_64_PRE         3
#define TIMER1_256_PRE        4
#define TIMER1_1024_PRE       5
#define TIMER1_EXT_FALLING    6
#define TIMER1_EXT_RISING     7

/*
 * TIMER1 INTERRUPT
 */

#define TIMER1_INT_DISABLE               0
#define TIMER1_INT_OVERFLOW              1
#define TIMER1_INT_COMP_B_MATCH          2
#define TIMER1_INT_COMP_A_MATCH          4
#define TIMER1_INT_COMP_BOTH_MATCH       6
#define TIMER1_INT_INPUT_CAPTURE         8
#define TIMER1_INT_OVF_IC_BOTH           9

#define INPUT_CAPTURE_FALLING_EDGE  0
#define INPUT_CAPTURE_RISING_EDGE   1

void TIMER1_voidInit(void);
void TIMER1_voidSetOCRA(u16 Copy_u16OCR);
void TIMER1_voidSetOCRB(u16 Copy_u16OCR);
void TIMER1_voidSetICR1(u32 Copy_u32ICR);
u16  TIMER1_u16GetICR1(void);
void TIMER1_voidChangeEdge(u8 Copy_u8Edge);
void TIMER1_voidClearFlag(u8 Copy_u8Interrupt);
u8   TIMER1_u8GetFlag(u8 Copy_u8Interrupt);
void TIMER1_voidDisableInterrupt(void);
void TIMER1_voidEnableInterrupt(u8 Copy_u8Interrupt);
void TIMER1_voidPWM(u16 Copy_u16OCRON,u8 Copy_u8Channel);
void TIMER1_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt );

#endif /* TIMER1_INTERFACE_H_ */
