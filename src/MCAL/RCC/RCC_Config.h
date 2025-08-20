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

#endif /* RCC_CONFIG_H_ */
