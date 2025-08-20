/*
 * RCC_Interface.h
 *
 *  Created on: Aug 16, 2025
 *      Author: JETT
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.H"
#include "RCC_Private.h"
#include "RCC_Config.h"

#define RCC (*volatile RCC_Memory*(0x40023800))

void MRCC_Init();






#endif /* RCC_INTERFACE_H_ */
