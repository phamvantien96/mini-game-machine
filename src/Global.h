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

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */

///****************************************************************************
///
/// EXTERNAL VARIABLE
///
///****************************************************************************
extern bool semaphore;
extern Boom WaterBoom;
extern Terrain* WoodBox[16];
extern Character Superman;
extern dir_t joystick_dir;

///****************************************************************************
///
/// FUNCTION PROTOTYPE
///
///****************************************************************************
void Init(void);
void Delay1ms(uint32_t t);
void Delay1us(uint32_t t);

#ifdef __cplusplus
}
#endif

#endif
