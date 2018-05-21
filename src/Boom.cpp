/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */

#include "Boom.h"

Boom::Boom()
:Terrain(BOOM_NOT_EXIST, black_boom, NULL_TERRAIN, BACKGROUND),
 timeLife(BOOM_TIMEOUT), timeExplode(NOT_EXPLODE),
 boomLength(EXPLODE_TIME)
{
}

Boom::Boom(life_t _life, image_t _image, terr_idx_t _boomIdx, int8_t _boomLength)
:Terrain(_life, _image, _boomIdx, WOOD_BOX),
 timeLife(BOOM_TIMEOUT), timeExplode(NOT_EXPLODE),
 boomLength(_boomLength)
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

		timeExplode = EXPLODE_TIME;
	}

	return isExplode;
}

void Boom::Explode()
{
	static int8_t * leftExplodeLength;
	static int8_t * rightExplodeLength;
	static int8_t * upExplodeLength;
	static int8_t * downExplodeLength;

	static Terrain * CenterExplode;
	static Terrain * LeftExplode;
	static Terrain * RightExplode;
	static Terrain * UpExplode;
	static Terrain * DownExplode;

	if(timeExplode == EXPLODE_TIME)
	{
		leftExplodeLength  = new int8_t;
		rightExplodeLength = new int8_t;
		upExplodeLength    = new int8_t;
		downExplodeLength  = new int8_t;

		/* Set explode length for every direction */
		if(0 <= (terrainIdx % MAP_WIDTH) - boomLength) {
			*leftExplodeLength = boomLength;
		} else {
			*leftExplodeLength = terrainIdx % MAP_WIDTH;
		}

		if((MAP_WIDTH - 1) >= (terrainIdx % MAP_WIDTH) + boomLength) {
			*rightExplodeLength = boomLength;
		} else {
			*rightExplodeLength = (MAP_WIDTH - 1) - (terrainIdx % MAP_WIDTH);
		}

		if(0 <= (terrainIdx / MAP_LENGTH) - boomLength) {
			*upExplodeLength = boomLength;
		} else {
			*upExplodeLength = terrainIdx / MAP_WIDTH;
		}

		if((MAP_LENGTH - 1) >= (terrainIdx / MAP_WIDTH) + boomLength) {
			*downExplodeLength = boomLength;
		} else {
			*downExplodeLength = (MAP_LENGTH - 1) - (terrainIdx / MAP_WIDTH);
		}

		CenterExplode	= new Terrain;
		LeftExplode		= new Terrain[*leftExplodeLength];
		RightExplode	= new Terrain[*rightExplodeLength];
		UpExplode	    = new Terrain[*upExplodeLength];
		DownExplode		= new Terrain[*downExplodeLength];

		CenterExplode->ChangeTerrainIdx(terrainIdx, BACKGROUND);
		CenterExplode->image = center_explode;
		CenterExplode->Draw();

		for(int i = 0; i < *leftExplodeLength; i++)
		{
			LeftExplode[i].ChangeTerrainIdx(terrainIdx - 1 - i, BACKGROUND);
			LeftExplode[i].image = horizontal_explode;
			LeftExplode[i].Draw();
		}

		for(int i = 0; i < *rightExplodeLength; i++)
		{
			RightExplode[i].ChangeTerrainIdx(terrainIdx + 1 + i, BACKGROUND);
			RightExplode[i].image = horizontal_explode;
			RightExplode[i].Draw();
		}

		for(int i = 0; i < *upExplodeLength; i++)
		{
			UpExplode[i].ChangeTerrainIdx(terrainIdx - (1 + i) * MAP_WIDTH, BACKGROUND);
			UpExplode[i].image = vertical_explode;
			UpExplode[i].Draw();
		}

		for(int i = 0; i < *upExplodeLength; i++)
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

		delete leftExplodeLength;
		delete rightExplodeLength;
		delete upExplodeLength;
		delete downExplodeLength;

		delete CenterExplode;
		delete [] LeftExplode;
		delete [] RightExplode;
		delete [] UpExplode;
		delete [] DownExplode;
	}
}
