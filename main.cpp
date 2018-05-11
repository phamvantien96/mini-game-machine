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
	setAddrWindow(0, 0, 239, 319);
	flood(BLACK, 240*320);
	ADC_Init();

	int i, j;

	for(i = 0; i < 16; i++)
		WoodBox[i].Draw();
	Superman.Draw();

	i = 0;
	j = 0;

	while(1) {
		if(1 == semaphore)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore = 0;

			ADCProcessorTrigger(ADC0_BASE, 2);
			Superman.Move(joystick_dir);
			if(0 == i++ % 200)
			{
				Superman.IncreaseSpeed();
				WoodBox[j++].Destroy();
			}
		}
	}
}
