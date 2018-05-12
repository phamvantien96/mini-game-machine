/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */
#include "Character.h"

///****************************************************************************
///
/// CLASS FUNCTION IMPLEMENT
///
///****************************************************************************
Character::Character(point_t _point, life_t _life, image_t _image,
		 	 	 	 uint8_t _boomAmount, uint8_t _boomLength, speed_t _speed)
:Entity(_point, _life, _image),
 boomAmount(_boomAmount),
 boomAmountCurr(0),
 boomLength(_boomLength),
 speed(_speed),
 boomVector(_boomAmount)
{
}

void Character::IncreaseBoomAmount()
{
	boomAmount++;
	boomVector.push_back(Boom());
}

void Character::IncreaseBoomLength()
{
	boomLength++;
}

void Character::IncreaseSpeed()
{
	speed++;
}

void Character::Move(dir_t _dir)
{
	Move(_dir, speed);
}

void Character::Move(dir_t _dir, distance_t distance)
 {
	point_t endPixel = { point.x + image.numCols - 1,
			point.y + image.numRows - 1 };

	coordinates_t mapBoundary;

	switch (_dir)
	{
	case LEFT:
		mapBoundary = GetClosestTerrain(PIXEL_IDX_CALC(point.x, point.y),
				PIXEL_IDX_CALC(point.x, endPixel.y), _dir);

		if ((point.x - distance) < mapBoundary)
			distance = point.x - mapBoundary;

		/* If distance = 0 we no change anything*/
		if (0 != distance) {
			setAddrWindow(endPixel.x - distance + 1, point.y, endPixel.x,
					endPixel.y);

			flood(BLACK, distance * image.numRows);
			point.x -= distance;
		}
		break;
	case RIGHT:
		mapBoundary = GetClosestTerrain(PIXEL_IDX_CALC(endPixel.x, point.y),
				PIXEL_IDX_CALC(endPixel.x, endPixel.y), _dir);

		if ((endPixel.x + distance) > mapBoundary)
			distance = mapBoundary - endPixel.x;

		/* If distance = 0 we no change anything*/
		if (0 != distance) {
			setAddrWindow(point.x, point.y, point.x + distance - 1, endPixel.y);
			flood(BLACK, distance * image.numRows);
			point.x += distance;
		}
		break;
	case UP:
		mapBoundary = GetClosestTerrain(PIXEL_IDX_CALC(point.x, point.y),
				PIXEL_IDX_CALC(endPixel.x, point.y), _dir);

		if ((point.y - distance) < mapBoundary)
			distance = point.y - mapBoundary;

		/* If distance = 0 we no change anything*/
		if (0 != distance) {
			setAddrWindow(point.x, endPixel.y - distance + 1, endPixel.x,
					endPixel.y);

			flood(BLACK, distance * image.numCols);
			point.y -= distance;
		}
		break;
	case DOWN:
		mapBoundary = GetClosestTerrain(PIXEL_IDX_CALC(point.x, endPixel.y),
				PIXEL_IDX_CALC(endPixel.x, endPixel.y), _dir);

		if ((endPixel.y + distance) > mapBoundary)
			distance = mapBoundary - endPixel.y;

		/* If distance = 0 we no change anything*/
		if (0 != distance) {
			setAddrWindow(point.x, point.y, endPixel.x, point.y + distance - 1);
			flood(BLACK, distance * image.numCols);
			point.y += distance;
		}
		break;
	}

	if (0 != distance)
		Draw();
}

void Character::SetBoom()
{
	if(boomAmountCurr == boomAmount)	return;

	point_t boomCoordinates;
	terr_idx_t boomIdx;

	if((SQUARE_SIZE_PIXEL / 2) < ((point.x - X_MAP_OFFSET) % SQUARE_SIZE_PIXEL)) {
		boomCoordinates.x = point.x + image.numCols - 1;
	} else {
		boomCoordinates.x = point.x;
	}

	if ((SQUARE_SIZE_PIXEL / 2) < ((point.y -Y_MAP_OFFSET) % SQUARE_SIZE_PIXEL)) {
		boomCoordinates.y = point.y + image.numRows - 1;
	} else {
		boomCoordinates.y = point.y;
	}

	boomIdx = PIXEL_IDX_CALC(boomCoordinates.x, boomCoordinates.y);

	for(int i = 0; i < boomAmount; i++)
	{
		if(BOOM_EXIST == boomVector[i].life)
		{
			if(boomVector[i].terrainIdx == boomIdx)    return;
		}
	}

	for(int i = 0; i < boomAmount; i++)
	{
		if(BOOM_NOT_EXIST == boomVector[i].life)
		{
			boomAmountCurr++;
			boomVector[i].life = BOOM_EXIST;
			boomVector[i].ChangeTerrainIdx(boomIdx);
			boomVector[i].Draw();

			return;
		}
	}
}
