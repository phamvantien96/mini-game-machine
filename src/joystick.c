/*
 * joystick.c
 *
 *  Created on: May 8, 2018
 *      Author: BKIC
 */
#include "joystick.h"

extern dir_t joystick_dir;

void Joystick_Init(void)
{
	//
	// Enable the ADC0 module.
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
	{ }
	ADCSequenceConfigure(ADC_BASE, ADC_SEQUENCE, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC_BASE, ADC_SEQUENCE, CH_0_STEP, CH_0);
	ADCSequenceStepConfigure(ADC_BASE, ADC_SEQUENCE, CH_1_STEP, CH_1);
	ADCSequenceEnable(ADC_BASE, ADC_SEQUENCE);
	ADCIntRegister(ADC_BASE, ADC_SEQUENCE, Joystick_Handler);
	ADCIntEnableEx(ADC_BASE, ADC_INT_SS);
	ADCIntEnable(ADC_BASE, ADC_SEQUENCE);

	//
	// Enable the Timer0 peripheral
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0))
	{ }
	TimerConfigure(TIMER0_BASE, (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC));
	TimerLoadSet(TIMER0_BASE, TIMER_A, 65535);
	TimerLoadSet(TIMER0_BASE, TIMER_B, 65535);
	TimerEnable(TIMER0_BASE, TIMER_BOTH);
	TimerIntRegister(TIMER0_BASE, TIMER_A, Timer0A_Handler);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntRegister(TIMER0_BASE, TIMER_B, Timer0B_Handler);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);

}

uint32_t ui32Value[2];
void Joystick_Handler(void)
{
	ADCIntClear(ADC_BASE, ADC_SEQUENCE);
	ADCSequenceDataGet(ADC_BASE, ADC_SEQUENCE, ui32Value);

	if (ui32Value[1]>ui32Value[0]) {
		if		((ui32Value[1]+ui32Value[0])<4096 && ui32Value[0]<1024)
			joystick_dir = UP;
		else if ((ui32Value[1]+ui32Value[0])>=4096 && ui32Value[1]>3072)
			joystick_dir = RIGHT;
		else
			joystick_dir = STAY;
	} else {
		if		((ui32Value[1]+ui32Value[0])<4096 && ui32Value[1]<1024)
			joystick_dir = LEFT;
		else if ((ui32Value[1]+ui32Value[0])>=4096 && ui32Value[0]>3072)
			joystick_dir = DOWN;
		else
			joystick_dir = STAY;
	}
}

void Timer0A_Handler(void)
{
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//	ADCProcessorTrigger(ADC0_BASE, 2);
}


void Timer0B_Handler(void)
{
	TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
}

