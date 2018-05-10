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

void Entity::Draw()
{
	setAddrWindow(point.x, point.y, point.x + image.numCols - 1, point.y + image.numRows - 1);

	pushColors(image.image, image.numCols * image.numRows, 1);
}

/** @breif Entity::Clear
 *
 * 	Default clear entity with BLACK color
 *
 */
void Entity::Clear()
{
	setAddrWindow(point.x, point.y, point.x + image.numCols - 1, point.y + image.numRows - 1);

	flood(BLACK, image.numCols * image.numRows);
}

void Entity::Destroy()
{
	Clear();
}
