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
/**
 * Marco calculate x, y from terrain index
 */
#define X_CALC(idx)		((idx % MAP_WIDTH ) * SQUARE_SIZE_PIXEL + X_MAP_OFFSET)
#define Y_CALC(idx)		((idx / MAP_LENGTH) * SQUARE_SIZE_PIXEL + Y_MAP_OFFSET)

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************

///****************************************************************************
///
/// EXTERNAL VARIABLE AND FUNCTION
///
///****************************************************************************
extern "C++" uint32_t GetClosestTerrain(terr_idx_t _idx, dir_t _dir);
extern "C++" uint32_t GetClosestTerrain(terr_idx_t _idx_st,
										terr_idx_t _idx_nd,
										dir_t      _dir   );

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
