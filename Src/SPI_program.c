/*
 * SPI_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "..\Include\MCAL\SPI\SPI_Interface.h"
#include "..\Include\MCAL\SPI\SPI_private.h"
#include "..\Include\MCAL\SPI\SPI_Configurations.h"


void MSPI_voidInit (void)
{
		SPCR = CONC_BIT(SPI_INTERRUPT_ENABLE,
						0,
						DATA_ORDER,
						OPERATING_MODE,
						CLK_POLARIZATION,
						CLK_PHASE,
						0,
						0);
		//Select Clock Rate
		SPCR |= (CLK_RATE<<CLK_RATE_B1);
		//Select Double Speed Mode
#if (DOUBLE_SPEED == ON)
		SET_BIT(SPSR , SPI2X);
#else
		CLR_BIT(SPSR , SPI2X);
#endif
		SET_BIT(SPCR , SPI_ENABLE);
}


u8 MSPI_u8SendAndReceive (u8 A_u8Data)
{
	SPDR = A_u8Data;
	while (GET_BIT(SPSR , SPIF) == 0);
	return SPDR;
}
