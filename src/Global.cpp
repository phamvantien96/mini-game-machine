/** @file Global.cpp
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#include "Global.h"

///****************************************************************************
///
/// GLOBAL VARIABLE
///
///****************************************************************************
bool semaphore_systick = 0;
bool semaphore_sw	   = 0;
bool semaphore_uart	   = 0;

uint8_t uart_rx_data;

dir_t uart_dir;

Terrain* WoodBox[16] = {new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX),
						new Terrain(1, wood_box, rand() % 100, WOOD_BOX)};

dir_t joystick_dir = STAY;

point_t rival_point;
bool	rival_bomb;

///****************************************************************************
///
/// FUNCTION IMPLEMENT
///
///****************************************************************************
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
