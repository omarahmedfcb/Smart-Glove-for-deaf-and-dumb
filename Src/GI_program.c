/*
 * GI_program.c
 *
 *  Created on: ???/???/????
 *      Author: Hesha
 */

#include "..\Include\LIB\STD_Types.h"
#include "..\Include\LIB\BIT_MATH.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../Include/MCAL/GI/GI_Configurations.h"


void MGI_voidEnable (void)
{
	SET_BIT(SREG,I_FLAG);
}

void MGI_voidDisable (void)
{
	CLR_BIT(SREG,I_FLAG);
}
