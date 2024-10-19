/*
 * LCD_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

void HLCD_voidSendCommand (u8 A_u8Command);
void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidInit (void);
void HLCD_voidClearDisplay (void);
void HLCD_voidSendString (u8 *A_u8Ptr);
void HLCD_voidSendNumber (u32 A_u32Number);
void HLCD_voidGoTo (u8 A_u8Row , u8 A_u8Col);
void HLCD_voidCreateChar (u8 A_u8Address , u8* A_u8Ptr);
void HLCD_voidPattern (u8 A_u8Char , u8 A_u8Start , u8 A_u8End);
void HLCD_voidShifting (u8 A_u8Char , u8 A_u8Position);




#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
