/*
 * ADC_private.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Ahmad
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

#define ADLAR 5
#define ADEN  7
#define ADSC  6
#define ADIF  4

#define ADMUX     *((volatile u8*)(0x27))
#define ADCSRA    *((volatile u8*)(0x26))
#define ADCL      *((volatile u8*)(0x25))
#define ADCH      *((volatile u8*)(0x24))
#define ADC_DATA  *((volatile u16*)(0x24))
#define SFIOR     *((volatile u8*)(0x50))

#endif /* ADC_ADC_PRIVATE_H_ */
