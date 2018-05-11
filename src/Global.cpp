/** @file Global.cpp
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#include "Global.h"

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

bool semaphore = 0;

Terrain WoodBox[16] =  {Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100),
						Terrain(1, img_wood_box, rand() % 100)};

Character Superman((point_t) {0, 48}, 1, img_superman, 1, 1, 1);

dir_t joystick_dir = STAY;

