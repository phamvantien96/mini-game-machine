/** @file main.c
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#include <stdint.h>
#include <stdbool.h>
#include "image.h"
#include "lcd_driver.h"
#include "definitions.h"

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */
///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Entity {
public:
	point_t point;
	image_t image;
	life_t life;
public:
	Entity(image_t _image);
	Entity(point_t _point, life_t _life, image_t _image);
	void SetPoint(point_t _point);
	point_t GetPoint(Entity);
	void Move(dir_t _dir, distance_t distance);
	void Draw();
	void Clear();
	void Destroy();
};

#ifdef __cplusplus
}
#endif

#endif
