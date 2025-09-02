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




void RCC_Init();
void RCC_Enable(u8 bus ,u8 peripheral);





#endif /* RCC_INTERFACE_H_ */
