/*
 * EXTI_private.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCR 	(*(volatile u8 *)0x55)
#define MCUCSR  (*(volatile u8 *)0x54)

#define GICR 	(*(volatile u8 *)0x5B)
#define GIFR 	(*(volatile u8 *)0x5A)

#define EXTI0  0
#define EXTI1  1
#define EXTI2  2
#define EXTI0_B1 0
#define EXTI1_B1 2
#define EXTI2_B1 6

#define TWO_BITS_MASK 0b11

#define LOW_LEVEL 0b00
#define ANY_LOGICAL_CHANGE 0b01
#define FALLING_EDGE 0b10
#define RISING_EDGE 0b11

#define EXTI0_ENABLE 6
#define EXTI1_ENABLE 7
#define EXTI2_ENABLE 5

#define EXTI0_FLAG 6
#define EXTI1_FLAG 7
#define EXTI2_FLAG 5

#define NULL 0
#endif /* INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_ */
