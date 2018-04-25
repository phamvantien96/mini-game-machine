/** @file main.c
 *  @author Tien.P.V
 *  @date 24-Apr-2018
 */

#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>
#include "config.h"
#include "lcd_driver.h"

int main(void){
	System_Init();
	GPIO_Init();
	LCD_init();
	LCD_reset();
	LCD_begin();
	setRotation(0);
	while(1) {
		drawPixel(10, 20, RED);
		drawPixel(11, 20, RED);
		drawPixel(11, 21, RED);
		drawPixel(10, 21, RED);

		drawFastHLine(50, 50, 100, RED);
		SysTick_Wait1ms(50);
	}
}
