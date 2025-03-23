/*
 * DIO_interface.h
 *
 *  Created on: Sep 1, 2023
 *      Author: ziaad
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7






#define DIO_HIGH 1
#define DIO_LOW 0



void DIO_TogglePinValue(u8 PortNO,u8 PinNO);



void DIO_SetPinDirection(u8 PortNO,u8 PinNO,u8 Direction);
void DIO_SetPinValue(u8 PortNO,u8 PinNO,u8 Value);
u8 DIO_GetPinValue(u8 PortNO,u8 PinNO);


void DIO_SetPortDirection(u8 PortNO,u8 Direction);
void DIO_SetPortValue(u8 PortNO,u8 Value);
u8 DIO_GedPortValue(u8 PortNO);



#endif /* DIO_DIO_INTERFACE_H_ */
