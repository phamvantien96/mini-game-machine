/*
 * joystick.h
 *
 *  Created on: May 8, 2018
 *      Author: BKIC
 */
#ifndef SRC_JOYSTICK_H_
#define SRC_JOYSTICK_H_



#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/adc.h>
#include <inc/hw_memmap.h>
#include "definitions.h"

#define ADC_BASE 		ADC0_BASE
#define ADC_SEQUENCE 	2
#define ADC_INT_SS		ADC_INT_SS2
#define CH_X 			ADC_CTL_CH10
#define CH_X_STEP 		0
#define CH_Y 			ADC_CTL_CH8
#define CH_Y_STEP 		1

#if CH_Y_STEP
	#define CH_0 		CH_X
	#define CH_0_STEP 	CH_X_STEP
	#define CH_1 		ADC_CTL_IE | ADC_CTL_END | CH_Y
	#define CH_1_STEP 	CH_Y_STEP
#else
	#define CH_0 		CH_Y
	#define CH_0_STEP 	CH_Y_STEP
	#define CH_1 		ADC_CTL_IE | ADC_CTL_END | CH_X
	#define CH_1_STEP 	CH_X_STEP
#endif


void ADC_Init(void);
void Joystick_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* SRC_JOYSTICK_H_ */
