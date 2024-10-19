/*
 * LCD_Configurations.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_
//LCD Mode :-
//		Eight_bit
//		Four_bit
#define LCD_MODE   Eight_bit

#define LCD_DATA_PORT 	 PORTB
#define LCD_CONTROL_PORT PORTC
#define RS_PIN 	PIN2
#define RW_PIN 	PIN3
#define E_PIN 	PIN4

#define CURSOR_DISPLAY		ON
#define CURSOR_BLINK		ON
#define DISPLAY				ON




#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_ */
