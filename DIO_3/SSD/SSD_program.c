/*
 * SSD_program.c
 *
 *  Created on: Apr 29, 2022
 *      Author: mazen
 */

#include "../STD_TYPES.h"

/* custom includes */
//#include <avr/io.h>
#include "../DIO/DIO_interface.h"
/* driver includes  */
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


u8 numbers[] = {
		0b11111100,//0
		0b01100000,//1
		0b11011010,//2
		0b11110010,//3
		0b01100110,//4
		0b10110110,//5
		0b10111110,//6
		0b11100010,//7
		0b11111110,//8
		0b11110110,//9
	};

void SSD_Init(void)
{
//	SSD_DDR = 0xff ;
	DIO_SETPortDirection(SSD_PORT, 0x00);
}

void SSD_DisplayNumber(u8 num)
{

	if(num < 10)
	{

#if SSD_TYPE==COM_CATHODE
//		SSD_PORT = numbers[num];
		DIO_SETPortValue(SSD_PORT, numbers[num]);

#elif SSD_TYPE==COM_ANODE
//		SSD_PORT = ~ numbers[num];
		DIO_SETPortValue(SSD_PORT, ~ numbers[num]);
#else
#error "SSD Type should only be COM_CATHODE or COM_ANODE"
#endif
	}

}
