/*
 * SPI_Private.h
 *
 *  Created on: Sep 2, 2025
 *      Author: JETT
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#include  "../../LIB/STD_TYPES.H"

typedef struct{
	u32 CR1;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_Memory;

#define SPI1_BASE_ADDRESS 			0x40013000
#define SPI2_BASE_ADDRESS           0x40003800
#define SPI3_BASE_ADDRESS           0x40003C00

#define SPI1   ((volatile SPI_Memory*)(0x40013000))
#define SPI2   ((volatile SPI_Memory*)(0x40003800))
#define SPI3   ((volatile SPI_Memory*)(0x40003C00))

#define SPI_NUM1                     0
#define SPI_NUM2                     1
#define SPI_NUM3                     2


//CR1 regigster
#define MSTR_BIT                    2
#define SSM_BIT                     9
#define SSI_BIT                     8
#define DFF_BIT                     11
#define CPOL_BIT                    1
#define CPHA_BIT                    0


//SR register
#define TXE_BIT                     1
#define RXNE_BIT                    0

//Configurations
#define MASTER                        0
#define SLAVE                         1
#define DFF_8BIT                      0
#define DFF_16BIT                     1
#define IDLE_LOW                      0
#define IDLE_HIGH                     1

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
