/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */

#include "Boom.h"

Boom::Boom()
:Terrain(BOOM_NOT_EXIST, black_boom, NULL_TERRAIN, BACKGROUND),
 timeLife(BOOM_TIMEOUT)
{
}

Boom::Boom(life_t _life, image_t _image, terr_idx_t _boomIdx)
:Terrain(_life, _image, _boomIdx, WOOD_BOX),
 timeLife(BOOM_TIMEOUT)
{
}

bool Boom::WaitExplode()
{
	bool isExplode = 0;

	timeLife--;

	if(0 == timeLife)
	{
		map_terrain[terrainIdx] = BACKGROUND;
		life = BOOM_NOT_EXIST;
		timeLife = BOOM_TIMEOUT;
		isExplode = 1;

		Destroy();
	}

	return isExplode;
}

