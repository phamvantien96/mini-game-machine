/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */

#include "Boom.h"

Boom::Boom()
:Terrain(BOOM_NOT_EXIST, water_boom, NULL_TERRAIN),
 timeLife(BOOM_TIMEOUT)
{
}

Boom::Boom(life_t _life, image_t _image, terr_idx_t _boomIdx)
:Terrain(_life, _image, _boomIdx),
 timeLife(BOOM_TIMEOUT)
{
}

void Boom::DecreaseTimeLife()
{
	timeLife--;

	if(0 == timeLife)
	{
		life = BOOM_NOT_EXIST;
		Destroy();
	}
}

