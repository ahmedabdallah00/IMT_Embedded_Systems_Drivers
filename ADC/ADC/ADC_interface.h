/*
 * ADC_interface.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Ahmad
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

void ADC_Init(void);
ADC_ReadDigitalValue(u8 ChannelNo);
ADC_StartConversion(u8 ChannelNo);

#endif /* ADC_ADC_INTERFACE_H_ */
