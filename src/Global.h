/** @file Global.h
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "Entity.h"
#include "image.h"

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */

///****************************************************************************
///
/// EXTERNAL VARIABLE
///
///****************************************************************************

extern unsigned long TimerCount;
extern unsigned long Semaphore;
extern unsigned long FrameCount;

extern Entity Thuy;
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
