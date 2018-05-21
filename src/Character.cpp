/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */
#include "Character.h"

static void GetBG(point_t pointStart, point_t pointEnd, uint16_t * bgImgPtr);

///****************************************************************************
///
/// CLASS FUNCTION IMPLEMENT
///
///****************************************************************************
Character::Character(point_t _point, life_t _life, image_t _image,
		 	 	 	 int8_t _boomAmount, int8_t _boomLength, speed_t _speed)
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

			uint16_t * bgImgPtr = new uint16_t[distance * image.numRows];
			GetBG((point_t) {endPixel.x - distance + 1, point.y},
				  (point_t) {endPixel.x, endPixel.y},
				  bgImgPtr);

			pushColors(bgImgPtr, distance * image.numRows, 1);

			delete [] bgImgPtr;

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

			uint16_t * bgImgPtr = new uint16_t[distance * image.numRows];
			GetBG((point_t) {point.x, point.y},
				  (point_t) {point.x + distance - 1, endPixel.y},
				  bgImgPtr);

			pushColors(bgImgPtr, distance * image.numRows, 1);

			delete [] bgImgPtr;

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

			uint16_t * bgImgPtr = new uint16_t[distance * image.numCols];
			GetBG((point_t) {point.x, endPixel.y - distance + 1},
				  (point_t) {endPixel.x, endPixel.y},
				  bgImgPtr);

			pushColors(bgImgPtr, distance * image.numCols, 1);

			delete [] bgImgPtr;

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

			uint16_t * bgImgPtr = new uint16_t[distance * image.numCols];
			GetBG((point_t) {point.x, point.y},
				  (point_t) {endPixel.x, point.y + distance - 1},
				  bgImgPtr);

			pushColors(bgImgPtr, distance * image.numCols, 1);

			delete [] bgImgPtr;

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

	if((SQUARE_EDGE_PIXEL / 2) < ((point.x - X_MAP_OFFSET) % SQUARE_EDGE_PIXEL)) {
		boomCoordinates.x = point.x + image.numCols - 1;
	} else {
		boomCoordinates.x = point.x;
	}

	if ((SQUARE_EDGE_PIXEL / 2) < ((point.y -Y_MAP_OFFSET) % SQUARE_EDGE_PIXEL)) {
		boomCoordinates.y = point.y + image.numRows - 1;
	} else {
		boomCoordinates.y = point.y;
	}

	boomIdx = PIXEL_IDX_CALC(boomCoordinates.x, boomCoordinates.y);

	/* If an index have a boom then no action */
	for(int i = 0; i < boomAmount; i++)
	{
		if(BOOM_EXIST == boomVector[i].life)
		{
			if(boomVector[i].terrainIdx == boomIdx)    return;
		}
	}

	/* Find a empty Boom object on boomVector to create a new boom */
	for(int i = 0; i < boomAmount; i++)
	{
		if(BOOM_NOT_EXIST == boomVector[i].life)
		{
			boomAmountCurr++;
			boomVector[i].life = BOOM_EXIST;
			boomVector[i].ChangeTerrainIdx(boomIdx, BOOM);
			boomVector[i].boomLength = boomLength;
			boomVector[i].Draw();

			return;
		}
	}
}

/** @breif GetBG
 *
 *  Get the background after character, when character move location
 *
 *  @param
 *  @param _dir The direction
 *  @return Pointer to image
 */
void GetBG(point_t pointStart, point_t pointEnd, uint16_t * bgImgPtr)
{
	terr_idx_t startTerrainIdx = PIXEL_IDX_CALC(pointStart.x, pointStart.y);
	point_t startPixel = {COL_IDX(pointStart.x) * SQUARE_EDGE_PIXEL + X_MAP_OFFSET,
						  ROW_IDX(pointStart.y) * SQUARE_EDGE_PIXEL + Y_MAP_OFFSET};

	uint16_t numCol = COL_IDX(pointEnd.x) - COL_IDX(pointStart.x) + 1;
	uint16_t numRow = ROW_IDX(pointEnd.y) - ROW_IDX(pointStart.y) + 1;

	uint16_t * bufferImg = new uint16_t[numCol * numRow * SQUARE_PIXEL];
	uint16_t * imgIdxPtr;
	uint16_t bgImgWidth  = pointEnd.x - pointStart.x + 1;


	for(int rowIdx = 0; rowIdx < numRow; rowIdx++)
	{
		for(int colIdx = 0; colIdx < numCol; colIdx++)
		{
			imgIdxPtr = GetImageFromIdx(startTerrainIdx + colIdx +
					rowIdx * MAP_WIDTH);

			for(int j = 0; j < SQUARE_EDGE_PIXEL; j++)
			{
				for(int i = 0; i < SQUARE_EDGE_PIXEL; i++)
				{
					int bufferImgIdx = (SQUARE_EDGE_PIXEL * numCol *
									   (j +	rowIdx * SQUARE_EDGE_PIXEL)) +
									   (i + colIdx * SQUARE_EDGE_PIXEL);

					bufferImg[bufferImgIdx] = imgIdxPtr[j * SQUARE_EDGE_PIXEL + i];
				}
			}
		}
	}

	for(int j = pointStart.y - startPixel.y; j <= pointEnd.y - startPixel.y; j++)
	{
		for(int i = pointStart.x - startPixel.x; i <= pointEnd.x - startPixel.x; i++)
		{
			uint16_t bgImgRowIdx = j - (pointStart.y - startPixel.y);
			uint16_t bgImgColIdx = i - (pointStart.x - startPixel.x);

			bgImgPtr[bgImgRowIdx * bgImgWidth + bgImgColIdx] =
					bufferImg[j * numCol * SQUARE_EDGE_PIXEL + i];
		}
	}

	delete [] bufferImg;
}

void Character::WaitBoomExplode()
{
	for(int i = 0; i < boomAmount; i++)
	{
		if(BOOM_EXIST == boomVector[i].life) {
			if(TRUE == boomVector[i].WaitExplode())	  boomAmountCurr--;
		} else {
			if(NOT_EXPLODE != boomVector[i].timeExplode)
				boomVector[i].Explode();
		}
	}
}
