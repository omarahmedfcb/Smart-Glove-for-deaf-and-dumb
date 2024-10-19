/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "..\Include\MCAL\DIO\DIO_Interface.h"
#include "..\Include\MCAL\DIO\DIO_private.h"
#include "..\Include\MCAL\DIO\DIO_Configurations.h"
#include "..\Include\MCAL\GI\GI_Interface.h"
#include "..\Include\MCAL\GI\GI_private.h"
#include "..\Include\MCAL\GI\GI_Configurations.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Configurations.h"
#include "..\Include\HAL\LCD\LCD_Interface.h"
#include "..\Include\HAL\LCD\LCD_private.h"
#include "..\Include\HAL\LCD\LCD_Configurations.h"


#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_private.h"
#include "../Include/MCAL/TWI/TWI_configuration.h"

#include "../Include/HAL/EEPROM/EEPROM_Interface.h"
#include "../Include/HAL/EEPROM/EEPROM_private.h"
#include "../Include/HAL/EEPROM/EEPROM_configuration.h"

#include "../Include/MCAL/ADC/ADC_interface.h"
#include "../Include/MCAL/ADC/ADC_private.h"
#include "../Include/MCAL/ADC/ADC_configuration.h"



//#include "../Include/MCAL/TIMER1/Music.h"
#include "../Include/MCAL/TIMER1/Arrays.h"
#include <avr/pgmspace.h>

void TIMER_voidSetPWM(void);




void main (void)
{
	// local variable to return data in
	u16 digital[5] = { 0, 0, 0, 0, 0 };
	u16 analog[5] = { 0, 0, 0, 0, 0 };

	u8 local_u8Data = 0;

	MDIO_voidInit();
	MGI_voidEnable();
	HLCD_voidInit();
	MADC_voidInit();
	TWI_voidMasterInit(0);
//	HLCD_voidSendNumber((pgm_read_byte(&anengineer[4095])));
//	HLCD_voidSendNumber((pgm_read_byte(&hesham[1023])));
//	_delay_ms(2000);
//(sizeof(anengineer)/sizeof(u8))
//	for ( u16 i = finelen ; i < heshamlen ; i++)
//	{
//		EEPROM32_voidSendDataByte(i,(pgm_read_byte(&hesham[count++])));
//	}

//	MDIO_voidSetPinValue(PORT_A, PIN2, PIN_HIGH);


//	EEPROM_voidSendDataByte(3, 8);
//			EEPROM_voidSendDataByte(4, 26);
//
//	MDIO_voidSetPinValue(PORT_A, PIN7, PIN_HIGH);
//				local_u8Data = EEPROM32_u8ReadDataByte(finelen+1023);
//				HLCD_voidSendNumber(local_u8Data);
//
//
//	for (u16 i = finelen; i < heshamlen; i++)
//	{
//		EEPROM32_voidSendDataByte(i, (pgm_read_byte(&hesham[count++])));
//	}
//	MDIO_voidSetPinValue(PORT_A, PIN6, PIN_HIGH);
//					local_u8Data = (pgm_read_byte(&checkarr[4095]));
//					HLCD_voidSendNumber(local_u8Data);


//				if (local_u8Data==128)
//				{
//					MDIO_voidSetPinValue(PORT_A, PIN5, PIN_HIGH);
//					MDIO_voidSetPinValue(PORT_A, PIN6, PIN_LOW);
//					MDIO_voidSetPinValue(PORT_A, PIN7, PIN_LOW);
//				}
//				else
//				{
//					MDIO_voidSetPinValue(PORT_A, PIN5, PIN_LOW);
//					MDIO_voidSetPinValue(PORT_A, PIN6, PIN_HIGH);
//					MDIO_voidSetPinValue(PORT_A, PIN7, PIN_LOW);
//				}


//	MTIMER0_voidSetCallBackOVF(TIMER_voidSetPWM);
//	MTIMER1_voidInit();
//	MTIMER0_voidInit();







	while (1)
	{
		digital[0] = MADC_u16GetDigitalValue(ADC0);
		analog[0] = (u16) ((digital[0] * 5000UL) / 1024);
		_delay_ms(100);
		digital[1] = MADC_u16GetDigitalValue(ADC1);
		analog[1] = (u16) ((digital[1] * 5000UL) / 1024);
		_delay_ms(100);
		digital[2] = MADC_u16GetDigitalValue(ADC2);
		analog[2] = (u16) ((digital[2] * 5000UL) / 1024);
		_delay_ms(100);
		MADC_voidInit();
		digital[3] = MADC_u16GetDigitalValue(ADC3);
		analog[3] = (u16) ((digital[3] * 5000UL) / 1024);
		_delay_ms(100);
		digital[4] = MADC_u16GetDigitalValue(ADC4);
		analog[4] = (u16) ((digital[4] * 5000UL) / 1024);


		if ((digital[0]<1500 || digital[0]>1400) || (digital[1]<1100 || digital[1]>1000) || (digital[2]<2050 || digital[2]>1950) || (digital[3]<700 || digital[3]>600) || (digital[4]<900 || digital[4]>800))
		{
			MDIO_voidSetPinValue(PORT_A, PIN6, PIN_HIGH);
			MTIMER0_voidSetCallBackOVF(TIMER_voidSetPWM);
			MTIMER1_voidInit();
			MTIMER0_voidInit();

		}
//		HLCD_voidSendNumber(analog[0]);
//			_delay_ms(4000);
//			HLCD_voidClearDisplay();
//			HLCD_voidSendNumber(analog[1]);
//			_delay_ms(4000);
//			HLCD_voidClearDisplay();
//			HLCD_voidSendNumber(analog[2]);
//			_delay_ms(4000);
//			HLCD_voidClearDisplay();
//			HLCD_voidSendNumber(analog[3]);
//			_delay_ms(4000);
//			HLCD_voidClearDisplay();
//			HLCD_voidSendNumber(analog[4]);
//			_delay_ms(4000);
//			HLCD_voidClearDisplay();

	}
}



//void TIMER_voidSetPWM(void)
//{
//	static u16 sample = 0;
//	static u8 counter = 0;
//	counter ++;
//	if (counter == 4)
//	{
//		MTIMER_voidSetOCR1A((pgm_read_byte(&anengineer[sample]))*1);
//		sample ++;
//		counter = 0;
//	}
//	if (sample>=9500)
//	{
//		sample = 0;
//	}
//
//}


//void TIMER_voidSetPWM(void)
//{
//	static u16 sample = 0;
//	static u8 counter = 0;
//	static u8 det=0;
//	counter ++;
//	if (counter == 4)
//	{
//		det= EEPROM32_u8ReadDataByte(sample);
//		MTIMER_voidSetOCR1A((det)*1);
//		sample ++;
//		counter = 0;
//	}
//	if (sample>=anenglen)
//	{
//		sample = 0;
//		MTIMERS_voidTimer1Stop();
//		HLCD_voidSendNumber(25);
//	}
//
//}
