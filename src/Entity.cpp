/** @file Entity.cpp
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#include "Entity.h"

Entity::Entity(image_t _image)
:point((point_t){0, 0}), life(0), image(_image)
{
}

Entity::Entity(point_t _point, life_t _life, image_t _image)
:point((point_t){_point.x, _point.y}), life(_life), image(_image)
{
}

void Entity::Move(dir_t _dir, distance_t distance)
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

void Entity::SetPoint(point_t _point)
{
	point = _point;
}

void Entity::Draw()
{
	setAddrWindow(point.x, point.y, point.x + image.numCols - 1, point.y + image.numRows - 1);

	pushColors(image.image, image.numCols * image.numRows, 1);
}

void Entity::Clear()
{
	setAddrWindow(point.x, point.y, point.x + image.numCols - 1, point.y + image.numRows - 1);

	flood(BLACK, image.numCols * image.numRows);
}

void Entity::Destroy()
{
	Clear();
}

