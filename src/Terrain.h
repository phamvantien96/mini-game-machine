/** @file Terrain.h
 *  @author Tien.P.V
 *  @date 08-May-2018
 */

#ifndef SRC_TERRAIN_H_
#define SRC_TERRAIN_H_

#include "Entity.h"

#ifdef __cplusplus
extern "C"
{
#endif  /* __cplusplus */
///****************************************************************************
///
/// DEFINE AND MARCO
///
///****************************************************************************
#define SQUARE_SIZE_PIXEL 			24

#define MAP_WIDTH					10
#define MAP_HEIGHT					10
#define MAX_IDX						(MAP_WIDTH * MAP_HEIGHT)
#define Y_MAP_OFFSET				48
#define X_MAP_OFFSET				0

/**
 * Marco calculate x, y from terrain index
 */
#define X_CALC(idx)		((idx % MAP_WIDTH ) * SQUARE_SIZE_PIXEL + X_MAP_OFFSET)
#define Y_CALC(idx)		((idx / MAP_HEIGHT) * SQUARE_SIZE_PIXEL + Y_MAP_OFFSET)

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************
/**
 *  Terrain index read from left to right, up to down
 */
typedef uint8_t terr_idx_t;

///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Terrain:public Entity {
private:
	terr_idx_t terrainIdx;
public:
	Terrain(life_t _life, image_t _image, terr_idx_t _terrainIdx);
	void ChangeTerrainIdx(terr_idx_t _idx);
};

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* SRC_TERRAIN_H_ */
