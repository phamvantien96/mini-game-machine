/** @file Global.cpp
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#include "Global.h"

unsigned long TimerCount;
unsigned long Semaphore;
unsigned long FrameCount=0;

void Delay1ms(uint32_t t){
	while(t--){
		uint16_t x = ONE_MSEC;
		while(x--);
	}
}

void Delay1us(uint32_t t){
	while(t--){
		uint16_t x = ONE_USEC;
		while(x--);
	}
}

Entity Thuy((point_t) {120-12, 160-16}, 1, img_thuy);
Terrain WoodBox(1, img_wood_box, 5);
dir_t joystick_dir = STAY;

