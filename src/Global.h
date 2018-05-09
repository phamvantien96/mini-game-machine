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
#include "Terrain.h"

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */

///****************************************************************************
///
/// EXTERNAL VARIABLE
///
///****************************************************************************
extern Terrain WoodBox;
extern Entity Thuy;
extern dir_t joystick_dir;

///****************************************************************************
///
/// FUNCTION PROTOTYPE
///
///****************************************************************************
void Init(void);
	
#ifdef __cplusplus
}
#endif

#endif
