/*
 * KEYPAD_program.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Ahmad
 */


#include "../STD_TYPES.h"

#include "../DIO/DIO_interface.h"
#include <util/delay.h>

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"


void KEYPAD_Init(void)
{
	DIO_SetPortDirection(KEYPAD_PORT, 0xf0);
	DIO_SetPortValue(KEYPAD_PORT, 0xff);
}

s32   KEYPAD_GetPressedKey(void)
{
	s32 pressed_key = 0;

	s32 column = 0;
	s32 row = 0 ;

	for(column=0; column < NO_COLS; column ++)
	{
		/* activate current column */
		DIO_SetPinValue(KEYPAD_PORT, column+4 ,DIO_LOW );

		for(row=0; row < NO_ROWS ; row++)
		{
			if(DIO_GetPinValue(KEYPAD_PORT,  row ) == DIO_LOW)
			{
				pressed_key = row + (column * NO_ROWS) + 1 ;
			}
			while(DIO_GetPinValue(KEYPAD_PORT,  row ) == DIO_LOW){}
			_delay_ms(DEBOUNCE_DELAY);
		}

		/* deactivate the current column */
		DIO_SetPinValue(KEYPAD_PORT, column+4 ,DIO_HIGH );
	}
	return pressed_key;
}
