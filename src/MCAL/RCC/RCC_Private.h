/*
 * RCC_Private.h
 *
 *  Created on: Aug 16, 2025
 *      Author: JETT
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

//RCC Memory Mapping
typedef struct RCC_Memory{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1;
	u32 reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved3;
	u32 reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved5;
	u32 reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 reserved7;
	u32 reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 reserved9;
	u32 reserved10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 reserved11;
	u32 reserved12;
	u32 BDCR;
	u32 CSR;
	u32 reserved13;
	u32 reserved14;
	u32 SSCGR;
	u32 CFGR;
	u32 reserved15;
	u32 DCKCFGR;
} RCC_Memory;


//RCC_SYS_CLK -OPTIONS
#define HSE_CLK              0
#define HSI_CLK              1
#define PLI_CLK              2

//HSE_BYPASS  -OPTIONS
#define RC_CLK               0
#define MECHANICAL_CLK       1


//RC CR bits
#define HSION                 0
#define HSEBYP                18
#define HSERDY                17
#define HSIRDY                1
#define PLION                 24


//RC CFGR bits
#define SW0                   0
#define SW1                   1

//RCC Struct

#endif /* RCC_PRIVATE_H_ */
