/*
 * LCD_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#include <util/delay.h>
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"

#include "..\Include\MCAL\DIO\DIO_Interface.h"
#include "..\Include\MCAL\DIO\DIO_private.h"
#include "..\Include\MCAL\DIO\DIO_Configurations.h"

#include "..\Include\HAL\LCD\LCD_Interface.h"
#include "..\Include\HAL\LCD\LCD_private.h"
#include "..\Include\HAL\LCD\LCD_Configurations.h"

#define DISPLAY_ON_OFF_CONTROL		 CONC_BIT(0,0,0,0,1,DISPLAY,CURSOR_DISPLAY,CURSOR_BLINK)
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET 0b00000010
#if (LCD_MODE == Eight_bit)
	#define FUNCTION_SET 0b00111000
#elif (LCD_MODE == Four_bit)
	#define FUNCTION_SET 0b00101000
#endif
void HLCD_voidSendCommand (u8 A_u8Command)
{
#if (LCD_MODE == Eight_bit)
	//RS -> LOW
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RS_PIN , PIN_LOW);
	//RW-> LOW
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RW_PIN , PIN_LOW);
	//Send Command
	MDIO_voidSetPortValue(LCD_DATA_PORT , A_u8Command);
	//Send Pulse to LCD With 2ms
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_LOW);
#elif (LCD_MODE == Four_bit)
	//RS -> HIGH
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RS_PIN , PIN_LOW);
	//RW-> LOW
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RW_PIN , PIN_LOW);
	//Send Higher 4-bit of Command
	MDIO_voidSetPortValue(LCD_DATA_PORT , (A_u8Command>>4));
	//Send Pulse to LCD With 2ms
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_LOW);
	MDIO_voidSetPortValue(LCD_DATA_PORT , A_u8Command);
	//Send Pulse to LCD With 2ms
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_LOW);
#endif
}

void HLCD_voidSendData (u8 A_u8Data)
{
#if (LCD_MODE == Eight_bit)
	//RS -> HIGH
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RS_PIN , PIN_HIGH);
	//RW-> LOW
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RW_PIN , PIN_LOW);
	//Send Command
	MDIO_voidSetPortValue(LCD_DATA_PORT , A_u8Data);
	//Send Pulse to LCD With 2ms
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_LOW);
#elif (LCD_MODE == Four_bit)
	//RS -> HIGH
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RS_PIN , PIN_HIGH);
	//RW-> LOW
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , RW_PIN , PIN_LOW);
	//Send Higher 4-bit of Data
	MDIO_voidSetPortValue(LCD_DATA_PORT , (A_u8Data>>4));
	//Send Pulse to LCD With 2ms
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_LOW);
	MDIO_voidSetPortValue(LCD_DATA_PORT , A_u8Data);
	//Send Pulse to LCD With 2ms
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , E_PIN , PIN_LOW);
#endif
}

#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET 0b00000010

void HLCD_voidInit (void)
{
	//wait for more than 30ms
	_delay_ms(30);
	//Send Function Set
#if (LCD_MODE == Four_bit)
	HLCD_voidSendCommand(0b00000010);
#endif
	HLCD_voidSendCommand(FUNCTION_SET);
	//wait for more than 39us
	_delay_ms(1);
	//Send Display On/Off Control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	//wait for more than 39us
	_delay_ms(1);
	//Send Clear Display
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53ms
	_delay_ms(2);
	//Send Entry Mode Set
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}


void HLCD_voidClearDisplay (void)
{
	//Send Clear Display
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53ms
	_delay_ms(2);
}


void HLCD_voidSendString (u8 *A_u8Ptr)
{
	for (int i = 0 ; A_u8Ptr[i]!='\0'; i++)
	{
		HLCD_voidSendData(A_u8Ptr[i]);
	}
}

void HLCD_voidSendNumber (u32 A_u32Number)
{
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	else
	{
		u32 local_u32Number = 1;
		while (A_u32Number!=0)
		{
			local_u32Number = ((local_u32Number*10)+(A_u32Number%10));
			A_u32Number=A_u32Number/10;
		}
		while (local_u32Number!=1)
		{
			HLCD_voidSendData((local_u32Number%10)+48);
			local_u32Number	= local_u32Number/10;
		}
	}
}



void HLCD_voidGoTo (u8 A_u8Row , u8 A_u8Col)
{
	u8 local_u8Address;
	switch (A_u8Row)
	{
	case ROW_ONE :
		local_u8Address = ROW_ONE_ADD + A_u8Col-1;
		break;
	case ROW_TWO :
		local_u8Address = ROW_TWO_ADD + A_u8Col-1;
		break;
	}
	SET_BIT(local_u8Address,PIN7);
	HLCD_voidSendCommand(local_u8Address);
	_delay_ms(1);
}

void HLCD_voidCreateChar (u8 A_u8Number , u8* A_u8Ptr)
{
	A_u8Number *= 8;
	SET_BIT(A_u8Number,PIN6);
	HLCD_voidSendCommand(A_u8Number);
	for (int i = 0 ; i < 8 ; i++)
	{
		HLCD_voidSendData(A_u8Ptr[i]);
	}
	HLCD_voidGoTo(1,1);
}


void HLCD_voidPattern (u8 A_u8Char , u8 A_u8Start , u8 A_u8End)
{
	HLCD_voidGoTo(1,A_u8Start);
	HLCD_voidSendData(A_u8Char);
	_delay_ms(300);
	for (int i = A_u8Start ; i < A_u8End ; i++)
	{
		HLCD_voidGoTo(1,i);
		HLCD_voidSendData(' ');
		HLCD_voidGoTo(1,i+1);
		HLCD_voidSendData(A_u8Char);
		_delay_ms(300);
	}
	HLCD_voidGoTo(1,A_u8End);
	HLCD_voidSendData(' ');
}

