/** @file Global.h
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "image.h"
#include "Entity.h"
#include "Terrain.h"
#include "Character.h"
#include "lcd_driver.h"

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */

///****************************************************************************
///
/// EXTERNAL VARIABLE
///
///****************************************************************************
extern bool semaphore_systick;
extern bool semaphore_sw;
extern bool semaphore_uart;

extern uint8_t uart_rx_data;
extern Terrain* WoodBox[16];
extern dir_t joystick_dir;
extern dir_t uart_dir;
///****************************************************************************
///
/// FUNCTION PROTOTYPE
///
///****************************************************************************
void Delay1ms(uint32_t t);
void Delay1us(uint32_t t);
void DrawBackground(void);
void Map_Init(void);

#ifdef __cplusplus
}
#endif

#endif
