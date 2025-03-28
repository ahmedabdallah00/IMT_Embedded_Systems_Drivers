/*
 * SSD_Program.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmad
 */

#ifndef SSD_SSD_PROGRAM_C_
#define SSD_SSD_PROGRAM_C_


#include "../STD_TYPES.h"

#include "../DIO/DIO_interface.h"

#include "SSD_Interface.h"
#include "SSD_config.h"


u8 numbers[]={
    		0b11111100,//0
			0b00001100,//1
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
//	SSD_DDR= 0xff;
	DIO_SetPortDirection(SSD_PORT,0xff);

}

void SSD_DisplayNumber(u8 number)
{
   if(number<10)
   {
#if  SSD_TYPE == COM_CATHODE
		//SSD_PORT = numbers[number];
	    DIO_SetPortValue(SSD_PORT,numbers[number]);
#elif  SSD_TYPE == COM_ANODE
	//	SSD_PORTA = ~(numbers[number]);
		DIO_SetPortValue(SSD_PORT,~(numbers[number]));
#else
#error "SSD type should be only COM_CATHODE or COM_ANODE"
#endif

   }

}
/*
void SSD_clock(u8 limit)
{
	if(limit<6)
	   {
#if  SSD_TYPE == COM_CATHODE
			SSD_PORTB = numbers[limit];

#endif

#if  SSD_TYPE == COM_ANODE
			SSD_PORTB = ~(numbers[number]);
#endif
	   }
}
*/
#endif /* SSD_SSD_PROGRAM_C_ */
