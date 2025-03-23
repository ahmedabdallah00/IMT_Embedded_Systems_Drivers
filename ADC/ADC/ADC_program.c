/*
 * ADC_program.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Ahmad
 */

#include "../BIT_MATH.h"
#include "../STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_Init(void)
{
	//ref selection
	SET_BIT(ADMUX,6);
	//left adjust
	CLR_BIT(ADMUX,ADLAR);
	//AUTO trigger Enable
    CLR_BIT(ADCSRA,5);

	CLR_BIT(ADCSRA,3);
	ADCSRA &=~(0b111);
	ADCSRA |= (0b110);
	//enable ADC
	SET_BIT(ADCSRA,ADEN);

}

ADC_ReadDigitalValue(u8 ChannelNo)
{
	//u16 digital_value;

	/*select channel*/
	ADMUX =(ADMUX & ~(0b00011111)) | ChannelNo ;
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
    /*Polling */
	while(GET_BIT(ADCSRA,ADIF) == 0){};
    /*clear ADC interrupt flag*/
    SET_BIT(ADCSRA,ADIF);
    /*return ADC digital value */
    return ADC_DATA;
}

ADC_StartConversion(u8 ChannelNo)
{

}
