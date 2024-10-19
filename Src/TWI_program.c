/*
 * TWI_program.c
 *
 *  Created on: ???/???/????
 *      Author: Omar Mohamed
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_configurations.h"

#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_private.h"
#include "../Include/MCAL/TWI/TWI_configuration.h"


void TWI_voidMasterInit(u8 copy_u8Address)
{
	//set acknowledge bit
	SET_BIT(TWCR,TWCR_TWEA);
	//set frequency
	TWBR=12;
	//set prescaler
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	if (copy_u8Address==0)
	{
		//do nothing
	}
	else
	{
		TWAR=(copy_u8Address<<1);
	}

	//Enable TWI
	SET_BIT(TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 A_u8Address)
{
	//Set Address
	TWAR=(A_u8Address<<1);
	//set acknowledge bit
	SET_BIT(TWCR,TWCR_TWEA);
	//Enable TWI
	SET_BIT(TWCR,TWCR_TWEN);
}


TWI_ErrorStatus TWI_u8SendStartCondition(void)
{
	TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	//send start condition bit
	SET_BIT(TWCR,TWCR_TWSTA);
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR & STATUS_BIT_MASK)!=START_ACK)
	{
		local_ErrorStatus=TWI_SC_ERROR;
	}
	else
	{

	}
	return local_ErrorStatus;
}

TWI_ErrorStatus TWI_u8SendReStartCondition(void)
{
	TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	//send start condition bit
	SET_BIT(TWCR,TWCR_TWSTA);
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR & STATUS_BIT_MASK)!=REP_START_ACK)
	{
		local_ErrorStatus=TWI_RSC_ERROR;
	}
	else
	{

	}
	return local_ErrorStatus;
}

TWI_ErrorStatus TWI_u8SendSlaveAddressWithWrite(u8 A_u8SlaveAddress)
{
	TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	//send slave address
	TWDR=A_u8SlaveAddress<<1;
	//set write operation
	CLR_BIT(TWDR,TWDR_TWD0);
	//clear start condition bit
	CLR_BIT(TWCR,TWCR_TWSTA);
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR & STATUS_BIT_MASK)!=SLAVE_ADD_AND_WR_ACK )
	{
		local_ErrorStatus=TWI_SLA_W_ERROR;
	}

	return local_ErrorStatus;
}

TWI_ErrorStatus TWI_u8SendSlaveAddressWithRead(u8 A_u8SlaveAddress)
{
	TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	//send slave address
	TWDR=A_u8SlaveAddress<<1;
	//set read operation
	SET_BIT(TWDR,TWDR_TWD0);
	//clear start condition bit
	CLR_BIT(TWCR,TWCR_TWSTA);
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR & STATUS_BIT_MASK)!=SLAVE_ADD_AND_RD_ACK )
	{
		local_ErrorStatus=TWI_SLA_R_ERROR;
	}

	return local_ErrorStatus;
}

TWI_ErrorStatus TWI_ErrorStatusMasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	TWDR=Copy_u8DataByte;
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR & STATUS_BIT_MASK)!=MSTR_WR_BYTE_ACK )
	{
		local_ErrorStatus=TWI_MT_DATA_ERROR;;
	}
	return local_ErrorStatus;
}

TWI_ErrorStatus TWI_ErrorStatusMasterReadDataByte(u8 * Copy_pu8ReceivedByte)
{
	TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);
	while (GET_BIT(TWCR,TWCR_TWINT)==0);

	if ((TWSR & STATUS_BIT_MASK)!=MSTR_RD_BYTE_WITH_ACK)
	{
		local_ErrorStatus=TWI_MR_DATA_ERROR;;
	}
	else
	{
		*Copy_pu8ReceivedByte=TWDR;
	}
	return local_ErrorStatus;
}

/*TWI_ErrorStatus local_ErrorStatus=TWI_OK;
	return local_ErrorStatus;*/
void TWI_voidSendStopCondition(void)
{
	//send stop condition bit
	SET_BIT(TWCR,TWCR_TWSTO);
	//CLR INTERRUPT FLAG
	SET_BIT(TWCR,TWCR_TWINT);

}
