/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Ahmad
 */

#include  "STD_TYPES.h"
#include  "LCD/LCD_interface.h"

#include <util/delay.h>

int main(void)
{
	LCD_Init();
	LCD_PrintString("H");
	_delay_ms(1000);
	while(1)
	{

	}
}
