/*
 * main.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Ahmad
 */

#include "STD_TYPES.h"
#include "DIO/DIO_interface.h"

#include "KEYPAD/KEYPAD_interface.h"

#include "LCD/LCD_interface.h"
#include <util/delay.h>


#define DEBOUNCE_1 0
#define DEBOUNCE_2 0
#define KEYPAD_TEST 0
#define KEYPAD_LCD_TEST 1

int main(void)
{
    KEYPAD_Init();
    LCD_Init();
   // LCD_Init();
    DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

    s32  key=0;
    s32  number=1;

/*
if  DEBOUNCE_1 | DEBOUNCE_2
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
#endif*/

    while(1)
	{
#if DEBOUNCE_1
		if(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==0)
		{
			_delay_ms(20);
			if(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==0)
			{
				DIO_TogglePinValue(DIO_PORTB,DIO_PIN1);
		    }
		}

#endif

#if DEBOUNCE_2
		if(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==0)
		{


			while(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==0){};
			_delay_ms(20);
			DIO_TogglePinValue(DIO_PORTB,DIO_PIN1);

		}

#endif

#if KEYPAD_TEST
		key=KEYPAD_GetPressedKey();
		if(key!=0)
		{

			DIO_TogglePinValue(DIO_PORTA,DIO_PIN0);
			_delay_ms(1000);
		}


#endif

#if KEYPAD_LCD_TEST
		key=KEYPAD_GetPressedKey();
		if(key!=0)
		{

			LCD_PrintNum(key);

		}


#endif

        }
}
