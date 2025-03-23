/*
 * DIO_program.c
 *
 *  Created on: Feb 13, 2023
 *      Author: Ahmad
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_SETPinDirection(u8 portno , u8 pinno, u8 direction)
{
	if(direction == DIO_OUTPUT)
	{
		switch(portno)
			{
			case DIO_PORTA:
				SET_BIT(DDRA,pinno);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB,pinno);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC,pinno);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD,pinno);
				break;
			}
	 }
	else if(direction == DIO_INPUT)
	{
		switch(portno)
		   {
			case DIO_PORTA:
				CLR_BIT(DDRA,pinno);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB,pinno);
				break;
			case DIO_PORTC:
				CLR_BIT(DDRC,pinno);
				break;
			case DIO_PORTD:
				CLR_BIT(DDRD,pinno);
				break;
			}
	}
}
void DIO_SETPinValue(u8 portno , u8 pinno, u8 value)
{
	if(value == DIO_HIGH)
		{
			switch(portno)
				{
				case DIO_PORTA:
					SET_BIT(PORTA,pinno);
					break;
				case DIO_PORTB:
					SET_BIT(PORTB,pinno);
					break;
				case DIO_PORTC:
					SET_BIT(PORTC,pinno);
					break;
				case DIO_PORTD:
					SET_BIT(PORTD,pinno);
					break;
				}
		 }
		else if(value == DIO_LOW)
		{
			switch(portno)
			   {
				case DIO_PORTA:
					CLR_BIT(PORTA,pinno);
					break;
				case DIO_PORTB:
					CLR_BIT(PORTB,pinno);
					break;
				case DIO_PORTC:
					CLR_BIT(PORTC,pinno);
					break;
				case DIO_PORTD:
					CLR_BIT(PORTD,pinno);
					break;
				}
		}
}
u8 DIO_GETPinValue(u8 portno , u8 pinno)
{
       u8 pin_value =0;
	   switch(portno)
       {
       case DIO_PORTA:
    	   pin_value= GET_BIT(PINA,pinno);
    	   break;
       case DIO_PORTB:
    	   pin_value= GET_BIT(PINB,pinno);
    	   break;
       case DIO_PORTC:
           pin_value= GET_BIT(PINC,pinno);
           break;
       case DIO_PORTD:
           pin_value= GET_BIT(PIND,pinno);
           break;
       }
	   return pin_value;
}

void DIO_SETPortDirection(u8 portno, u8 direction)
{
	switch(portno)
	{
	 case DIO_PORTA:
	    DDRA =direction ;
	    break;
	 case DIO_PORTB:
		DDRB =direction ;;
	    break;
	 case DIO_PORTC:
	    DDRC =direction ;
	    break;
	 case DIO_PORTD:
		DDRD =direction ;;
	    break;
	 }
}
void DIO_SETPortValue(u8 portno , u8 value)
{
	switch(portno)
	{
	case DIO_PORTA:
		DDRA =value ;
		break;
	case DIO_PORTB:
		DDRB =value ;
		break;
	case DIO_PORTC:
		DDRC =value ;
		break;
	case DIO_PORTD:
		DDRD =value ;
		break;
	}
}
u8 DIO_GETPortValue(u8 portno )
{
    u8 port_value =0;
	   switch(portno)
    {
    case DIO_PORTA:
    	port_value= PINA;
 	   break;
    case DIO_PORTB:
    	port_value= PINB;
 	   break;
    case DIO_PORTC:
    	port_value= PINC;
        break;
    case DIO_PORTD:
    	port_value= PIND;
        break;
    }
	   return port_value;
}
