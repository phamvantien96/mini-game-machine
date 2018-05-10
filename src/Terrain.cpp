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
/** @breif GetClosestTerrain
 *
 *  Get the closest terrain form current index and follow one direction, this
 *  function can wrong if take wrong value index
 *
 *  @param _idx_st The first current index
 *  @param _idx_nd The second current index
 *  @param _dir The direction
 */
coordinates_t GetClosestTerrain(terr_idx_t _idx_st, terr_idx_t _idx_nd, dir_t _dir)
{

	coordinates_t closestCoordinate;

	switch (_dir) {
	case LEFT:
		/* Default value to left boundary of map if no terrain */
		closestCoordinate = X_MAP_OFFSET;

		/*
		 * Consider all terrain in a row with _idx and come from
		 * left direcion. It break when meet closest terrain
		 */
		while (0 != (_idx_st % MAP_WIDTH)) {
			_idx_st--;
			_idx_nd--;

			if (1 == map_terrain[_idx_st]) {
				/* Calculate right boundary of terrain */
				closestCoordinate = X_CALC(_idx_st) + SQUARE_SIZE_PIXEL;
				break;
			}

			if (1 == map_terrain[_idx_nd]) {
				/* Calculate right boundary of terrain */
				closestCoordinate = X_CALC(_idx_nd) + SQUARE_SIZE_PIXEL;
				break;
			}
		}
		break;
	case RIGHT:
		/* Default value to right boundary of map if no terrain */
		closestCoordinate = X_MAP_OFFSET + MAP_WIDTH * SQUARE_SIZE_PIXEL - 1;

		/*
		 * Consider all terrain in a row with _idx and come from
		 * left direcion. It break when meet closest terrain
		 */
		while ((MAP_WIDTH - 1) != _idx_st % MAP_WIDTH) {
			_idx_st++;
			_idx_nd++;

			if (1 == map_terrain[_idx_st]) {
				/* Calculate left boundary of terrain */
				closestCoordinate = X_CALC(_idx_st) - 1;
				break;
			}

			if (1 == map_terrain[_idx_nd]) {
				/* Calculate left boundary of terrain */
				closestCoordinate = X_CALC(_idx_nd) - 1;
				break;
			}
		}
		break;
	case UP:
		/* Default value to up boundary of map if no terrain */
		closestCoordinate = Y_MAP_OFFSET;

		/*
		 * Consider all terrain in a column with _idx and come from
		 * left direcion. It break when meet closest terrain
		 */
		while (0 != (_idx_st / MAP_LENGTH)) {
			_idx_st -= MAP_LENGTH;
			_idx_nd -= MAP_LENGTH;

			if (1 == map_terrain[_idx_st]) {
				/* Calculate down boundary of terrain */
				closestCoordinate = Y_CALC(_idx_st) + SQUARE_SIZE_PIXEL;
				break;
			}

			if (1 == map_terrain[_idx_nd]) {
				/* Calculate down boundary of terrain */
				closestCoordinate = Y_CALC(_idx_nd) + SQUARE_SIZE_PIXEL;
				break;
			}
		}
		break;
	case DOWN:
		/* Default value to down boundary of map if no terrain */
		closestCoordinate = Y_MAP_OFFSET + MAP_LENGTH * SQUARE_SIZE_PIXEL - 1;

		/*
		 * Consider all terrain in a row with _idx and come from
		 * left direcion. It break when meet closest terrain
		 */
		while ((MAP_LENGTH - 1) != _idx_st / MAP_LENGTH) {
			_idx_st += MAP_LENGTH;
			_idx_nd += MAP_LENGTH;

			if (1 == map_terrain[_idx_st]) {
				/* Calculate up boundary of terrain */
				closestCoordinate = Y_CALC(_idx_st) - 1;
				break;
			}

			if (1 == map_terrain[_idx_nd]) {
				/* Calculate up boundary of terrain */
				closestCoordinate = Y_CALC(_idx_nd) - 1;
				break;
			}
		}
		break;
	}

	return closestCoordinate;

}
