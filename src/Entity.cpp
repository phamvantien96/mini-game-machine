#include "Entity.h"

Entity::Entity()
{
	point.x = 0;
	point.y = 0;
	life = 0;
}

Entity::Entity(point_t _point, uint32_t _life)
:life(_life)
{
	point.x = _point.x;
	point.y = _point.y;
}

void Entity::Move(dir_t _dir, uint32_t distance)
{
    switch(_dir)
    {
        case LEFT:
            point.x -= distance;
            break;
        case RIGHT:
            point.x += distance;
            break;
        case UP:
            point.y -= distance;
            break;
        case DOWN:
            point.y += distance;
            break;
    }
}
