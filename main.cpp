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
#include "joystick.h"
#include "Global.h"

uint32_t ui32Value[2];

int main(void){
	System_Init();
	LCD_Reset();
	LCD_Begin();
	ADC_Init();
	flood(WHITE, TFTHEIGHT*TFTWIDTH);

	Character Superman((point_t) {0, 48}, 1, superman, 6, 1, 1);

	for(int i = 0; i < 16; i++)
		WoodBox[i]->Draw();
	Superman.Draw();

	while(1) {
		if(1 == semaphore_systick)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_systick = 0;

			ADCProcessorTrigger(ADC0_BASE, 2);
			Superman.Move(joystick_dir);
			Superman.WaitBoomExplode();
		}

		if(1 == semaphore_sw)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_sw = 0;

			Superman.SetBoom();
		}
	}
}
