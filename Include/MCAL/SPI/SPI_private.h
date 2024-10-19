/*
 * SPI_private.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRIVATE_H_
#define INCLUDE_MCAL_SPI_SPI_PRIVATE_H_

#define SPCR				(*(volatile u8 *)0x2D)
#define SPSR				(*(volatile u8 *)0x2E)
#define SPDR				(*(volatile u8 *)0x2F)

#define ON						1
#define OFF						0
#define	LSB_FIRST				1
#define MSB_FIRST				0
#define RISING_THEN_FALLING		0
#define FALLING_THEN_RISING		1
#define SAMPLE_THEN_SETUP		0
#define SETUP_THEN_SAMPLE		1
#define CLK_RATE_B1				0
#define SPI2X					0
#define SPIF					7
#define NO_DATA 				255
#define MASTER					1
#define SLAVE					0
#define SPI_ENABLE				6
#endif /* INCLUDE_MCAL_SPI_SPI_PRIVATE_H_ */
