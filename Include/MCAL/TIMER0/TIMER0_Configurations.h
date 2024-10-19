/*
 * TIMER_Configurations.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATIONS_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATIONS_H_

/* Timer Modes :-
 * 		NORMAL_MODE
 * 		PHASE_CORRECT_MODE
 * 		CTC_MODE
 * 		FAST_PWM_MODE
 */
#define TIMER0_MODE NORMAL_MODE

/*
 * 0b000  No clock source (Timer/Counter stopped).
 * 0b001  clkI/O /(No prescaling)
 * 0b010  clkI/O /8 (From prescaler)
 * 0b011  clkI/O /64 (From prescaler)
 * 0b100  clkI/O /256 (From prescaler)
 * 0b101  clkI/O /1024 (From prescaler)
 * 0b110  External clock source on T0 pin. Clock on falling edge.
 * 0b111  External clock source on T0 pin. Clock on rising edge.
 * */
#define CLK_CONFIG	0b001
/*
 * 		NORMAL_PIN
 * 		TOGGLE_PIN
 * 		CLEAR_PIN
 * 		SET_PIN
 */
#define OC0_MODE	NORMAL_PIN


/*
 *		NORMAL_DIO
 *		NON_INVERTING
 *		INVERTING
 */

#define OC0_MODE_PWM	NON_INVERTING

#define OCR0_VALUE		0


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATIONS_H_ */
