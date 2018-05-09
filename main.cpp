/** @file main.cpp
 *  @author Tien.P.V
 *  @date 24-Apr-2018
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>
#include "config.h"
#include "image.h"
#include "Global.h"
#include "joystick.h"

uint32_t ui32Value[2];

int main(void){
	System_Init();
	LCD_Reset();
	LCD_Begin();
	setAddrWindow(0, 0, 239, 319);
	flood(BLACK, 240*320);
	ADC_Init();
	Thuy.Draw();
	while(1) {
		Delay1ms(30);
		ADCProcessorTrigger(ADC0_BASE, 2);
		Thuy.Draw();
		Thuy.Move(joystick_dir, 2);
	}
}
