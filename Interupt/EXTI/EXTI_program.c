/*
 * EXTI_program.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Ahmad
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "../DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*INT0_Callback)(void);

void EXII_SetCallback(void (*Fptr)(void))
{
	INT0_Callback= Fptr;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	INT0_Callback();
}

void EXTI_Init(void)
{

#if EXII_ENABLE_INT0 == ENABLE
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
#if EXII_SENSE_CONTROL_INT0 == EXII_FALLING
	/*senseing control*/
    SET_BIT(MCUCR,1);
    CLR_BIT(MCUCR,0);
#elif EXII_SENSE_CONTROL_INT0 == EXII_RISING
    SET_BIT(MCUCR,1);
    SET_BIT(MCUCR,0);
#elif EXII_SENSE_CONTROL_INT0 == EXII_ONCHANGE
	/*senseing control*/
    CLR_BIT(MCUCR,1);
    SET_BIT(MCUCR,0);
#elif EXII_SENSE_CONTROL_INT0 == EXII_LOWLVL
    CLR_BIT(MCUCR,1);
    CLR_BIT(MCUCR,0);

#endif

    /**/
    SET_BIT(GICR,6);
#endif

#if EXII_ENABLE_INT1 == DISABLE
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	/*senseing control*/
    SET_BIT(MCUCR,1);
    /**/
    SET_BIT(GICR,6);
#endif

#if EXII_ENABLE_INT2 == DISABLE
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	/*senseing control*/
    SET_BIT(MCUCR,1);
    /**/
    SET_BIT(GICR,6);
#endif

}


void EXTI_EnableInterrupt(u8 IntID)
{

}

void EXTI_DisableInterrupt(u8 IntID)
{

}

void EXTI_SenseControl(u8 IntID,u8 SenseCtrl)
{

}
