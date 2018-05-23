/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */

#include "Boom.h"
#include <stdio.h>

Boom::Boom()
:Terrain(UNPLANT, black_boom, NULL_TERRAIN, BACKGROUND),
 timeLife(BOOM_TIMEOUT), timeExplode(NOT_EXPLODE),
 boomLength(DEFAULT_BOOM_LEN)
{
}

Boom::Boom(life_t _life, image_t _image, terr_idx_t _boomIdx, int8_t _boomLength)
:Terrain(_life, _image, _boomIdx, WOOD_BOX),
 timeLife(BOOM_TIMEOUT), timeExplode(NOT_EXPLODE),
 boomLength(_boomLength)
{
}

bool Boom::CheckExplode()
{
	bool isExplode = 0;

	timeLife--;
	if(0 == timeLife)	isExplode = 1;

	return isExplode;
}

void Boom::Exploding()
{
	int8_t leftExplodeLength;
	int8_t rightExplodeLength;
	int8_t upExplodeLength;
	int8_t downExplodeLength;

	if(timeExplode == EXPLODE_TIME)
	{
		/* Set explode length for every direction
		 * in order to left, right, up, down */
		leftExplodeLength = GetDistance2ClosestBomb(terrainIdx, LEFT);
		if(leftExplodeLength > boomLength)
			leftExplodeLength = boomLength;

		rightExplodeLength = GetDistance2ClosestBomb(terrainIdx, RIGHT);
		if(rightExplodeLength > boomLength)
			rightExplodeLength = boomLength;

		upExplodeLength = GetDistance2ClosestBomb(terrainIdx, UP);
		if(upExplodeLength > boomLength)
			upExplodeLength = boomLength;

		downExplodeLength = GetDistance2ClosestBomb(terrainIdx, DOWN);
		if(downExplodeLength > boomLength)
			downExplodeLength = boomLength;

		CenterExplode	= new Terrain;
		LeftExplode		= new Terrain[leftExplodeLength];
		RightExplode	= new Terrain[rightExplodeLength];
		UpExplode	    = new Terrain[upExplodeLength];
		DownExplode		= new Terrain[downExplodeLength];

		/* Draw explode and clear map_terrain */
		CenterExplode->ChangeTerrainIdx(terrainIdx, BACKGROUND);
		CenterExplode->image = center_explode;
		CenterExplode->Draw();

		for(int i = 0; i < leftExplodeLength; i++)
		{
			LeftExplode[i].ChangeTerrainIdx(terrainIdx - 1 - i, BACKGROUND);
			LeftExplode[i].image = horizontal_explode;
			LeftExplode[i].Draw();
		}

		for(int i = 0; i < rightExplodeLength; i++)
		{
			RightExplode[i].ChangeTerrainIdx(terrainIdx + 1 + i, BACKGROUND);
			RightExplode[i].image = horizontal_explode;
			RightExplode[i].Draw();
		}

		for(int i = 0; i < upExplodeLength; i++)
		{
			UpExplode[i].ChangeTerrainIdx(terrainIdx - (1 + i) * MAP_WIDTH, BACKGROUND);
			UpExplode[i].image = vertical_explode;
			UpExplode[i].Draw();
		}

		for(int i = 0; i < downExplodeLength; i++)
		{
			DownExplode[i].ChangeTerrainIdx(terrainIdx + (1 + i) * MAP_WIDTH, BACKGROUND);
			DownExplode[i].image = vertical_explode;
			DownExplode[i].Draw();
		}
	}

	timeExplode--;

	if(0 == timeExplode)
	{
		timeExplode = NOT_EXPLODE;

		delete CenterExplode;
		delete [] LeftExplode;
		delete [] RightExplode;
		delete [] UpExplode;
		delete [] DownExplode;

		CenterExplode = NULL;
		LeftExplode   = NULL;
		RightExplode  = NULL;
		UpExplode     = NULL;
		DownExplode   = NULL;
	}
}

uint8_t GetDistance2ClosestBomb(terr_idx_t idx, dir_t dir)
{
	uint8_t distance = 0;
	terr_idx_t _idx = idx;

	switch(dir)
	{
	case LEFT:
		distance = _idx % MAP_WIDTH;

		while (0 != (_idx % MAP_WIDTH)) {
			_idx--;

			if (BOOM == map_terrain[_idx])
			{
				distance = idx - _idx - 1;
				break;
			}
		}

		break;
	case RIGHT:
		distance = (MAP_WIDTH - 1) - (_idx % MAP_WIDTH);

		while ((MAP_WIDTH - 1) != (_idx % MAP_WIDTH)) {
			_idx++;

			if (BOOM == map_terrain[_idx])
			{
				distance = _idx - idx - 1;
				break;
			}
		}

		break;
	case UP:
		distance = _idx / MAP_WIDTH;

		while (0 != (_idx / MAP_WIDTH)) {
			_idx -= MAP_WIDTH;

			if (BOOM == map_terrain[_idx])
			{
				distance = ((idx - _idx) / MAP_WIDTH) - 1;
				break;
			}
		}

		break;
	case DOWN:
		distance = (MAP_LENGTH - 1) - (_idx / MAP_WIDTH);

		while ((MAP_LENGTH - 1) != (_idx / MAP_WIDTH)) {
			_idx += MAP_WIDTH;

			if (BOOM == map_terrain[_idx])
			{
				distance = ((_idx - idx) / MAP_WIDTH) - 1;
				break;
			}
		}

		break;
	}

	return distance;
}

void Boom::UnsetBomb()
{
	Clear();

	map_terrain[terrainIdx] = BACKGROUND;
	life = UNPLANT;
	timeLife = BOOM_TIMEOUT;
}
