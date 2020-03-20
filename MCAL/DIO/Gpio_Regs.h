/*
 * Dio_Regs.h
 *
 *  Created on: Mar 21, 2020
 *      Author: super
 */

#ifndef MCAL_DIO_GPIO_REGS_H_
#define MCAL_DIO_GPIO_REGS_H_

#include "Std_Types.h"

/* GPIO typdef struct  */
typedef struct {
  volatile const            uint32  RESERVED[255];                     /* Reserved */
  volatile                  uint32  DATA;                              /* GPIO Data */
  volatile                  uint32  DIR;                               /* GPIO Direction */
  volatile                  uint32  IS;                                /* GPIO Interrupt Sense */
  volatile                  uint32  IBE;                               /* GPIO Interrupt Both Edges */
  volatile                  uint32  IEV;                               /* GPIO Interrupt Event  */
  volatile                  uint32  IM;                                /* GPIO Interrupt Mask   */
  volatile                  uint32  RIS;                               /* GPIO Raw Interrupt Status */
  volatile                  uint32  MIS;                               /* GPIO Masked Interrupt Status  */
  volatile                  uint32  ICR;                               /* GPIO Interrupt Clear  */
  volatile                  uint32  AFSEL;                             /* GPIO Alternate Function Select */
  volatile const            uint32  RESERVED1[55];                     /* Reserved */
  volatile                  uint32  DR2R;                              /* GPIO 2-mA Drive Select */
  volatile                  uint32  DR4R;                              /* GPIO 4-mA Drive Select */
  volatile                  uint32  DR8R;                              /* GPIO 8-mA Drive Select */
  volatile                  uint32  ODR;                               /* GPIO Open Drain Select */
  volatile                  uint32  PUR;                               /* GPIO Pull-Up Select */
  volatile                  uint32  PDR;                               /* GPIO Pull-Down Select */
  volatile                  uint32  SLR;                               /* GPIO Slew Rate Control Select */
  volatile                  uint32  DEN;                               /* GPIO Digital Enable */
  volatile                  uint32  LOCK;                              /* GPIO Lock */
  volatile                  uint32  CR;                                /* GPIO Commit */
  volatile                  uint32  AMSEL;                             /* GPIO Analog Mode Select */
  volatile                  uint32  PCTL;                              /* GPIO Port Control */
  volatile                  uint32  ADCCTL;                            /* GPIO ADC Control */
  volatile                  uint32  DMACTL;                            /* GPIO DMA Control */
} GPIO_Type;

#define GPIOA_BASE          0x40004000UL                               /* GPIOA base address */
#define GPIOB_BASE          0x40005000UL                               /* GPIOB base address */
#define GPIOC_BASE          0x40006000UL                               /* GPIOC base address */
#define GPIOD_BASE          0x40007000UL                               /* GPIOD base address */
#define GPIOE_BASE          0x40024000UL                               /* GPIOE base address */
#define GPIOF_BASE          0x40025000UL                               /* GPIOF base address */

#define GPIOA               (( GPIO_Type * ) GPIOA_BASE)
#define GPIOB               (( GPIO_Type * ) GPIOB_BASE)
#define GPIOC               (( GPIO_Type * ) GPIOC_BASE)
#define GPIOD               (( GPIO_Type * ) GPIOD_BASE)
#define GPIOE               (( GPIO_Type * ) GPIOE_BASE)
#define GPIOF               (( GPIO_Type * ) GPIOA_BASE)

#endif /* MCAL_DIO_GPIO_REGS_H_ */
