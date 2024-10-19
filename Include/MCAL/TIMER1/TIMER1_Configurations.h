/*
 * TIMER1_Configurations.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_CONFIGURATIONS_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_CONFIGURATIONS_H_




/*COMPARE MODES  ON NORMAL_MODE :-
 * 		NORMAL_DIO
 * 		TOGGLE_PIN
 * 		CLEAR_PIN
 * 		SET_PIN
 * COMPARE MODES  ON PWM:-
 * 		NORMAL_DIO
 * 		NON_INVERTING
 * 		INVERTING
 */
#define COM1A_MODE	NON_INVERTING
#define COM1B_MODE	TOGGLE_PIN


/*
		Mode of Operation						TOP		Update of OCR1x		TOV1 Flag Set on
 0b0000 	Normal 								0xFFFF		 Immediate		 MAX
 0b0001 	PWM	Phase Correct 8-bit 			0x00FF 			TOP 		BOTTOM
 0b0010 	PWM Phase Correct 9-bit				0x01FF 			TOP 		BOTTOM
 0b0011 	PWM Phase Correct 10-bit			0x03FF			TOP 		BOTTOM
 0b0100		CTC 								OCR1A		 Immediate		 MAX
 0b0101 	Fast PWM 8-bit						0x00FF			TOP 		 TOP
 0b0110 	Fast PWM 9-bit 						0x01FF 			TOP 		 TOP
 0b0111 	Fast PWM 10-bit 					0x03FF 			TOP 		 TOP
 0b1000 	PWM Phase and Frequency Correct 	ICR1		  BOTTOM 		BOTTOM
 0b1001 	PWM Phase and Frequency Correct 	OCR1A 		  BOTTOM 		BOTTOM
 0b1010 	PWM Phase Correct 					ICR1 			TOP 		BOTTOM
 0b1011 	PWM Phase Correct 					OCR1A 			TOP 		BOTTOM
 0b1100 	CTC 								ICR1 		 Immediate 		 MAX
 0b1101 	Reserved 							 � 				� 			  �
 0b1110 	Fast PWM 							ICR1 			TOP 		 TOP
 0b1111 	Fast PWM 							OCR1A 			TOP 		 TOP
 */
#define TIMER1_MODE		0b0101

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

#define OC1A_VALUE		0
#define OC1B_VALUE		0
#define ICR1_VALUE 		0
#define INPUT_CAPUTRE_INTERRUPT_ENABLE		0
#define OUTPUT_COMPARE_A_INTERRUPT_ENABLE	0
#define OUTPUT_COMPARE_B_INTERRUPT_ENABLE	0
#define OVER_FLOW_INTERRUPT_ENABLE			1
#endif /* INCLUDE_MCAL_TIMER1_TIMER1_CONFIGURATIONS_H_ */
