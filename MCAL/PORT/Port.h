/*
 * Port.h
 *
 *  Created on: Mar 21, 2020
 *      Author: super
 */

#ifndef MCAL_PORT_PORT_H_
#define MCAL_PORT_PORT_H_

#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Port_Regs.h"

#define PORT_INIT    (0x01U)
#define PORT_UNINIT  (0x00U)

/*******************************************************************************************************************
 *                                                  DET Error codes
 *******************************************************************************************************************/

/* Det code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                0x0A

/* Det code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE   0x0B

/* Det code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG             0x0C

/* Det code to to report Port_SetPinMode called with Invalid mode */
#define PORT_E_PARAM_INVALID_MODE       0x0D

/* Det code to report API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE        0x0E

/* Det code to report API service called without module initialization */
#define PORT_E_UNINIT                   0x0F

/* Det code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER            0x10

/*******************************************************************************************************************
 *                                                      Port types
 *******************************************************************************************************************/

/* Typedef variable Port_PinType shall be used for the symbolic name of a Port Pin. */
typedef uint8   Port_PinType;

/* Typedef variable Port_PinDirectionType is a type for defining the direction of a Port Pin.
 * having range as PORT_PIN_IN and PORT_PIN_OUT.
 */
typedef uint8 Port_PinDirectionType;

/* Typedef variable Port_PinModeType is a type for defining the mode of a Port Pin.
 * having range as the available Port pin modes
 */
typedef uint8 Port_PinModeType;

/* Typedef variable Port_PinDirectionType is a type for defining the initial value of a Port Pin.
 * having range as STD_HIGH and STD_LOW.
 */
typedef uint8 Port_PinLevelInitValue;

/* Typedef variable Port_PinPullUp is a type for the Pullup resistor functionality of a Port Pin. */
typedef uint8 Port_PinInternalResistor;

/* Typedef variable Port_PinDirectionChangeability is a type for the ability to change the direction of a Port Pin in runtime. */
typedef uint8 Port_PinDirectionChangeable;

/* Typedef variable PinModeChangeability is a type for the ability to change the mode of a Port Pin in runtime. */
typedef uint8 Port_PinModeChangeable;

typedef uint8 Port_PinOpenDrain;


typedef struct
{
    Port_PinType                        PinType;
    Port_PinDirectionType               Direction;
    Port_PinModeType                    Mode;
    Port_PinLevelInitValue              InitValue;
    Port_PinInternalResistor            InternalRes;
    Port_PinDirectionChangeable         DirectionChange;
    Port_PinModeChangeable              ModeChange;
    Port_PinOpenDrain                   OpenDrain;
}Port_ConfigChannel;

/* The type Port_ConfigType is a type for the external data structure containing the initialization data for the Port Driver. */
typedef struct
{
    Port_ConfigChannel  Channels[PORT_MAX_NO_OF_PINS];
}Port_ConfigType;

/*******************************************************************************************************************
*                                                   Port Function prototypes
 *******************************************************************************************************************/

/******************************************************************************************
 *  Service Name: Port_Init
 *  Service ID: 0x00
 *  Sync/Async: Synchronous
 *  Reentrancy: Non Reentrant
 *  Parameters(in): ConfigPtr: Pointer to configuration set.
 *  Parameters(in/out): None
 *  Parameters(out): None
 *  Return value: None
 *  Description: Initializes the Port Driver module.
 *****************************************************************************************/

void Port_Init( const Port_ConfigType* ConfigPtr );

/******************************************************************************************
 *  Service Name: Port_SetPinDirection
 *  Service ID: 0x01
 *  Sync/Async: Synchronous
 *  Reentrancy: Reentrant
 *  Parameters(in): Pin: Port Pin ID number
 *                  Direction: Port pin direction
 *  Parameters(in/out): None
 *  Parameters(out): None
 *  Return value: None
 *  Description: Sets the Port Pin direction
 *****************************************************************************************/

void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );

/*******************************************************************************************************************
 *                                          Port extern variables
 *******************************************************************************************************************/
extern const Port_ConfigType Port_Configuration;



#endif /* MCAL_PORT_PORT_H_ */
