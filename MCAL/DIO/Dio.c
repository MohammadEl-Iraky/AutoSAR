/*
 * dio.c
 *
 *  Created on: Mar 20, 2020
 *      Author: super
 */

#include "Dio.h"
#include "../../Bit_Math.h"


/*******************************************************************************************************************
 *                                             Dio global variables
 *******************************************************************************************************************/

#if DIO_DEV_ERROR_DETECT == STD_ON
static uint8 g_DioStatus = DIO_UNINIT;
#endif

static const Dio_ConfigChannel * g_ChannelPtr = NULL_PTR;

/*******************************************************************************************************************
 *                                           Dio function definitions
 *******************************************************************************************************************/

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

void Dio_Init( const Dio_ConfigType * ConfigPtr )
{
#if DIO_DEV_ERROR_DETECT == STD_ON
    if( ConfigPtr == NULL_PTR )
    {
      //  Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId)
    }
    else
#endif
    {
#if DIO_DEV_ERROR_DETECT == STD_ON
        g_DioStatus = DIO_INIT;
#endif
        g_ChannelPtr = ConfigPtr->Channels;
    }
}

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

Dio_LevelType Dio_ReadChannel( Dio_ChannelType channelId )
{

    uint8 error = STD_OFF;
    volatile uint32 * PortDataPtr = NULL_PTR;
    uint8 result;

#if DIO_DEV_ERROR_DETECT == STD_ON
    if( DIO_CONFIGURED_CHANNELS <= channelId  )
    {
        /* Det_ReportError(ModuleId, InstanceId, ApiId, DIO_E_PARAM_INVALID_CHANNEL_ID ) */
        error = STD_ON;

    }
    else
    {
        /* Empty else */
    }

    if( DIO_UNINIT == g_DioStatus )
    {
        /* Det_ReportError */
    }
    else
    {
        /* Empty else */
    }

#endif

    if( STD_OFF == error )  /* If there was no erro */
    {
        switch( g_ChannelPtr[channelId].Port_no )   /* Get the Port address into the PortDataPtr variable */
        {
            case 0: PortDataPtr = &HW_REG( GPIOA_BASE + GPIO_DATA_OFFSET );          /* Port A data address */
                    break;
            case 1: PortDataPtr = &HW_REG( GPIOB_BASE + GPIO_DATA_OFFSET );          /* Port B data address */
                    break;
            case 2: PortDataPtr = &HW_REG( GPIOC_BASE + GPIO_DATA_OFFSET );          /* Port C data address */
                    break;
            case 3: PortDataPtr = &HW_REG( GPIOD_BASE + GPIO_DATA_OFFSET );          /* Port D data address */
                    break;
            case 4: PortDataPtr = &HW_REG( GPIOE_BASE + GPIO_DATA_OFFSET );          /* Port E data address */
                    break;
            case 5: PortDataPtr = &HW_REG( GPIOF_BASE + GPIO_DATA_OFFSET );          /* Port F data address */
                    break;
        }

        result = GET_BIT( *PortDataPtr, g_ChannelPtr[channelId].Channel_no );       /* Value to be returned from this API */
    }
    else
    {
        /* Do nothing */
    }
    return result;
}

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

void Dio_WriteChannel( Dio_ChannelType channelId, Dio_LevelType Level)
{

    uint8 error = STD_OFF;
    volatile uint32 * PortDataPtr = NULL_PTR;

#if DIO_DEV_ERROR_DETECT == STD_ON
    if( DIO_CONFIGURED_CHANNELS <= channelId  )
    {
        /*  Det_ReportError(ModuleId, InstanceId, ApiId, DIO_E_PARAM_INVALID_CHANNEL_ID ) */
        error = STD_ON;

    }
    else
    {
        /* Empty else */
    }

    if( DIO_UNINIT == g_DioStatus )
    {
        /* Det_ReportError */
    }
    else
    {
        /* Empty else */
    }
#endif

    if( STD_OFF == error )
    {
        switch( g_ChannelPtr[channelId].Port_no )
        {
            case 0: PortDataPtr = &HW_REG( GPIOA_BASE + GPIO_DATA_OFFSET );          /* Port A data address */
                    break;
            case 1: PortDataPtr = &HW_REG( GPIOB_BASE + GPIO_DATA_OFFSET );          /* Port B data address */
                    break;
            case 2: PortDataPtr = &HW_REG( GPIOC_BASE + GPIO_DATA_OFFSET );          /* Port C data address */
                    break;
            case 3: PortDataPtr = &HW_REG( GPIOD_BASE + GPIO_DATA_OFFSET );          /* Port D data address */
                    break;
            case 4: PortDataPtr = &HW_REG( GPIOE_BASE + GPIO_DATA_OFFSET );          /* Port E data address */
                    break;
            case 5: PortDataPtr = &HW_REG( GPIOF_BASE + GPIO_DATA_OFFSET );          /* Port F data address */
                    break;
        }

        if( STD_HIGH == Level )
        {
            /* Write a logical high value at the requested Pin */
            SET_BIT( *PortDataPtr, g_ChannelPtr[channelId].Channel_no );
        }
        else
        {
            /* Write a logical low value at the requested Pin */
            CLEAR_BIT( *PortDataPtr, g_ChannelPtr[channelId].Channel_no );
        }

    }
    else
    {
        /* Empty else */
    }

}




