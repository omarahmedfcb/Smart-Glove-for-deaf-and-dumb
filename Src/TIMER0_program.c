/*
 * TIMER_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"

void (*TIMER0_OVF_CallBack) (void) = NULL;
void (*TIMER0_CTC_CallBack) (void) = NULL;

void MTIMER0_voidInit (void)
{
#if TIMER0_MODE == NORMAL_MODE
	//Select TIMER0 Mode
	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);
	//Select Compare Match Output Mode
	TCCR0 &= ~(TWO_BIT_MASK<<COM0_B0);
	TCCR0 |= (OC0_MODE<<COM0_B0);
	//Enable TIMER0 Interrupts
	SET_BIT(TIMSK , TOIE0);
	//Clear CLK Bits
	TCCR0 &= ~(THREE_BIT_MASK<<CS_B0);
	//Select CLK Source
	TCCR0 |= (CLK_CONFIG<<CS_B0);
#elif TIMER0_MODE == PHASE_CORRECT_MODE

#elif TIMER0_MODE == CTC_MODE
	//Select TIMER0 Mode
	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
	//Select Compare Match Output Mode
	TCCR0 &= ~(TWO_BIT_MASK<<COM0_B0);
	TCCR0 |= (OC0_MODE<<COM0_B0);
	//Enable CTC Interrupts
	SET_BIT(TIMSK , OCIE0);
	//Clear CLK Bits
	TCCR0 &= ~(THREE_BIT_MASK<<CS_B0);
	//Select CLK Source
	TCCR0 |= (CLK_CONFIG<<CS_B0);
#elif TIMER0_MODE == FAST_PWM_MODE
	//Select TIMER0 Mode
	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
	//Select Compare Match Output Mode
	TCCR0 &= ~(TWO_BIT_MASK<<COM0_B0);
	TCCR0 |= (OC0_MODE_PWM<<COM0_B0);
	OCR0 = OCR0_VALUE;
	//Clear CLK Bits
	TCCR0 &= ~(THREE_BIT_MASK<<CS_B0);
	//Select CLK Source
	TCCR0 |= (CLK_CONFIG<<CS_B0);
#else
	#error  Wrong TIMER0 Mode Configuration
#endif

}

void MTIMER0_voidSetPreLoadValue (u8 A_u8PreLoadValue)
{
	TCNT0 = A_u8PreLoadValue;
}
void MTIMER0_voidSetCallBackOVF (void (*Ptr_Function)(void))
{
	if (Ptr_Function != NULL)
	{
		TIMER0_OVF_CallBack = Ptr_Function;
	}
}
void MTIMER0_voidSetCallBackCTC (void (*Ptr_Function)(void))
{
	if (Ptr_Function != NULL)
	{
		TIMER0_CTC_CallBack = Ptr_Function;
	}
}

void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}

void MTIMER0_voidStopClock (void)
{
	//Clear CLK Bits
	TCCR0 &= ~(THREE_BIT_MASK<<CS_B0);
}

void __vector_11 (void)  __attribute__ ((signal));
void __vector_11 (void)
{
	if (TIMER0_OVF_CallBack!= NULL)
	{
		TIMER0_OVF_CallBack();
	}
}

void __vector_10 (void)  __attribute__ ((signal));
void __vector_10 (void)
{
	if (TIMER0_CTC_CallBack!= NULL)
	{
		TIMER0_CTC_CallBack();
	}
}


