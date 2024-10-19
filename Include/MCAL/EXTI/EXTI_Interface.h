/*
 * EXTI_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_

void MEXTI_voidConfig (u8 A_u8EXTI , u8 A_u8SenseMode);
void MEXTI_voidEnable (u8 A_u8EXTI);
void MEXTI_voidDisable (u8 A_u8EXTI);
void MEXTI_voidClearFlag (u8 A_u8EXTI);
void MEXTI_voidSetCallBack (u8 A_u8EXTI ,void (*PtrToFunction) (void));

#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
