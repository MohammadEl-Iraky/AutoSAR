/*
 * Dio_Regs.h
 *
 *  Created on: Mar 21, 2020
 *      Author: super
 */

#ifndef _GPIO_REGS_H_
#define _GPIO_REGS_H_

#include "Std_Types.h"

#define GPIO_DATA_OFFSET        0x3FCUL                            /* GPIO DATA */
#define GPIO_DIR_OFFSET         0x400UL                            /* GPIO Direction */
#define GPIO_IS_OFFSET          0x404UL                            /* GPIO Interrupt Sense */
#define GPIO_AFSEL_OFFSET       0x420UL                            /* GPIO Alternate Function Select */
#define GPIO_ODR_OFFSET         0x50CUL                            /* GPIO Open Drain Select */
#define GPIO_PUR_OFFSET         0x510UL                            /* GPIO Pull-Up Select */
#define GPIO_PDR_OFFSET         0x514UL                            /* GPIO Pull-Down Select */
#define GPIO_DEN_OFFSET         0x51CUL                            /* GPIO Digital Enable */
#define GPIO_AMSEL_OFFSET       0x528UL                            /* GPIO Analog Mode Select */
#define GPIO_PCTL_OFFSET        0x52CUL                            /* GPIO Port Control */

#define GPIOA_BASE          0x40004000UL                               /* GPIOA base address */
#define GPIOB_BASE          0x40005000UL                               /* GPIOB base address */
#define GPIOC_BASE          0x40006000UL                               /* GPIOC base address */
#define GPIOD_BASE          0x40007000UL                               /* GPIOD base address */
#define GPIOE_BASE          0x40024000UL                               /* GPIOE base address */
#define GPIOF_BASE          0x40025000UL                               /* GPIOF base address */

#define RCGCGPIO            0x400FE608UL

#endif
