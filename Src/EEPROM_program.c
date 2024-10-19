/*
 * EEPROM_program.c
 *
 *  Created on: ???/???/????
 *      Author: Omar Mohamed
 */


#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_configurations.h"



#include "../Include/HAL/EEPROM/EEPROM_Interface.h"
#include "../Include/HAL/EEPROM/EEPROM_private.h"
#include "../Include/HAL/EEPROM/EEPROM_configuration.h"

#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_private.h"
#include "../Include/MCAL/TWI/TWI_configuration.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../Include/HAL/LCD/LCD_Configurations.h"

#include <util/delay.h>


void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 local_u8DataPacket;
	local_u8DataPacket=EEPROM_FIXED_ADDRESS | (A2_CONNECTION<<2) | (u8)(Copy_u16LocationAddress>>8);
	//send start condition
	TWI_u8SendStartCondition();
	//send slave address with write operation
	TWI_u8SendSlaveAddressWithWrite(local_u8DataPacket);
	//send the rest of the byte
	TWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16LocationAddress);
	//send data
	TWI_ErrorStatusMasterWriteDataByte(Copy_u8DataByte);
	//send stop condition
	TWI_voidSendStopCondition();
	_delay_ms(10);
}

void EEPROM32_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 local_u8DataPacket;
	local_u8DataPacket=EEPROM_FIXED_ADDRESS | (A1_CONNECTION<<2) | (A0_CONNECTION<<1);
	//send start condition
	TWI_u8SendStartCondition();
	//send slave address with write operation
	TWI_u8SendSlaveAddressWithWrite(local_u8DataPacket);
	//send the MSB of the address byte
	TWI_ErrorStatusMasterWriteDataByte((u8)(Copy_u16LocationAddress>>8));
	//send the LSB of the address byte
	TWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16LocationAddress);
	//send data
	TWI_ErrorStatusMasterWriteDataByte(Copy_u8DataByte);
	//send stop condition
	TWI_voidSendStopCondition();
	_delay_ms(10);
}


u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress)
{
	u8 local_u8Data;
	u8 local_u8DataPacket;
	local_u8DataPacket=EEPROM_FIXED_ADDRESS | (A2_CONNECTION<<2) | (u8)(Copy_u16LocationAddress>>8);
	//send start condition
	TWI_u8SendStartCondition();
	//send slave address with write operation
	TWI_u8SendSlaveAddressWithWrite(local_u8DataPacket);
	//send the rest of the byte
	TWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16LocationAddress);
	//send repeated start condition
	TWI_u8SendReStartCondition();
	//send slave address with read operation
	TWI_u8SendSlaveAddressWithRead(local_u8DataPacket);
	/*Get the data from memory*/
	TWI_ErrorStatusMasterReadDataByte(&local_u8Data);
	/*send the stop condition*/
	TWI_voidSendStopCondition();

	return local_u8Data;
}

u8 EEPROM32_u8ReadDataByte(u16 Copy_u16LocationAddress)
{
	u8 local_u8Data;
	u8 local_u8DataPacket;
	local_u8DataPacket=EEPROM_FIXED_ADDRESS | (A1_CONNECTION<<2) | (A0_CONNECTION<<1);
	//send start condition
	TWI_u8SendStartCondition();
	//send slave address with write operation
	TWI_u8SendSlaveAddressWithWrite(local_u8DataPacket);
	//send the MSB of the address byte
	TWI_ErrorStatusMasterWriteDataByte((u8)(Copy_u16LocationAddress>>8));
	//send the LSB of the address byte
	TWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16LocationAddress);
	//send repeated start condition
	TWI_u8SendReStartCondition();
	//send slave address with read operation
	TWI_u8SendSlaveAddressWithRead(local_u8DataPacket);
	/*Get the data from memory*/
	TWI_ErrorStatusMasterReadDataByte(&local_u8Data);
	/*send the stop condition*/
	TWI_voidSendStopCondition();

	return local_u8Data;
}

