/*
 * program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "..\Include\MCAL\DIO\DIO_Interface.h"
#include "..\Include\MCAL\DIO\DIO_private.h"
#include "..\Include\MCAL\DIO\DIO_Configurations.h"
void MDIO_voidInit(void)
{
	DDRA_REG = CONC_BIT(PORTA_PIN7_DIRECTION,PORTA_PIN6_DIRECTION,PORTA_PIN5_DIRECTION,PORTA_PIN4_DIRECTION,PORTA_PIN3_DIRECTION,PORTA_PIN2_DIRECTION,PORTA_PIN1_DIRECTION,PORTA_PIN0_DIRECTION);
	DDRB_REG = CONC_BIT(PORTB_PIN7_DIRECTION,PORTB_PIN6_DIRECTION,PORTB_PIN5_DIRECTION,PORTB_PIN4_DIRECTION,PORTB_PIN3_DIRECTION,PORTB_PIN2_DIRECTION,PORTB_PIN1_DIRECTION,PORTB_PIN0_DIRECTION);
	DDRC_REG = CONC_BIT(PORTC_PIN7_DIRECTION,PORTC_PIN6_DIRECTION,PORTC_PIN5_DIRECTION,PORTC_PIN4_DIRECTION,PORTC_PIN3_DIRECTION,PORTC_PIN2_DIRECTION,PORTC_PIN1_DIRECTION,PORTC_PIN0_DIRECTION);
	DDRD_REG = CONC_BIT(PORTD_PIN7_DIRECTION,PORTD_PIN6_DIRECTION,PORTD_PIN5_DIRECTION,PORTD_PIN4_DIRECTION,PORTD_PIN3_DIRECTION,PORTD_PIN2_DIRECTION,PORTD_PIN1_DIRECTION,PORTD_PIN0_DIRECTION);
	PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE,PORTA_PIN6_VALUE,PORTA_PIN5_VALUE,PORTA_PIN4_VALUE,PORTA_PIN3_VALUE,PORTA_PIN2_VALUE,PORTA_PIN1_VALUE,PORTA_PIN0_VALUE);
	PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE,PORTB_PIN6_VALUE,PORTB_PIN5_VALUE,PORTB_PIN4_VALUE,PORTB_PIN3_VALUE,PORTB_PIN2_VALUE,PORTB_PIN1_VALUE,PORTB_PIN0_VALUE);
	PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE,PORTC_PIN6_VALUE,PORTC_PIN5_VALUE,PORTC_PIN4_VALUE,PORTC_PIN3_VALUE,PORTC_PIN2_VALUE,PORTC_PIN1_VALUE,PORTC_PIN0_VALUE);
	PORTD_REG = CONC_BIT(PORTD_PIN7_VALUE,PORTD_PIN6_VALUE,PORTD_PIN5_VALUE,PORTD_PIN4_VALUE,PORTD_PIN3_VALUE,PORTD_PIN2_VALUE,PORTD_PIN1_VALUE,PORTD_PIN0_VALUE);
}

//PortId :- PORTA - PORTB - PORTC - PORTD
//PinId  :- PIN0 ... PIN7
//Value  :- PIN_HIGH - PIN_LOW

void MDIO_voidSetPinValue (u8 A_u8PortId , u8 A_u8PinId , u8 A_u8Value)
{
	switch (A_u8PortId)
	{
	case PORTA :
		switch (A_u8Value)
		{
		case PIN_HIGH :
			SET_BIT (PORTA_REG,A_u8PinId);
			break;
		case PIN_LOW :
			CLR_BIT (PORTA_REG,A_u8PinId);
			break;
		}
		break;
	case PORTB :
		switch (A_u8Value)
		{
		case PIN_HIGH :
			SET_BIT (PORTB_REG,A_u8PinId);
			break;
		case PIN_LOW :
			CLR_BIT (PORTB_REG,A_u8PinId);
			break;
		}
		break;
	case PORTC :
		switch (A_u8Value)
		{
		case PIN_HIGH :
			SET_BIT (PORTC_REG,A_u8PinId);
			break;
		case PIN_LOW :
			CLR_BIT (PORTC_REG,A_u8PinId);
			break;
		}
		break;
	case PORTD :
		switch (A_u8Value)
		{
		case PIN_HIGH :
			SET_BIT (PORTD_REG,A_u8PinId);
			break;
		case PIN_LOW :
			CLR_BIT (PORTD_REG,A_u8PinId);
			break;
		}
		break;
	}
}

//PortId :- PORTA - PORTB - PORTC - PORTD
//PinId  :- PIN0 ... PIN7
//Value  :- OUTPUT_PIN - INPUT_PIN
void MDIO_voidSetPinDirection (u8 A_u8PortId , u8 A_u8PinId , u8 A_u8Direction)
{
	switch (A_u8PortId)
	{
	case PORTA :
		switch (A_u8Direction)
		{
		case OUTPUT_PIN :
			SET_BIT (DDRA_REG,A_u8PinId);
			break;
		case INPUT_PIN :
			CLR_BIT (DDRA_REG,A_u8PinId);
			break;
		}
		break;
	case PORTB :
		switch (A_u8Direction)
		{
		case OUTPUT_PIN :
			SET_BIT (DDRB_REG,A_u8PinId);
			break;
		case INPUT_PIN :
			CLR_BIT (DDRB_REG,A_u8PinId);
			break;
		}
		break;
	case PORTC :
		switch (A_u8Direction)
		{
		case OUTPUT_PIN :
			SET_BIT (DDRC_REG,A_u8PinId);
			break;
		case INPUT_PIN :
			CLR_BIT (DDRC_REG,A_u8PinId);
			break;
		}
		break;
	case PORTD :
		switch (A_u8Direction)
		{
		case OUTPUT_PIN :
			SET_BIT (DDRD_REG,A_u8PinId);
			break;
		case INPUT_PIN :
			CLR_BIT (DDRD_REG,A_u8PinId);
			break;
		}
		break;
	}
}

//PortId :- PORTA - PORTB - PORTC - PORTD
//PinId  :- PIN0 ... PIN7
u8 MDIO_u8GetPinValue (u8 A_u8PortId , u8 A_u8PinId)
{
	u8 local_u8PinValue = 0;
	switch (A_u8PortId)
	{
	case PORTA :
		local_u8PinValue = GET_BIT (PINA_REG , A_u8PinId);
		break;
	case PORTB :
		local_u8PinValue = GET_BIT (PINB_REG , A_u8PinId);
		break;
	case PORTC :
		local_u8PinValue = GET_BIT (PINC_REG , A_u8PinId);
		break;
	case PORTD :
		local_u8PinValue = GET_BIT (PIND_REG , A_u8PinId);
		break;
	}
	return local_u8PinValue;
}

//PortId :- PORTA - PORTB - PORTC - PORTD
//PortValue :- u8
void MDIO_voidSetPortValue (u8 A_u8PortId , u8 A_u8PortValue)
{
	switch (A_u8PortId)
	{
	case PORTA :
		PORTA_REG = A_u8PortValue;
		break;
	case PORTB :
		PORTB_REG = A_u8PortValue;
		break;
	case PORTC :
		PORTC_REG = A_u8PortValue;
		break;
	case PORTD :
		PORTD_REG = A_u8PortValue;
		break;
	}
}


void MDIO_voidSetPortDirection (u8 A_u8PortId , u8 A_u8PortDirection)
{
	switch (A_u8PortId)
	{
	case PORTA :
		DDRA_REG = A_u8PortDirection;
		break;
	case PORTB :
		DDRB_REG = A_u8PortDirection;
		break;
	case PORTC :
		DDRC_REG = A_u8PortDirection;
		break;
	case PORTD :
		DDRD_REG = A_u8PortDirection;
		break;
	}
}
