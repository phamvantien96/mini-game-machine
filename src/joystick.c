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
	TimerLoadSet(TIMER0_BASE, TIMER_A, 3000);
	TimerLoadSet(TIMER0_BASE, TIMER_B, 4000);
	TimerEnable(TIMER0_BASE, TIMER_BOTH);
	TimerIntRegister(TIMER0_BASE, TIMER_A, Timer0A_Handler);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntRegister(TIMER0_BASE, TIMER_B, Timer0B_Handler);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);

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

void Timer0A_Handler(void)
{
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	ADCProcessorTrigger(ADC0_BASE, 2);
}


void Timer0B_Handler(void)
{
	TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
}

