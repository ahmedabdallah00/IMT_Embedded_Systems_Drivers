/*
 * EXTI_interface.h
 *
 *  Created on: Feb 12, 2024
 *      Author: Ahmad
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

#define EXTI_INT0 0
#define EXTI_INT1 1
#define EXTI_INT2 2

#define EXTI_FALLING  0
#define EXTI_RISING   1
#define EXTI_ONCHANGE 2
#define EXTI_LOWVL    3

void EXTI_Init(void);
void EXII_SetCallback(void (*Fptr)(void));
void EXTI_EnableInterrupt(u8 IntID);
void EXTI_DisableInterrupt(u8 IntID);
void EXTI_SenseControl(u8 IntID,u8 SenseCtrl);

#endif /* EXTI_EXTI_INTERFACE_H_ */
