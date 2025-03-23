/*
 * DIO_program.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmad
 */


#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_SetPinDirection(u8 PortNo,u8 PinNo,u8 Direction)
{
    if(Direction == DIO_OUTPUT)
    {
      switch(PortNo)
      {
      case  DIO_PORTA:
    	  SET_BIT(DDRA,PinNo);
    	  break;
      case  DIO_PORTB:
    	  SET_BIT(DDRB,PinNo);
    	  break;
      case  DIO_PORTC:
          SET_BIT(DDRC,PinNo);
          break;
      case  DIO_PORTD:
          SET_BIT(DDRD,PinNo);
          break;
      }
    }
    else if(Direction == DIO_INPUT)
    {
       switch(PortNo)
       {
       case  DIO_PORTA:
           CLR_BIT(DDRA,PinNo);
            break;
       case  DIO_PORTB:
           CLR_BIT(DDRB,PinNo);
           break;
       case  DIO_PORTC:
           CLR_BIT(DDRC,PinNo);
           break;
       case  DIO_PORTD:
           CLR_BIT(DDRD,PinNo);
           break;
       }
    }
}

void DIO_SetPinValue(u8 PortNo,u8 PinNo,u8 Value)
{
    if(Value == DIO_HIGH)
    {
      switch(PortNo)
      {
      case  DIO_PORTA:
    	  SET_BIT(PORTA,PinNo);
    	  break;
      case  DIO_PORTB:
    	  SET_BIT(PORTB,PinNo);
    	  break;
      case  DIO_PORTC:
          SET_BIT(PORTC,PinNo);
          break;
      case  DIO_PORTD:
          SET_BIT(PORTD,PinNo);
          break;
      }
    }
    else if(Value == DIO_LOW)
    {
       switch(PortNo)
       {
       case  DIO_PORTA:
           CLR_BIT(PORTA,PinNo);
            break;
       case  DIO_PORTB:
           CLR_BIT(PORTB,PinNo);
           break;
       case  DIO_PORTC:
           CLR_BIT(PORTC,PinNo);
           break;
       case  DIO_PORTD:
           CLR_BIT(PORTD,PinNo);
           break;
       }
    }
}


u8 DIO_GetPinValue(u8 PortNo,u8 PinNo)
{
    u8 pin_value=0;
	switch(PortNo)
    {
    case  DIO_PORTA:
      pin_value=GET_BIT(PINA,PinNo);
  	  break;
    case  DIO_PORTB:
      pin_value=GET_BIT(PINB,PinNo);
  	  break;
    case  DIO_PORTC:
      pin_value=GET_BIT(PINC,PinNo);
      break;
    case  DIO_PORTD:
      pin_value=GET_BIT(PIND,PinNo);
      break;
    }
	return pin_value;
}

void DIO_SetPortDirection(u8 PortNo,u8 Direction)
{

      switch(PortNo)
      {
      case  DIO_PORTA:
    	  DDRA=Direction;
    	  break;
      case  DIO_PORTB:
    	  DDRB=Direction;
    	  break;
      case  DIO_PORTC:
    	  DDRC=Direction;
          break;
      case  DIO_PORTD:
    	  DDRD=Direction;
          break;
      }

}
void DIO_SetPortValue(u8 PortNo,u8 Value)
{

    switch(PortNo)
    {
    case  DIO_PORTA:
  	  PORTA=Value;
  	  break;
    case  DIO_PORTB:
      PORTB=Value;
  	  break;
    case  DIO_PORTC:
      PORTC=Value;
      break;
    case  DIO_PORTD:
      PORTD=Value;
      break;
    }
}
u8 DIO_GetPortValue(u8 PortNo)
{
    u8 port_value=0;
	switch(PortNo)
    {
    case  DIO_PORTA:
      port_value=PINA;
  	  break;
    case  DIO_PORTB:
      port_value=PINB;
  	  break;
    case  DIO_PORTC:
      port_value=PINC;
      break;
    case  DIO_PORTD:
      port_value=PIND;
      break;
    }
	return port_value;
}
