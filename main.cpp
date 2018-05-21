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

	Character Superman((point_t) {0, 48}, 1, superman, 6, 2, 1);
	Character Rival((point_t) {0, 48}, 1, superman, 6, 2, 1);

	for(int i = 0; i < 16; i++)
		WoodBox[i]->Draw();
	Superman.Draw();

	while(1) {
		Delay1ms(30);
		Superman.Draw();
		Superman.Move(joystick_dir, 2);
		UARTCharPutNonBlocking(UART_BASE,	(uint8_t) (Superman.point.x));
		UARTCharPutNonBlocking(UART_BASE,	(uint8_t) (Superman.point.y));
//		UARTCharPut(UART0_BASE, '\n');
//		UARTCharPut(UART0_BASE, 'x');
//		UARTCharPut(UART0_BASE, ':');
//		UARTCharPut(UART0_BASE,	(uint8_t) ((Character.point.x / 100) + 48));
//		UARTCharPut(UART0_BASE,	(uint8_t) ((Character.point.x / 10 % 10) + 48));
//		UARTCharPut(UART0_BASE,	(uint8_t) ((Character.point.x % 10) + 48));
//		UARTCharPut(UART0_BASE, ' ');
//		UARTCharPut(UART0_BASE, 'y');
//		UARTCharPut(UART0_BASE, ':');
//		UARTCharPut(UART0_BASE,	(uint8_t) ((Character.point.y / 100) + 48));
//		UARTCharPut(UART0_BASE,	(uint8_t) ((Character.point.y / 10 % 10) + 48));
//		UARTCharPut(UART0_BASE,	(uint8_t) ((Character.point.y % 10) + 48));
		uartPoint.x = uartNum[0];
		uartPoint.y = uartNum[1];
		Rival.SetPoint(uartPoint);
		Rival.Draw();
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
