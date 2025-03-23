/*
 * LCD_interface.h
 *
 *  Created on: Sep 2, 2023
 *      Author: ziaad
 */

#ifndef LCD_LCD_INTERFACE_H_

#define LCD_LCD_INTERFACE_H_
#define LCD_CLR  0b00000001
void LCD_Init(void);
void LCD_SendCommand(u8 command);
void LCD_SendChar(char c);

void LCD_PrintString(char str[]);
void LCD_PrintNum(s32 num );
void LCD_CLR_DIS(void);
//custom character functions

void LCD_DisplayCoustmeChar(u8 adress);
void LCD_SaveCustomChar(u8 adress, u8 array[]);

void LCD_SetCursorPosition(u8 line_pose ,u8 line_no);
#endif /* LCD_LCD_INTERFACE_H_ */
