/*
 * DIO_interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmad
 */

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_HIGH 1
#define DIO_LOW 0

void DIO_SetPinDirection(u8 PortNo,u8 PinNo,u8 Direction);
void DIO_SetPinValue(u8 PortNo,u8 PinNo,u8 Value);
u8 DIO_GetPinValue(u8 PortNo,u8 PinNo);

void DIO_SetPortDirection(u8 PortNo,u8 Direction);
void DIO_SetPortValue(u8 PortNo,u8 Value);
u8 DIO_GetPortValue(u8 PortNo);
