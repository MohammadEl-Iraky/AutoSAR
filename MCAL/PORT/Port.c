/*
 * Port.c
 *
 *  Created on: Mar 21, 2020
 *      Author: super
 */

#include "Port.h"
#include "../../Bit_Math.h"


/*******************************************************************************************************************
 *                                             Port user-defined Macros
 *******************************************************************************************************************/

#define GET_PORT_FROM_PIN(PIN_NO)    ( (PIN_NO) / 8 )
#define GET_BIT_FROM_PIN(PIN_NO)     ( (PIN_NO) % 8 )

/*******************************************************************************************************************
 *                                             Port global variables
 *******************************************************************************************************************/

#if developer_error
static uint8 g_PortStatus = PORT_UNINIT;
#endif
static const Port_ConfigChannel * g_ConfigPtr = NULL_PTR;

/*******************************************************************************************************************
 *                                             Port function definitions
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

void Port_Init( const Port_ConfigType* ConfigPtr )
{
    uint8 Port_no;
    uint8 Pin_no;
    uint8 i = 0;
    uint32 GpioBase;
#if developer_error
    if( NULL_PTR == ConfigPtr )
    {
        //  Det_ReportError(ModuleId, InstanceId, ApiId, PORT_E_PARAM_CONFIG);
    }
    else
#endif
    {
        g_ConfigPtr = ConfigPtr->Channels;
        HW_REG(RCGCGPIO) |= (1<<0)|(1<<2)|(1<<1)|(1<<3)|(1<<4)|(1<<5);

        /* Enable clocks for all the Ports */

        for( i=0; i<PORT_MAX_NO_OF_PINS; i++ )
        {
            Port_no = GET_PORT_FROM_PIN( ConfigPtr->Channels[i].PinType );
            Pin_no = GET_BIT_FROM_PIN( ConfigPtr->Channels[i].PinType );

            switch( Port_no )   /* Get the current GPIO port */
            {
                case 0: GpioBase = GPIOA_BASE;             /* Gpio A base address */
                        break;
                case 1: GpioBase = GPIOB_BASE;             /* Gpio B base address */
                        break;
                case 2: GpioBase = GPIOC_BASE;             /* Gpio C base address */
                        break;
                case 3: GpioBase = GPIOD_BASE;             /* Gpio D base address */
                        break;
                case 4: GpioBase = GPIOE_BASE;             /* Gpio E base address */
                        break;
                case 5: GpioBase = GPIOF_BASE;             /* Gpio F base address */
                        break;
             }

            /* Initial Pin direction */
             if(  PORT_PIN_OUT == g_ConfigPtr[i].Direction )
             {
                 SET_BIT( HW_REG( GpioBase + GPIO_DIR_OFFSET ), Pin_no );
             }
             else
             {
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_DIR_OFFSET ), Pin_no );
             }

             /* Initial Pin value */
             if( STD_HIGH == g_ConfigPtr[i].InitValue  )
             {
                 SET_BIT( HW_REG( GpioBase + GPIO_DATA_OFFSET ), Pin_no );
             }
             else
             {
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_DATA_OFFSET ), Pin_no );
             }

             /* Initial Pin Mode */
             if( PORTX_PINX_DIO == g_ConfigPtr[i].Mode )         /* If its DIO */
             {
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_AFSEL_OFFSET ), Pin_no );
                 SET_BIT( HW_REG( GpioBase + GPIO_DEN_OFFSET ), Pin_no );
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_AMSEL_OFFSET ), Pin_no );
             }
             else if( PORTX_PINX_ADC == g_ConfigPtr[i].Mode )    /* If its ADC */
             {
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_DEN_OFFSET ), Pin_no );
                 SET_BIT( HW_REG( GpioBase + GPIO_AMSEL_OFFSET ) , Pin_no );
                 SET_BIT( HW_REG( GpioBase + GPIO_AFSEL_OFFSET ), Pin_no );
             }
             else                                                /* For a different alternate function */
             {
                 SET_BIT( HW_REG( GpioBase + GPIO_AFSEL_OFFSET ), Pin_no );
                 HW_REG( GpioBase + GPIO_PCTL_OFFSET ) |= ( (g_ConfigPtr[i].Mode)<<(Pin_no*4) );
                 //GpioBase->PCTL = ((GpioBase->PCTL)&(0x0F<<(Pin_no*4))) | (g_ConfigPtr[i].Mode)<<(Pin_no*4);
             }

             /* Internal resistance functionality */
             if( PULL_UP_ON == ConfigPtr->Channels[i].InternalRes )
             {
                 SET_BIT( HW_REG( GpioBase + GPIO_PUR_OFFSET ), Pin_no );
             }
             else if( PULL_DOWN_ON == ConfigPtr->Channels[i].InternalRes )
             {
                 SET_BIT( HW_REG( GpioBase + GPIO_PDR_OFFSET ), Pin_no );
             }
             else
             {
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_PUR_OFFSET ), Pin_no );
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_PDR_OFFSET ), Pin_no );
             }

             /* Pin Open Drain functionality */
             if( OPEN_DRAIN == ConfigPtr->Channels[i].OpenDrain )
             {
                 SET_BIT( HW_REG( GpioBase + GPIO_ODR_OFFSET ), Pin_no );
             }
             else
             {
                 CLEAR_BIT( HW_REG( GpioBase + GPIO_ODR_OFFSET ), Pin_no );
             }
        }
    }
}

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

void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
    uint8 Port_no;
    uint8 Pin_no;
    uint32 GpioBase;

#if 0
    if( PORT_UNINIT == g_PortStatus )
    {
        /* Det report error Port module is not initialized */
    }
    else
    {
        /* Empty else */
    }

    if( PORT_MAX_NO_OF_PINS <= Pin )
    {
        /* Det report error invalid pin number */
    }
    else
    {

    }

    if( STD_OFF == g_ConfigPtr[Pin].DirectionChange )
    {
        /* Det report error direction unchangeable */
    }

#endif

    Port_no = GET_PORT_FROM_PIN( Pin );
    Pin_no = GET_BIT_FROM_PIN( Pin );

    switch( Port_no )   /* Get the current GPIO port */
     {
         case 0: GpioBase = GPIOA_BASE;             /* Gpio A base address */
                 break;
         case 1: GpioBase = GPIOB_BASE;             /* Gpio B base address */
                 break;
         case 2: GpioBase = GPIOC_BASE;             /* Gpio C base address */
                 break;
         case 3: GpioBase = GPIOD_BASE;             /* Gpio D base address */
                 break;
         case 4: GpioBase = GPIOE_BASE;             /* Gpio E base address */
                 break;
         case 5: GpioBase = GPIOF_BASE;             /* Gpio F base address */
                 break;
      }

     /* Change Pin direction */
     if(  PORT_PIN_OUT == g_ConfigPtr[Pin].Direction )
     {
         SET_BIT( HW_REG( GpioBase + GPIO_DIR_OFFSET ), Pin_no );
     }
     else
     {
         CLEAR_BIT( HW_REG( GpioBase + GPIO_DIR_OFFSET ), Pin_no );
     }


}

