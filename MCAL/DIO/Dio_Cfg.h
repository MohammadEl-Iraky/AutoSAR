/*
 * dio_cfg.h
 *
 *  Created on: Mar 20, 2020
 *      Author: super
 */

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_

/* Number of channels configured in the Dio Module */
#define DIO_CONFIGURED_CHANNELS          2

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT             STD_OFF

#define DIO_LED_CHANNEL_INDEX            0  /* Led Index in PBcfg struct */
#define DIO_LED_CHANNEL_NO               3  /* Pin Number 3 */
#define DIO_LED_PORT_NO                  6  /* Port F */

#define DIO_BUTTON_CHANNEL_INDEX         1  /* Button index in PBcfg struct */
#define DIO_BUTTON_CHANNEL_NO            2  /* Pin Number 2 */
#define DIO_BUTTON_PORT_NO               3  /* Port C */

#endif /* MCAL_DIO_DIO_CFG_H_ */
