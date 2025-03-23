/*
 * main.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Ahmad
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "EXTI/EXTI_interface.h"
#include "GIE/GIE_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void LedToggle(void)
{
	DIO_TogglePinValue(DIO_PORTA,DIO_PIN0);
}

int main(void)
{
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	EXTI_Init();
    EXII_SetCallback(&LedToggle);
	GIE_Enable();
	while(1)
	{

	}
}
