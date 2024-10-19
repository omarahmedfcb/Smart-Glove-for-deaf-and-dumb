/*
 * TIMER_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_


void MTIMER0_voidInit (void);
void MTIMER0_voidSetPreLoadValue (u8 A_u8PreLoadValue);
void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value);
void MTIMER0_voidSetCallBackOVF (void (*Ptr_Function)(void));
void MTIMER0_voidSetCallBackCTC (void (*Ptr_Function)(void));
void MTIMER0_voidStopClock (void);
#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
