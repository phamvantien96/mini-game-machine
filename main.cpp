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

extern uint32_t GetClosestTerrain(terr_idx_t _idx, dir_t _dir);

uint32_t ui32Value[2];

int main(void){
	System_Init();
	LCD_Reset();
	LCD_Begin();
	setAddrWindow(0, 0, 239, 319);
	flood(BLACK, 240*320);
	ADC_Init();


	while(1) {
		uint32_t tmp;
		tmp = GetClosestTerrain(43 , RIGHT);
		tmp = GetClosestTerrain(47 , RIGHT);

		tmp = GetClosestTerrain(43, LEFT);
		tmp = GetClosestTerrain(47, LEFT);

		tmp = GetClosestTerrain(35, UP);
		tmp = GetClosestTerrain(65, UP);

		tmp = GetClosestTerrain(35, DOWN);
		tmp = GetClosestTerrain(65, DOWN);

		tmp = GetClosestTerrain(43, 53, RIGHT);
		tmp = GetClosestTerrain(33, 43, RIGHT);
		tmp = GetClosestTerrain(23, 33, RIGHT);
		tmp = GetClosestTerrain(47, 57, RIGHT);

		tmp = GetClosestTerrain(43, 53, LEFT);
		tmp = GetClosestTerrain(47, 57, LEFT);
		tmp = GetClosestTerrain(23, 33, LEFT);
		tmp = GetClosestTerrain(23, 33, LEFT);

		tmp = GetClosestTerrain(35, 36, UP);
		tmp = GetClosestTerrain(65, 66, UP);
		tmp = GetClosestTerrain(64, 65, UP);
		tmp = GetClosestTerrain(63, 64, UP);

		tmp = GetClosestTerrain(35, 36, DOWN);
		tmp = GetClosestTerrain(65, 66, DOWN);
		tmp = GetClosestTerrain(34, 35, DOWN);
		tmp = GetClosestTerrain(63, 64, DOWN);
		Delay1ms(30);
//		ADCProcessorTrigger(ADC0_BASE, 2);
//		Thuy.Draw();
//		Thuy.Move(joystick_dir, 2);
	}
}
