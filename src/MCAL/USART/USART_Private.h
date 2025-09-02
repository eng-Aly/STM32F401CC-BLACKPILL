/*
 * USART_Private.h
 *
 *  Created on: Sep 1, 2025
 *      Author: JETT
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

#include  "../../LIB/STD_TYPES.H"



typedef struct {
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART_Memory;


#define USART1_ADDRESS   0x40011000
#define USART2_ADDRESS   0x40004400
#define USART6_ADDRESS   0x40011400


/*CR1 BITS*/
#define USART_ENABLE_BIT      13
#define WORD_LENGTH_BIT       12
#define PARITY_CONTROL_BIT    10
#define PARITY_SELECTION_BIT  9
#define TCIE_BIT              6

/*SR BITS*/
#define TXE_BIT              7
#define RXNE_BIT             5
#define ORE_BIT              3
#define NE_BIT               2
#define FE_BIT               1
#define PE_BIT               0

#define USART1         ((volatile USART_Memory*)(USART1_ADDRESS))
#define USART2         ((volatile USART_Memory*)(USART2_ADDRESS))
#define USART6         ((volatile USART_Memory*)(USART6_ADDRESS))

/* USART_SELECT --OPTIONS */
#define USARTNUM1          0
#define USARTNUM2          1
#define USARTNUM6         2

/* WORD_SIZE --OPTIONS */
#define WORD_8BIT_SIZE   0
#define WORD_9BIT_SIZE   1

/* PARITY_CONTROL --OPTIONS*/
#define PARTIY_DISABLE   0
#define PARTIY_ENABLE    1
/* PARITY_SELECTION --OPTIONS*/
#define EVEN_PARITY      0
#define ODD_PARITY       1
/* TC_INTERRUPT    --OPTIONS*/
#define TC_ENABLE        0
#define TC_DISABLE       1











#endif /* MCAL_USART_USART_PRIVATE_H_ */
