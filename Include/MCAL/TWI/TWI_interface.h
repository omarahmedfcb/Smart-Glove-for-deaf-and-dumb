/*
 * TWI_interface.h
 *
 *  Created on: ???/???/????
 *      Author: Omar Mohamed
 */

#ifndef INCLUDE_MCAL_TWI_TWI_INTERFACE_H_
#define INCLUDE_MCAL_TWI_TWI_INTERFACE_H_

typedef enum
{
	TWI_OK =1,
	TWI_NOK,
	TWI_SC_ERROR,
	TWI_RSC_ERROR,
	TWI_SLA_W_ERROR,
	TWI_SLA_R_ERROR,
	TWI_MT_DATA_ERROR,
	TWI_MR_DATA_ERROR,
	TWI_NULL_POINTER,
}TWI_ErrorStatus;

void TWI_voidMasterInit(u8 copy_u8Address);
void TWI_voidSlaveInit(u8 A_u8Address);
TWI_ErrorStatus TWI_u8SendStartCondition(void);
TWI_ErrorStatus TWI_u8SendReStartCondition (void);
TWI_ErrorStatus TWI_u8SendSlaveAddressWithWrite(u8 A_u8SlaveAddress);
TWI_ErrorStatus TWI_u8SendSlaveAddressWithRead(u8 A_u8SlaveAddress);
TWI_ErrorStatus TWI_ErrorStatusMasterWriteDataByte(u8 Copy_u8DataByte);
TWI_ErrorStatus TWI_ErrorStatusMasterReadDataByte(u8 * Copy_pu8ReceivedByte);
void TWI_voidSendStopCondition(void);

#endif /* INCLUDE_MCAL_TWI_TWI_INTERFACE_H_ */
