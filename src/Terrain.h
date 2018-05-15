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
#define NULL_TERRAIN	-1

/**
 * Marco calculate x, y from terrain index
 */
#define X_CALC(idx)		((idx % MAP_WIDTH ) * SQUARE_EDGE_PIXEL + X_MAP_OFFSET)
#define Y_CALC(idx)		((idx / MAP_LENGTH) * SQUARE_EDGE_PIXEL + Y_MAP_OFFSET)

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************

///****************************************************************************
///
/// EXTERNAL VARIABLE
///
///****************************************************************************
extern map_t map_terrain[MAX_IDX];

///****************************************************************************
///
/// FUNCTION PROTOTYPE
///
///****************************************************************************
coordinates_t GetClosestTerrain(terr_idx_t _idx_st, terr_idx_t _idx_nd, dir_t _dir);
uint16_t * GetImageFromIdx(terr_idx_t idx);

///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Terrain:public Entity {
public:
	terr_idx_t terrainIdx;
public:
	Terrain();
	Terrain(life_t _life, image_t _image, terr_idx_t _terrainIdx, map_t _kindOfTerrain);
	~Terrain();
	void ChangeTerrainIdx(terr_idx_t _idx, map_t _kindOfTerrain);
	void Destroy();
};

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* SRC_TERRAIN_H_ */
