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


char uart_ch;
uint8_t led2;

int main(void) {
	System_Init();
	Communication_Init();
//	LCD_Reset();
//	LCD_Begin();
//	Joystick_Init();
//	setAddrWindow(0, 0, 239, 319);
//	flood(BLACK, 240*320);
//
//	WoodBox[0].Draw();
//	WoodBox[1].Draw();
//	WoodBox[2].Draw();
//	WoodBox[3].Draw();

	while(1) {
//		Delay1ms(30);
//		Character.Draw();
//		Character.Move(joystick_dir, 2);
//		UARTCharPut(UART0_BASE, 's');
	}
}
