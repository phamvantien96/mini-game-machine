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
#include "communication.h"

#define	CONSOLE_ID	1

char uartNum[2];
point_t uartPoint;

int main(void) {
	System_Init();
	Communication_Init();
	LCD_Reset();
	LCD_Begin();
	Joystick_Init();
	setAddrWindow(0, 0, 239, 319);
	flood(WHITE, TFTHEIGHT*TFTWIDTH);

#if		(CONSOLE_ID == 1)
	Character Main	((point_t) {0, 48}, 1, superman,	6, 2, 1);
	Character Rival	((point_t) {0, 48}, 1, batman,		6, 2, 1);
#else
	Character Main	((point_t) {0, 48}, 1, batman,		6, 2, 1);
	Character Rival	((point_t) {0, 48}, 1, superman,	6, 2, 1);
#endif

	for(int i = 0; i < 16; i++)
		WoodBox[i]->Draw();
	Main.Draw();

	while(1) {



		if(1 == semaphore_systick)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_systick = 0;

			ADCProcessorTrigger(ADC0_BASE, 2);
			Main.Move(joystick_dir);
			Main.WaitBoomExplode();
			UARTCharPutNonBlocking(UART_BASE,	(uint8_t) (Main.point.x));
			UARTCharPutNonBlocking(UART_BASE,	(uint8_t) (Main.point.y));
			uartPoint.x = uartNum[0];
			uartPoint.y = uartNum[1];
			Rival.SetPoint(uartPoint);
			Rival.Draw();
		}

		if(1 == semaphore_sw)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_sw = 0;

			Main.SetBoom();
		}
	}
}
