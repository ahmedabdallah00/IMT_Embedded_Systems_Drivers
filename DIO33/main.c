/*
 * main.c
 *
 *  Created on: Nov 27, 2022
 *      Author: Ahmad
 */


#include "STD_TYPES.h"
#include "SSD/SSD_Interface.h"
#include <util/delay.h>

int main(void)
{
	SSD_Init();
	while(1)
	{
		for(u8 i=0;i<6;i++)
		{
			/*
			for(u8 j=0;j<10;j++)
			{
				SSD_DisplayNumber(j);
				_delay_ms(1000);
			}*/

			SSD_DisplayNumber(i);
			_delay_ms(1000);
		}
	}
}



