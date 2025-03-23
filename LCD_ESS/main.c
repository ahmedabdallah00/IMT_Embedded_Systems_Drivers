/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Ahmad
 */

#include  "STD_TYPES.h"
#include  "LCD/LCD_interface.h"

#include <util/delay.h>


#define EX1 0
#define EX2 0
#define EX3 0
#define EX4 0
#define EX5 1
#define EX6 0

int main(void)
{
	u8 heart[8]={
			0b00000000,
			0b00001010,
			0b00011111,
			0b00011111,
			0b00001110,
			0b00000100,
			0b00000000,
			0b00000000
	};

	u8 ALF_char[8]={
			0b00000110,
			0b00000100,
			0b00001110,
			0b00000000,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000100
	};

	u8 HAA_char[8]={
			0b00000000,
			0b00000000,
			0b00000000,
			0b00001110,
			0b00000001,
			0b00011110,
			0b00000000,
			0b00000000
		};

	u8 meam_char[8]={
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000,
				0b00011111,
				0b00001010,
				0b00001110
			};



	u8 dal_char[8]={
				0b00000000,
				0b00000000,
				0b00000100,
				0b00000010,
				0b00000001,
				0b00011111,
				0b00000000,
				0b00000000
			};


#if EX1
	u32 a=1181092;
	LCD_Init();
	LCD_PrintString("H");
	LCD_CLR_DIS();
	LCD_PrintString("AHMED");
	_delay_ms(1000);
	LCD_CLR_DIS();
    LCD_PrintString("ABDALLUH");
    _delay_ms(1000);
    LCD_CLR_DIS();
    LCD_PrintNum(a);
#endif
#if EX2
    LCD_Init();
    LCD_SaveCustomChar(3,heart);
    LCD_DisplayCoustmeChar(3);
    LCD_PrintString("Mostafa");
#endif
#if EX3
    LCD_Init();
    LCD_SaveCustomChar(3,heart);
    LCD_SetCursorPosition(4,1);
    LCD_DisplayCoustmeChar(3);

#endif
#if EX4
    LCD_Init();
    LCD_SaveCustomChar(0,heart);
        for(u8 j=0;j<2;j++)
    	{
        	for(u8 i=0;i<16;i++)
        	{
        		LCD_SetCursorPosition(i,j);
        		LCD_DisplayCoustmeChar(0);
        		_delay_ms(500);
        		LCD_CLR_DIS();

        	}

        }

#endif

#if EX5
    LCD_Init();
    LCD_SaveCustomChar(0,ALF_char);
    LCD_SetCursorPosition(15,0);
    LCD_DisplayCoustmeChar(0);
    LCD_SaveCustomChar(1,HAA_char);
    LCD_SetCursorPosition(14,0);
    LCD_DisplayCoustmeChar(1);
    LCD_SaveCustomChar(2,meam_char);
    LCD_SetCursorPosition(13,0);
    LCD_DisplayCoustmeChar(2);
    LCD_SaveCustomChar(3,dal_char);
    LCD_SetCursorPosition(12,0);
    LCD_DisplayCoustmeChar(3);
#endif

#if EX6
    LCD_Init();
    LCD_SaveCustomChar(0,ALF_char);
    LCD_SetCursorPosition(15,0);
    LCD_DisplayCoustmeChar(0);
    LCD_SaveCustomChar(1,HAA_char);
    LCD_SetCursorPosition(14,0);
    LCD_DisplayCoustmeChar(1);
    LCD_SaveCustomChar(2,meam_char);
    LCD_SetCursorPosition(13,0);
    LCD_DisplayCoustmeChar(2);
    LCD_SaveCustomChar(3,dal_char);
    LCD_SetCursorPosition(12,0);
    LCD_DisplayCoustmeChar(3);
#endif



	while(1)
	{

	}
}
