/** @file Terrain.cpp
 *  @author Tien.P.V
 *  @date 08-May-2018
 */

#include "Terrain.h"

uint8_t map_terrain[MAX_IDX] = {};

///****************************************************************************
///
/// CLASS FUNCTION IMPLEMENTATION
///
///****************************************************************************
Terrain::Terrain(life_t _life, image_t _image, terr_idx_t _terrainIdx)
:Entity((point_t) {X_CALC(_terrainIdx), Y_CALC(_terrainIdx)},
		_life, _image),
terrainIdx(_terrainIdx)
{
	map_terrain[_terrainIdx] = 1;
}

void Terrain::ChangeTerrainIdx(terr_idx_t _idx)
{
	terrainIdx = _idx;

	/* Update x, y follow index */
	point.x = X_CALC(terrainIdx);
	point.y = Y_CALC(terrainIdx);
}

///****************************************************************************
///
/// FUNCTION IMPLEMENTATION
///
///****************************************************************************
uint32_t GetCloseseTerrain(dir_t _dir)
{

}
