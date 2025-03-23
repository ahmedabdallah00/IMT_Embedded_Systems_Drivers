/*
 * main.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Ahmad
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "ADC/ADC_interface.h"
#include "LCD/LCD_interface.h"
#include<util/delay.h>


int main(void)
{
	LCD_Init();
	ADC_Init();
	u16 digital_value=0;
	u16 Tempreature=0;
	while(1)
	{
		digital_value = ADC_ReadDigitalValue(0);
		Tempreature = (500*digital_value)/1024;
		LCD_SendCommand(LCD_CLR);
		LCD_PrintNum(Tempreature);
		_delay_ms(1000);


	}
}


