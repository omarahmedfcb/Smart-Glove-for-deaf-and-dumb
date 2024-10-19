/*
 * TWI_private.h
 *
 *  Created on: ???/???/????
 *      Author: Omar Mohamed
 */

#ifndef INCLUDE_MCAL_TWI_TWI_PRIVATE_H_
#define INCLUDE_MCAL_TWI_TWI_PRIVATE_H_

#define START_ACK                0x08 //start has been sent
#define REP_START_ACK            0x10 //repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 //Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 //Master transmit ( slave address + Read request ) ACK
#define MSTR_WR_BYTE_ACK         0x28 //Master transmit data ACK
#define MSTR_RD_BYTE_WITH_ACK    0x50 //Master received data with ACK
#define MSTR_RD_BYTE_WITH_NACK   0x58 //Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 //means that slave address is received with read request
#define SLAVE_ADD_RCVD_WR_REQ    0x60 //means that slave address is received with write request
#define SLAVE_DATA_RECEIVED      0x80 //means that a byte is received
#define SLAVE_BYTE_TRANSMITTED   0xB8 //means that the written byte is transmitted

#define TWCR (*(volatile u8 *)0x56)
#define TWCR_TWINT 7
#define TWCR_TWEA 6
#define TWCR_TWSTA 5
#define TWCR_TWSTO 4
#define TWCR_TWEN 2
#define TWCR_TWIE 0

#define TWDR (*(volatile u8 *)0x23)
#define	TWDR_TWD0	0

#define TWAR (*(volatile u8 *)0x22)
#define TWSR (*(volatile u8 *)0x21)
#define TWSR_TWPS1 1
#define TWSR_TWPS0 0

#define TWBR (*(volatile u8 *)0x20)


#define STATUS		(TWSR&0xF8)
#define STATUS_BIT_MASK 0xF8
#define NULL 0
#endif /* INCLUDE_MCAL_TWI_TWI_PRIVATE_H_ */
