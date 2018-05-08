/*
 * joystick.c
 *
 *  Created on: May 8, 2018
 *      Author: BKIC
 */
#include "joystick.h"

extern uint32_t ui32Value[2];

void ADC_Init(void)
{
	//
	// Enable the ADC0 module.
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	//
	// Wait for the ADC0 module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
	{ }
	//
	// Enable the first sample sequencer to capture the value of channel 0 when
	// the processor trigger occurs.
	//
	ADCSequenceConfigure(ADC_BASE, ADC_SEQUENCE, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC_BASE, ADC_SEQUENCE, CH_0_STEP, CH_0);
	ADCSequenceStepConfigure(ADC_BASE, ADC_SEQUENCE, CH_1_STEP, CH_1);
	ADCSequenceEnable(ADC_BASE, ADC_SEQUENCE);
	ADCIntRegister(ADC_BASE, ADC_SEQUENCE, Joystick_Handler);
	ADCIntEnableEx(ADC_BASE, ADC_INT_SS);
	ADCIntEnable(ADC_BASE, ADC_SEQUENCE);
}

void Joystick_Handler(void)
{
	ADCIntClear(ADC_BASE, ADC_SEQUENCE);
	ADCSequenceDataGet(ADC_BASE, ADC_SEQUENCE, ui32Value);
}
