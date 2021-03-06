/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */

#ifndef SRC_CHARACTER_H_
#define SRC_CHARACTER_H_

#include <vector>
#include <stdlib.h>
#include "Entity.h"
#include "Boom.h"

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
#define COL_IDX(x)				((x - X_MAP_OFFSET) / SQUARE_EDGE_PIXEL)
#define ROW_IDX(y)				((y - Y_MAP_OFFSET) / SQUARE_EDGE_PIXEL)

#define PIXEL_IDX_CALC(x, y)	(COL_IDX(x) + MAP_LENGTH * ROW_IDX(y))

///****************************************************************************
///
/// EXTERNAL VARIABLE AND FUNCTION
///
///****************************************************************************
extern coordinates_t GetClosestTerrain(terr_idx_t _idx_st,
									   terr_idx_t _idx_nd, dir_t _dir);
extern uint16_t * GetImageFromIdx(terr_idx_t idx);

///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Character:public Entity {
public:
	int8_t boomAmount;
	int8_t boomAmountCurr;
	int8_t boomLength;
	speed_t speed;
	std::vector<Boom> boomVector;
public:
	Character(point_t _point, life_t _life, image_t _image,
			  int8_t _boomAmount, int8_t _boomLength, speed_t _speed);
	void IncreaseBoomAmount();
	void IncreaseBoomLength();
	void IncreaseSpeed();
	void Move(dir_t _dir);
	void Move(dir_t _dir, distance_t distance);
	void SetBoom();
	void WaitBoomExplode();
	void BombChain(terr_idx_t idx);
};

#ifdef __cplusplus
}
#endif

#endif /* SRC_CHARACTER_H_ */
