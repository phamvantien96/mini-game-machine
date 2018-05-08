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
#define SQUARE_SIZE 			24

/**
 * Marco calculate x, y from terrain index
 */
#define X_CALC(idx)				((idx % 10) * SQUARE_SIZE)
#define Y_CALC(idx)				((idx / 10) * SQUARE_SIZE + SQUARE_SIZE * 2)

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
