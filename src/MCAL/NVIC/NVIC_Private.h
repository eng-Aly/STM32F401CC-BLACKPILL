/*
 * NVIC_Private.h
 *
 *  Created on: Aug 19, 2025
 *      Author: JETT
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#include  "../../LIB/STD_TYPES.h"


#define NVIC_BASE_ADDR  0xE000EF00



typedef struct{
	u32 ISER[8];
	u32 reserved1[24];
	u32 ICER[8];
	u32 reserved2[24];
	u32 ISPR[8];
	u32 reserved3[24];
	u32 ICPR[8];
	u32 reserved4[24];
	u32 IABR;
	u32 reserved5[24];
	u32 IPRx[60];
	u32 reserved6[580];
	u32 STIR[8];
}NVIC_Memory;

typedef enum{
	NVIC_GROUP_16_SUB_0 = 3,
	NVIC_GROUP_8_SUB_2,
	NVIC_GROUP_4_SUB_4,
	NVIC_GROUP_2_SUB_8,
	NVIC_GROUP_0_SUB_16
}NVIC_GROUP;


#define NVIC                  ((volatile NVIC_Memory*)(NVIC_BASE_ADDR))



#define SCB_AIRCR             ((volatile u32*)(0xE000ED0C))

#define VECTKEY                                0x05FA0000



#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
