/*
 * main.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Ahmad
 */


#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO/DIO_interface.h"
#include "KEYPAD/KEYPAD_interface.h"


int main(void)
{
	KEYPAD_Init();
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);

	u8 key = 0;

/*
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_INPUT);
	DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_HIGH);*/

	while(1)
	{
		key = KEYPAD_GetPressedKey();
		if(key != 0)
		{
			DIO_TogglePinValue(DIO_PORTA, DIO_PIN7);
		}
/*
		if(DIO_GetPinValue(DIO_PORTC, DIO_PIN1) == 0)
		{
			while(DIO_GetPinValue(DIO_PORTC, DIO_PIN1) == 0){}
			_delay_ms(10);
			DIO_TogglePinValue(DIO_PORTC, DIO_PIN0);
		}*/
	}

}
