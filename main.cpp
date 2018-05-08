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
#include "Entity.h"
#include "Global.h"

int main(void){
	System_Init();
	LCD_init();
	LCD_reset();
	LCD_begin();
	setRotation(0);
	int i;

	for(i = 0; i < 100; i++)
	{
		WoodBox.ChangeTerrainIdx(i);
		WoodBox.Draw();
		SysTick_Wait1ms(100);
	}

	while(1) {
		Thuy.Draw();
		SysTick_Wait1ms(1000/30);
		Thuy.Move(rand()%4, 1);
	}
}
