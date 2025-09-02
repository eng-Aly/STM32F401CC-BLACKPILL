/*
 * RCC_Config.h
 *
 *  Created on: Aug 16, 2025
 *      Author: JETT
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*RCC_SYS_CLK -OPTIONS
 HSE_CLK 0
 HSI_CLK 1
 PLI_CLK 2
*/
#define RCC_SYS_CLK  HSE_CLK


/* HSE_BYPASS -OPTIONS
 RC_CLK                0
 MECHANICAL_CLK        1
 */
#define HSE_BYPASS        RC_CLK

/* BUSSES      -OPTIONS
 RCC_AHB1             0
 RCC_AHB2             1
 RCC_APB1             2
 RCC_APB2             3
 */

/* PERIPHERALS   -OPTIONS
 RCC_GPIOA           0
 RCC_GPIOB           1
 */


#endif /* RCC_CONFIG_H_ */



