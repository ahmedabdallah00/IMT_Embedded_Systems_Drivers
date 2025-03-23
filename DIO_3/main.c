/*
 * main.c
 *
 *  Created on: Nov 27, 2022
 *      Author: Ahmad
 */
#include <stdio.h>

#include "STD_TYPES.h"

#include <util/delay.h>
#include "SSD/SSD_interface.h"

int main(void)
{
	SSD_Init();
	while(1)
	{
        for(u8 i=0;i<10; i++)
        {
        	SSD_DisplayNumber(i);
        	_delay_ms(500);
        }
	}
}

