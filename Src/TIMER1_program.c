/*


 * TIMER1_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Configurations.h"
void (*TIMER1_OVF_CallBack) (void) = 0;
void MTIMER_voidSetEdgeForICU (u8 A_u8Edge)
{
	if (A_u8Edge == FALLINGEDGE)
	{
		CLR_BIT(TCCR1B , ICES1);
	}
	else
	{
		SET_BIT(TCCR1B , ICES1);

	}
}

u16 MTIMER_u16GetICR1Value (void)
{
	u16 local_u16ICR1 = ICR1;
	SET_BIT (TIFR , ICF1);
	return local_u16ICR1;
}
void MTIMER1_voidInit (void)
{
	//Clear Compare OutPut Mode Bits
	TCCR1A &= ~(TWO_BIT_MASK<<COM1A_B1);
	TCCR1A &= ~(TWO_BIT_MASK<<COM1B_B1);
	//Select Compare OutPut Mode
	TCCR1A |= (COM1A_MODE<<COM1A_B1);
	TCCR1A |= (COM1B_MODE<<COM1B_B1);
	//Clear Wave Generation Mode First Two Bits
	TCCR1A &= ~(TWO_BIT_MASK<<WGM_B1);
	//Set Wave Generation Mode First Two Bits
	TCCR1A |= ((TIMER1_MODE&TWO_BIT_MASK)<<WGM_B1);
	//Clear Wave Generation Mode Last Two Bits
	TCCR1B &= ~(TWO_BIT_MASK<<WGM_B3);
	//Set Wave Generation Mode Last Two Bits
	TCCR1B |=  ((TIMER1_MODE>>2)<<WGM_B3);
	//Set The Initial Values of OCR1A & OCR1B
	OCR1A = OC1A_VALUE;
	OCR1B = OC1B_VALUE;
	//Set The Initial Value of ICR1
	ICR1 = ICR1_VALUE;
	//Enable Or Disable The Interrupt Flags
#if (INPUT_CAPUTRE_INTERRUPT_ENABLE == 1)
	SET_BIT(TIMSK , TICIE1);
#else
	CLR_BIT(TIMSK , TICIE1);
#endif
#if (OUTPUT_COMPARE_A_INTERRUPT_ENABLE == 1)
	SET_BIT(TIMSK , OCIE1A);
#else
	CLR_BIT(TIMSK , OCIE1A);
#endif
#if (OUTPUT_COMPARE_B_INTERRUPT_ENABLE == 1)
	SET_BIT(TIMSK , OCIE1B);
#else
	CLR_BIT(TIMSK , OCIE1B);
#endif
#if (OVER_FLOW_INTERRUPT_ENABLE == 1)
	SET_BIT(TIMSK , TOIE1);
#else
	CLR_BIT(TIMSK , TOIE1);
#endif
	//Set The Clock OF TIMER1
	TCCR1B &= ~(THREE_BIT_MASK<<CS1_B1);
	TCCR1B |= (CLK_CONFIG<<CS1_B1);
}

void MTIMERS_voidTimer1Stop(void)
{
	CLR_BIT(TCCR1B,2);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}


void MTIMER1_voidSetICR1 (u16 A_u16ICR1Value)
{
	ICR1 = A_u16ICR1Value;
}

void MTIMER_voidSetOCR1A (u16 A_u16OCR1AValue)
{
	OCR1A = A_u16OCR1AValue;
}

void MTIMER1_voidSetCallBackOVF (void (*Ptr_Function)(void))
{
	if (Ptr_Function != 0)
	{
		TIMER1_OVF_CallBack = Ptr_Function;
	}
}

void __vector_9 (void)  __attribute__ ((signal));
void __vector_9 (void)
{
	if (TIMER1_OVF_CallBack!= 0)
	{
		TIMER1_OVF_CallBack();
	}
}
