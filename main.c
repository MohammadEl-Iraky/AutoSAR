/*
 * main.c
 *
 *  Created on: Mar 20, 2020
 *      Author: super
 */

#include "MCAL/PORT/Port.h"
#include "MCAL/DIO/Dio.h"


int main(void)
{
    Port_Init(&Port_Configuration);
    Dio_Init(&Dio_Configuration);
    while(1)
    {

    }
}
