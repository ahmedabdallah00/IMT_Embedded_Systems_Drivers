/*
 * EXTI_private.h
 *
 *  Created on: Feb 12, 2024
 *      Author: Ahmad
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define ENABLE   1
#define DISABLE  0

#define EXII_FALLING    2
#define EXII_RISING     3
#define EXII_ONCHANGE   1
#define EXII_LOWLVL     0

#define MCUCR   *((volatile u8*)(0x55))
#define MCUCSR  *((volatile u8*)(0x54))
#define GICR    *((volatile u8*)(0x5B))
#define GIFR    *((volatile u8*)(0x5A))

#endif /* EXTI_EXTI_PRIVATE_H_ */
