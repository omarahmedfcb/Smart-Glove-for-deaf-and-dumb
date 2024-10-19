/*
 * DIO_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
void MDIO_voidInit(void);
void MDIO_voidSetPinDirection (u8 A_u8PortId , u8 A_u8PinId , u8 A_u8Direction);
void MDIO_voidSetPinValue (u8 A_u8PortId , u8 A_u8PinId , u8 A_u8Value);
u8 MDIO_u8GetPinValue (u8 A_u8PortId , u8 A_u8PinId);
void MDIO_voidSetPortValue (u8 A_u8PortId , u8 A_u8PortValue);
void MDIO_voidSetPortDirection (u8 A_u8PortId , u8 A_u8PortDirection);


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
