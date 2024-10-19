/*
 * SPI_Configurations.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_SPI_SPI_CONFIGURATIONS_H_
#define INCLUDE_MCAL_SPI_SPI_CONFIGURATIONS_H_

#define OPERATING_MODE				MASTER
/*
 * Operating Modes :-
 * 		MASTER
 * 		SLAVE
 */

#define SPI_INTERRUPT_ENABLE		OFF
/*
 * SPI_INTERRUPT_ENABLE:-
 * 		ON
 * 		OFF
 */
#define DATA_ORDER					MSB_FIRST
/*
 * DATA_ORDER:-
 * 		LSB_FIRST
 * 		MSB_FIRST
 */
#define CLK_POLARIZATION			RISING_THEN_FALLING
/*
 * CLK_POLARIZATION:-
 * 		RISING_THEN_FALLING
 * 		FALLING_THEN_RISING
 */
#define CLK_PHASE					SAMPLE_THEN_SETUP
/*
 * CLK_PHASE:-
 * 		SAMPLE_THEN_SETUP
 * 		SETUP_THEN_SAMPLE
 */
#define CLK_RATE					0b00
/*
 * CLK_RATE:-
 * 		NO_DOUBLE_SPEED :-
 * 			0b00		F/4
 * 			0b01		F/16
 * 			0b10		F/64
 * 			0b11		F/128
 * 		DOUBLE_SPEED :-
 * 			0b00		F/2
 * 			0b01		F/8
 * 			0b10		F/32
 * 			0b11		F/64
 */
#define DOUBLE_SPEED				OFF
/*
 * DOUBLE_SPEED:-
 * 		ON
 * 		OFF
 */

#endif /* INCLUDE_MCAL_SPI_SPI_CONFIGURATIONS_H_ */
