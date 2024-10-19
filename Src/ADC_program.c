/*
 * ADC_program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: abdelrahmanhossam
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_configurations.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../Include/HAL/LCD/LCD_Configurations.h"

#include "../Include/MCAL/ADC/ADC_interface.h"
#include "../Include/MCAL/ADC/ADC_private.h"
#include "../Include/MCAL/ADC/ADC_configuration.h"


#include <util/delay.h>
#define NULL 0
void (*ADC_CallBack) (void)=NULL;
//u16 digital =0;
  //  u16 analog=0;
void MADC_voidInit (void)
{
//	1- Select Vref = Avcc
//	2- Right Adjustment
//	3- Disable Auto Trigger
//	4- Select CLK/64
//	5- Enable ADC

	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	CLR_BIT(ADMUX,5);

	CLR_BIT(ADCSRA,5);

	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	SET_BIT(ADCSRA,7);
}

u16 MADC_u16GetDigitalValue (u8 A_u8Channel)
{
	u16 local_u16DigitalValue=0;
	if (A_u8Channel<32)
	{
		// clear the channel 5-bits
		ADMUX &= 0b11100000;
		// Select channel
		ADMUX |= A_u8Channel;
		// start Conversion
		SET_BIT(ADCSRA,6);
		// Polling on ADC Complete Flag
		while (GET_BIT(ADCSRA,4)==0);
		// Clear INT Flag
		SET_BIT(ADCSRA,4);
		// Read Conversion value
		local_u16DigitalValue = ADCLH;
	}
	return local_u16DigitalValue;
}

void MADC_voidStartConversion(u8 A_u8Channel)
{
	if (A_u8Channel<32)
		{
			// clear the channel 5-bits
			ADMUX &= 0b11100000;
			// Select channel
			ADMUX |= A_u8Channel;
			// start Conversion
			SET_BIT(ADCSRA,6);
		}
}

u16 MADC_u16GetDigitalValueTrigger (void)
{

	return ADCLH;
}


void MADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA,3);
	SET_BIT(ADCSRA,5);
// AUTO TRIGGER
	CLR_BIT(SFIOR,4);
	CLR_BIT(SFIOR,5);
	CLR_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);
}

void MADC_voidSetToCallback(void (*ptrToFunc)(void))
{
	if (ptrToFunc!=NULL)
	{
		ADC_CallBack=ptrToFunc;
	}
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if (ADC_CallBack != NULL)
	{
		ADC_CallBack();
	}
//	digital = MADC_u16GetDigitalValue(ADC0);
//				analog = (u16) ((digital * 5000UL) / 1024);
//
//				if (analog <= 1500) {
//					MDIO_voidSetPinValue(PORTA, PIN1, PIN_HIGH);
//					MDIO_voidSetPinValue(PORTA, PIN2, PIN_LOW);
//					MDIO_voidSetPinValue(PORTA, PIN3, PIN_LOW);
//				} else if (analog > 1500 && analog <= 3000) {
//					MDIO_voidSetPinValue(PORTA, PIN1, PIN_HIGH);
//					MDIO_voidSetPinValue(PORTA, PIN2, PIN_HIGH);
//					MDIO_voidSetPinValue(PORTA, PIN3, PIN_LOW);
//				} else if (analog > 3000) {
//					MDIO_voidSetPinValue(PORTA, PIN1, PIN_HIGH);
//					MDIO_voidSetPinValue(PORTA, PIN2, PIN_HIGH);
//					MDIO_voidSetPinValue(PORTA, PIN3, PIN_HIGH);
//				}
//
//				HLCD_voidDisplayNumber(analog);
//				_delay_ms(5000);
//				HLCD_voidClearDisplay();
}
