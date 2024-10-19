/*
 * TIMER1_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define FALLINGEDGE			0
#define RISINGEDGE			1
void MTIMER1_voidInit (void);
void MTIMER1_voidSetICR1 (u16 A_u16ICR1Value);
void MTIMER_voidSetOCR1A (u16 A_u16OCR1AValue);
void MTIMER_voidSetEdgeForICU (u8 A_u8Edge);
u16 MTIMER_u16GetICR1Value (void);
void MTIMER1_voidSetCallBackOVF (void (*Ptr_Function)(void));
void MTIMERS_voidTimer1Stop(void);
#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
