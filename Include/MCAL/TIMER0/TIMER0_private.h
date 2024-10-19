/*
 * TIMER_private.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCCR0	(*(volatile u8 *)0x53)
#define	TCNT0	(*(volatile u8 *)0x52)
#define OCR0	(*(volatile u8 *)0x5c)
#define TIMSK	(*(volatile u8 *)0x59)
#define TIFR	(*(volatile u8 *)0x58)

#define WDTCR 	(*(volatile u8 *)0x41)
#define WGM00	3
#define WGM01	6
#define CS_B0	0
#define TOIE0	0
#define OCIE0	1
#define TWO_BIT_MASK	0b11
#define THREE_BIT_MASK	0b111
#define NULL 	0

#define COM0_B0		4

#define NORMAL_MODE        0
#define PHASE_CORRECT_MODE 1
#define CTC_MODE           2
#define FAST_PWM_MODE      3


#define NORMAL_PIN	0b00
#define TOGGLE_PIN	0b01
#define CLEAR_PIN	0b10
#define SET_PIN		0b11



#define NORMAL_DIO		0b00
#define NON_INVERTING	0b10
#define INVERTING		0b11


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
