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
#include "Global.h"
#include "config.h"
#include "image.h"
#include "joystick.h"
#include "communication.h"

int main(void) {
	System_Init();
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

	Communication_Init();

	while(1) {
		if(1 == semaphore_systick)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_systick = 0;

			ADCProcessorTrigger(ADC_BASE, ADC_SEQUENCE);
			Main.Move(joystick_dir);
			Main.WaitBoomExplode();

			Rival.Move(uart_dir);
			Rival.WaitBoomExplode();

			UARTCharPut(UART_BASE, joystick_dir);
		}

		if(1 == semaphore_sw)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_sw = 0;

			Main.SetBoom();
			UARTCharPut(UART_BASE, AVAIL_BOMB);

		}

		if(1 == semaphore_uart)
		{
			/* Clear semaphore and wait for next interrupt */
			semaphore_uart = 0;

			if(uart_rx_data == AVAIL_BOMB)	Rival.SetBoom();
			else	uart_dir = (dir_t) uart_rx_data;
		}
	}
}
