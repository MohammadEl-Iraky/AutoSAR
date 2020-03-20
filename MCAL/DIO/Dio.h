/*
 * Dio.h
 *
 *  Created on: Mar 20, 2020
 *      Author: super
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <MCAL/DIO/Dio_Cfg.h>
#include <MCAL/DIO/Gpio_Regs.h>
#include <Std_Types.h>
#include "../../Det.h"
#include "../../Bit_Math.h"


#define DIO_INIT    (0x01U)
#define DIO_UNINIT  (0x00U)

/*******************************************************************************************************************
 *                                                  DET Error codes
 *******************************************************************************************************************/

/* Det code to report invalid channel name requested */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  (0x00U)

/* Det code to report API service called with Null ptr */
#define DIO_E_PARAM_CONFIG              (0x10U)

/* Det code to report invalid port name requested */
#define DIO_E_PARAM_INVALID_PORT_ID     (0x14U)

/* Det code to report invalid group name passed */
#define DIO_E_PARAM_INVALID_GROUP       (0x1FU)

/* Det code to report API service called with a NULL pointer. In case of this error,
 * the API service shall return immediately without any further action, beside reporting this development error */
#define DIO_E_PARAM_POINTER             (0x20U)

/*******************************************************************************************************************
 *                                                  Dio types
 *******************************************************************************************************************/

/* Typedef for Dio_ChannelType used by Dio APIs */
typedef uint8 Dio_ChannelType ;

/* Typedef for Dio_PortType used by Dio APIs */
typedef uint8 Dio_PortType ;

/* Typedef for Dio_LevelType used by Dio APIs */
typedef uint8 Dio_LevelType ;           /* Dio level type */

/* Typedef for Dio_PortLevelType used by Dio APIs */
typedef uint8 Dio_PortLevelType;

typedef struct
{
    Dio_ChannelType Channel_no;
    Dio_PortType    Port_no;
}Dio_ConfigChannel;

typedef struct
{
    Dio_ConfigChannel Channels[ DIO_CONFIGURED_CHANNELS ];
}Dio_ConfigType;

/*******************************************************************************************************************
 *                                           Dio function prototypes
 *******************************************************************************************************************/

/******************************************************************************************
 *  Service Name: Dio_ReadChannel
 *  Service ID: 0x00
 *  Sync/Async: Synchronous
 *  Reentrancy: Reentrant
 *  Parameters(in): channelId: Id of the dio channel
 *  Parameters(in/out): None
 *  Parameters(out): None
 *  Return value: STD_HIGH, The value of the pin is high 3.3v
 *                STD_LOW, The value of the pin is low 0v
 *  Description: Returns the value of the specified Dio Channel
 *****************************************************************************************/

Dio_LevelType Dio_ReadChannel( Dio_ChannelType channelId );

/******************************************************************************************
 *  Service Name: Dio_WriteChannel
 *  Service ID: 0x01
 *  Sync/Async: Synchronous
 *  Reentrancy: Reentrant
 *  Parameters(in): channelId: Id of the Dio channel
 *                  Level: Value to be written
 *  Parameters(in/out): None
 *  Parameters(out): None
 *  Return value: None
 *  Description: Set the level of the selected Dio Channel
 *****************************************************************************************/

void Dio_WriteChannel( Dio_ChannelType channelId, Dio_LevelType Level);

/******************************************************************************************
 *  Service Name: Dio_Init
 *  Service ID: 0x10
 *  Sync/Async: Synchronous
 *  Reentrancy: Non Reentrant
 *  Parameters(in): ConfigPtr: Pointer to post build configuration data
 *  Parameters(in/out): None
 *  Parameters(out): None
 *  Return value: None
 *  Description: Initializes the module
 *****************************************************************************************/

void Dio_Init( const Dio_ConfigType * ConfigPtr );

/*******************************************************************************************************************
 *                                           Dio extern variables
 *******************************************************************************************************************/
extern const Dio_ConfigType Dio_Configuration;


#endif /* MCAL_DIO_DIO_H_ */
