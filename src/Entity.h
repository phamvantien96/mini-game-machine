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
/// DEFINE AND MARCO
///
///****************************************************************************
/*
 * This two marco use for calculate column and row index on map
 */
#define COL_IDX(x)				((x - X_MAP_OFFSET) / SQUARE_SIZE_PIXEL)
#define ROW_IDX(y)				((y - Y_MAP_OFFSET) / SQUARE_SIZE_PIXEL)

#define PIXEL_IDX_CALC(x, y)	(COL_IDX(x) + MAP_LENGTH * ROW_IDX(y))

///****************************************************************************
///
/// EXTERNAL VARIABLE AND FUNCTION
///
///****************************************************************************
coordinates_t GetClosestTerrain(terr_idx_t _idx_st, terr_idx_t _idx_nd, dir_t _dir);

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
