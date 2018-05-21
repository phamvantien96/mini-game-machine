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
	flood(BLACK, 240*320);

	WoodBox[0].Draw();
	WoodBox[1].Draw();
	WoodBox[2].Draw();
	WoodBox[3].Draw();

	while(1) {
		Delay1ms(30);
		Character.Draw();
		Character.Move(joystick_dir, 2);
		UARTCharPutNonBlocking(UART_BASE,	(uint8_t) (Character.point.x));
		UARTCharPutNonBlocking(UART_BASE,	(uint8_t) (Character.point.y));
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
	}
}
