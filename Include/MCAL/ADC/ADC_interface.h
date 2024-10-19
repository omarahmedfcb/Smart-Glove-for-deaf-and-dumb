/*
 * ADC_interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_


#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

void MADC_voidInit (void);
void MADC_voidInterruptEnable(void);
u16 MADC_u16GetDigitalValue (u8 A_u8Channel);
void MADC_voidSetToCallback(void (*ptrToFunc)(void));
void MADC_voidStartConversion(u8 A_u8Channel);
u16 MADC_u16GetDigitalValueTrigger (void);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
