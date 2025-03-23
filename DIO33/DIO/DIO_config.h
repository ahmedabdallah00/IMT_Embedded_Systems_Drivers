/*
 * DIO_config.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmad
 */

#ifndef DIO_DIO_CONFIG_H_
#define DIO_DIO_CONFIG_H_

void DIO_SetPinDirection(u8 PortNo,u8 PinNo,u8 Direction);
void DIO_SetPinValue(u8 PortNo,u8 PinNo,u8 Value);
u8 DIO_GetPinValue(u8 PortNo,u8 PinNo);

void DIO_SetPortDirection(u8 PortNo,u8 Direction);
void DIO_SetPortValue(u8 PortNo,u8 Value);
u8 DIO_GetPortValue(u8 PortNo);


#endif /* DIO_DIO_CONFIG_H_ */
