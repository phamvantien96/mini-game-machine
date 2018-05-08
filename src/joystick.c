/*
 * joystick.c
 *
 *  Created on: May 8, 2018
 *      Author: BKIC
 */
#include "joystick.h"

extern uint32_t ui32Value[2];
extern dir_t joystick_dir;

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
{	uint32_t x, y;
	ADCIntClear(ADC_BASE, ADC_SEQUENCE);
	ADCSequenceDataGet(ADC_BASE, ADC_SEQUENCE, ui32Value);
	x = ui32Value[1];
	y = ui32Value[0];
	if (x>y) {
		if		((x+y)<4096 && y<1024)  joystick_dir = UP;
		else if ((x+y)>=4096 && x>3072) joystick_dir = RIGHT;
		else 							joystick_dir = STAY;
	} else {
		if		((x+y)<4096 && x<1024)  joystick_dir = LEFT;
		else if ((x+y)>=4096 && y>3072) joystick_dir = DOWN;
		else 							joystick_dir = STAY;
	}

}
