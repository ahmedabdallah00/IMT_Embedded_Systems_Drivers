/*
 * LCD_program.c
 *
 *  Created on: Sep 2, 2023
 *      Author: ziaad
 */
#include"../STD_TYPES.h"
#include"../DIO/DIO_interface.h"
#include<util/delay.h>




#include"LCD_interface.h"
#include"LCD_private.h"
#include"LCD_config.h"





void LCD_SendCommand(u8 command)
{
	//1-Set RS pin --> low
	DIO_SetPinValue( LCD_CTRL_PORT ,LCD_RS_PIN , DIO_LOW);
	//Set RW pin-->low
	DIO_SetPinValue(LCD_CTRL_PORT ,LCD_RW_PIN , DIO_LOW);
	//3-Set DB pins
	DIO_SetPortValue(LCD_DATA_PORT , command);
	//4-Send an enable pulse
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
		_delay_ms(1);
}
void LCD_SendChar(char c)
{
	//1-Set RS pin --> High
		DIO_SetPinValue(LCD_CTRL_PORT ,LCD_RS_PIN , DIO_HIGH);
		//Set RW pin-->low
		DIO_SetPinValue(LCD_CTRL_PORT ,LCD_RW_PIN , DIO_LOW);
		//3-Set DB pins
		DIO_SetPortValue(LCD_DATA_PORT , c);
		//4-Send an enable pulse
		DIO_SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
			_delay_ms(1);
}

void LCD_Init(void)
{
	//set lcd ctrl port&
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);
    DIO_SetPortDirection(LCD_DATA_PORT,0xff);
    _delay_ms(100);
    LCD_SendCommand(0b00111000);
    _delay_ms(1);
    LCD_SendCommand(0b00001100);
    _delay_ms(1);
    LCD_SendCommand(0b00000001);
    _delay_ms(3);
    LCD_SendCommand(0b00000110);
	_delay_ms(5);

}


void LCD_PrintString(char str[])
{

	for(u32 i=0; str[i] !='\0' ; i++)
	{

		LCD_SendChar(str[i]);
		_delay_ms(300);

	}


}


void LCD_PrintNum(s32 num )
{
	u8 digits[11]={0} ;
	//Extract each digits in the array (reversed)
	s8 i = 0;
	while (num>0)
	{
	digits[i]= num%10 ;
	num/=10 ; //shift right
    i++;
	}
	for(s8 j =i-1 ;j>=0;j--)
	{
		LCD_SendChar(digits[j]+'0');

	}


}

void LCD_CLR_DIS(void)
{
	 LCD_SendCommand(LCD_CLR);
}



void LCD_DisplayCoustmeChar(u8 adress)
{
	if(adress<8)
	{
		LCD_SendChar(adress);
	}
}



void LCD_SaveCustomChar(u8 adress, u8 array[])
{
	/*
	if (adress<8)
	{
		LCD_SendCommand(0b01000000 +(adress*8))	;

	for ( u8 i =0 ;i<8;i++)
	{
		LCD_SendChar(array[i]);
	}

    LCD_SendCommand(0b10000000);//talk with DDRAM
	}*/

	if(adress<8)
	{
		LCD_SendCommand(0b01000000 +(adress*8));
		for(u8 i=0;i<8;i++)
		{
			LCD_SendChar(array[i]);//save array at CGRAM
		}
		LCD_SendCommand(0b10000000);//display
	}
}


void LCD_SetCursorPosition(u8 line_pose ,u8 line_no)
{
	switch(line_no)
	{
	case 0:
		LCD_SendCommand(0b10000000+line_pose);
		break;
	case 1:
		LCD_SendCommand(0b10000000+line_pose+64);
			break;


	}

}






















