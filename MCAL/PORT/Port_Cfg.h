/*
 * Port_Cfg.h
 *
 *  Created on: Mar 21, 2020
 *      Author: super
 */

#ifndef MCAL_PORT_PORT_CFG_H_
#define MCAL_PORT_PORT_CFG_H_

/* Number of pins in Tiva C */
#define PORT_MAX_NO_OF_PINS             48

#define PUSH_PULL                       (0x00U)
#define OPEN_DRAIN                      (0x01U)

#define DIRECTION_UNCHANGEABLE          (0x00U)
#define DIRECTION_CHANGEABLE            (0x01U)

#define MODE_UNCHANGEABLE               (0x00U)
#define MODE_CHANGEABLE                 (0x01U)


#define PULL_UP_ON                      (0x00U)
#define PULL_DOWN_ON                    (0x01U)
#define NO_PULL_RES                     (0x02U)

#define PORT_PIN_IN                     STD_OFF /* Sets Port as Input */
#define PORT_PIN_OUT                    STD_ON  /* Sets Port as Output */

#define PORTX_PINX_DIO                  (0U)
#define PORTX_PINX_ADC                  (16U)
/* Port pins symbolic modes */
/* Port A symbolic mode names */
#define PORTA_PIN0_U0RX                 (1U)
#define PORTA_PIN0_CAN1RX               (8U)
#define PORTA_PIN1_U0TX                 (1U)
#define PORTA_PIN1_CAN1TX               (8U)
#define PORTA_PIN2_SSI0CLK              (2U)
#define PORTA_PIN3_SSI0FSS              (2U)
#define PORTA_PIN4_SSI0RX               (2U)
#define PORTA_PIN5_SSI0TX               (2U)
#define PORTA_PIN6_I2C1SCL              (3U)
#define PORTA_PIN6_M1PWM2               (5U)
#define PORTA_PIN7_I2C1SDA              (3U)
#define PORTA_PIN7_M1PWM3               (5U)

/* Port A symbolic mode names */
#define PORTB_PIN0_U1RX                 (1U)
#define PORTB_PIN0_T2CCP0               (7U)
#define PORTB_PIN1_U1TX                 (1U)
#define PORTB_PIN1_T2CCP1               (7U)
#define PORTB_PIN2_I2C0SCL              (3U)
#define PORTB_PIN2_T3CCP0               (7U)
#define PORTB_PIN3_I2C0SDA              (3U)
#define PORTB_PIN3_T3CCP1               (7U)
#define PORTB_PIN4_SSI2CLK              (2U)
#define PORTB_PIN4_M0PWM2               (4U)
#define PORTB_PIN4_T1CCP0               (7U)
#define PORTB_PIN4_CAN0RX               (8U)
#define PORTB_PIN5_SSI2FSS              (2U)
#define PORTB_PIN5_M0PWM3               (4U)
#define PORTB_PIN5_T1CCP1               (7U)
#define PORTB_PIN5_CAN0TX               (8U)
#define PORTB_PIN6_SSI2CRX              (2U)
#define PORTB_PIN6_M0PWM0               (4U)
#define PORTB_PIN6_T0CCP0               (7U)
#define PORTB_PIN7_SSI2TX               (2U)
#define PORTB_PIN7_M0PWM1               (4U)
#define PORTB_PIN7_T0CCP1               (7U)










/* Port pins symbolic names */
#define PORT_A_PIN_0                    (0U)
#define PORT_A_PIN_1                    (1U)
#define PORT_A_PIN_2                    (2U)
#define PORT_A_PIN_3                    (3U)
#define PORT_A_PIN_4                    (4U)
#define PORT_A_PIN_5                    (5U)
#define PORT_A_PIN_6                    (6U)
#define PORT_A_PIN_7                    (7U)

#define PORT_B_PIN_0                    (8U)
#define PORT_B_PIN_1                    (9U)
#define PORT_B_PIN_2                    (10U)
#define PORT_B_PIN_3                    (11U)
#define PORT_B_PIN_4                    (12U)
#define PORT_B_PIN_5                    (13U)
#define PORT_B_PIN_6                    (14U)
#define PORT_B_PIN_7                    (15U)

#define PORT_C_PIN_0                    (16U)
#define PORT_C_PIN_1                    (17U)
#define PORT_C_PIN_2                    (18U)
#define PORT_C_PIN_3                    (19U)
#define PORT_C_PIN_4                    (20U)
#define PORT_C_PIN_5                    (21U)
#define PORT_C_PIN_6                    (22U)
#define PORT_C_PIN_7                    (23U)

#define PORT_D_PIN_0                    (24U)
#define PORT_D_PIN_1                    (25U)
#define PORT_D_PIN_2                    (26U)
#define PORT_D_PIN_3                    (27U)
#define PORT_D_PIN_4                    (28U)
#define PORT_D_PIN_5                    (29U)
#define PORT_D_PIN_6                    (30U)
#define PORT_D_PIN_7                    (31U)

#define PORT_E_PIN_0                    (32U)
#define PORT_E_PIN_1                    (33U)
#define PORT_E_PIN_2                    (34U)
#define PORT_E_PIN_3                    (35U)
#define PORT_E_PIN_4                    (36U)
#define PORT_E_PIN_5                    (37U)
#define PORT_E_PIN_6                    (38U)
#define PORT_E_PIN_7                    (39U)

#define PORT_F_PIN_0                    (40U)
#define PORT_F_PIN_1                    (41U)
#define PORT_F_PIN_2                    (42U)
#define PORT_F_PIN_3                    (43U)
#define PORT_F_PIN_4                    (44U)
#define PORT_F_PIN_5                    (45U)
#define PORT_F_PIN_6                    (46U)
#define PORT_F_PIN_7                    (47U)

#endif /* MCAL_PORT_PORT_CFG_H_ */
