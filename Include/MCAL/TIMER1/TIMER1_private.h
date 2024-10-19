/*
 * TIMER1_private.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
//Defining Registers
#define TCCR1A	(*(volatile u8 *)0x4f)
#define TCCR1B	(*(volatile u8 *)0x4E)
#define TCNT1	(*(volatile u16 *)0x4c)
#define OCR1A	(*(volatile u16 *)0x4A)
#define OCR1B	(*(volatile u16 *)0x48)
#define ICR1	(*(volatile u16 *)0x46)
#define TIMSK	(*(volatile u8 *)0x59)
#define TIFR	(*(volatile u8 *)0x58)
#define TWO_BIT_MASK	0b11
#define THREE_BIT_MASK	0b111
#define COM1A_B1	6
#define COM1B_B1	4
#define NORMAL_DIO		0b00
#define	NON_INVERTING 	0b10
#define INVERTING		0b11
#define TOGGLE_PIN		0b01
#define CLEAR_PIN		0b10
#define SET_PIN			0b11
#define WGM_B1			0
#define WGM_B3			3
#define CS1_B1			0
#define TICIE1			5
#define OCIE1A			4
#define	OCIE1B			3
#define TOIE1			2
#define ICES1			6
#define ICF1			5

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
