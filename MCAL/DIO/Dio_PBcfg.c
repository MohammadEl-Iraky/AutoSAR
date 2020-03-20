/*
 * dio_pbcfg.c
 *
 *  Created on: Mar 20, 2020
 *      Author: super
 */

#include <MCAL/DIO/Dio.h>

const Dio_ConfigType Dio_Configuration =
{
     {
 /*            Dio_ChannelType               Dio_PortType             */
         {   DIO_LED_CHANNEL_NO,          DIO_LED_PORT_NO       },
         {   DIO_BUTTON_CHANNEL_NO,       DIO_BUTTON_PORT_NO    }
     }
};


