 /*
 * DIO_program.c

 *
 *  Created on: Sep 1, 2023
 *      Author: ziaad
 */
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "DIO_interface.h"//1
#include "DIO_priv.h"//2
#include "DIO_config.h"






void DIO_TogglePinValue(u8 PortNO,u8 PinNO)
{
	switch(PortNO)
	{
	case(DIO_PORTA):
			TOG_BIT(PORTA,PinNO);
	break;

	case(DIO_PORTB):
				TOG_BIT(PORTB,PinNO);
		break;

	case(DIO_PORTC):
				TOG_BIT(PORTC,PinNO);
		break;

	case(DIO_PORTD):
				TOG_BIT(PORTD,PinNO);
		break;


	}





}

void DIO_SetPinDirection(u8 PortNO,u8 PinNO,u8 Direction)

{
	if(Direction==DIO_OUTPUT)
	{
		switch(PortNO)
			{
			case DIO_PORTA:
				SET_BIT(DDRA,PinNO);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB,PinNO);
					break;
			case DIO_PORTC:
				SET_BIT(DDRC,PinNO);
					break;
			case DIO_PORTD:
				SET_BIT(DDRD,PinNO);
					break;
			}
	}
	else if (Direction==DIO_INPUT)
    {
		switch(PortNO)
			{
			case DIO_PORTA:
				CLR_BIT(DDRA,PinNO);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB,PinNO);
					break;
			case DIO_PORTC:
				CLR_BIT(DDRC,PinNO);
					break;
			case DIO_PORTD:
				CLR_BIT(DDRD,PinNO);
					break;
	}
 }
}
 void DIO_SetPinValue(u8 PortNO,u8 PinNO,u8 Value)

{

	if(Value==DIO_HIGH)
		{
			switch(PortNO)
				{
				case DIO_PORTA:
					SET_BIT(PORTA,PinNO);
					break;
				case DIO_PORTB:
					SET_BIT(PORTB,PinNO);
						break;
				case DIO_PORTC:
					SET_BIT(PORTC,PinNO);
						break;
				case DIO_PORTD:
					SET_BIT(PORTD,PinNO);
						break;
				}
		}
		else if (Value==DIO_LOW)
			{
			switch(PortNO)
				{
				case DIO_PORTA:
					CLR_BIT(PORTA,PinNO);
					break;
				case DIO_PORTB:
					CLR_BIT(PORTB,PinNO);
						break;
				case DIO_PORTC:
					CLR_BIT(PORTC,PinNO);
						break;
				case DIO_PORTD:
					CLR_BIT(PORTD,PinNO);
						break;
			}
			}
}
u8 DIO_GetPinValue(u8 PortNO,u8 PinNO)
{
	u8 pin_value =0 ;

	switch(PortNO)
	{
	case DIO_PORTA:
		pin_value=GET_BIT(PINA,PinNO);
		break;
	case DIO_PORTB:
		pin_value=GET_BIT(PINB,PinNO);
		break;
	case DIO_PORTC:
		pin_value=GET_BIT(PINC,PinNO);
		break;
	case DIO_PORTD:
		pin_value=GET_BIT(PIND,PinNO);
		break;
	  }

	return pin_value;
}


void DIO_SetPortDirection(u8 PortNO,u8 Direction)
{


	switch(PortNO)
	{
	case DIO_PORTA:
		DDRA=Direction;
		break;
	case DIO_PORTB:
			DDRB=Direction;
			break;
	case DIO_PORTC:
			DDRC=Direction;
			break;
	case DIO_PORTD:
			DDRD=Direction;
			break;
	}


}
 void DIO_SetPortValue(u8 PortNO,u8 Value)
{

	switch(PortNO)
		{
		case DIO_PORTA:
			PORTA=Value;
			break;
		case DIO_PORTB:
			PORTB=Value;
				break;
		case DIO_PORTC:
			PORTC=Value;
				break;
		case DIO_PORTD:
			PORTD=Value;
				break;
		}
}
u8 DIO_GetdPortValue(u8 PortNO)
{
	u8 port_value=0;
	switch(PortNO)
	{
	case DIO_PORTA:
		port_value=PINA ;
		break;
	case DIO_PORTB:
			port_value=PINB ;
			break;
	case DIO_PORTC:
			port_value=PINC ;
			break;
	case DIO_PORTD:
			port_value=PIND ;
			break;
	}
	return port_value;
}




