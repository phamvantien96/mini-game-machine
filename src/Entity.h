#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************
typedef struct {
    uint32_t x;
    uint32_t y;
}point_t;

typedef enum {
	LEFT,
	RIGHT,
	UP,
	DOWN
}dir_t;

class Entity {
    public:
        point_t point;
        const uint8_t * image[2];
        uint32_t life;
    public:
		Entity();
        Entity(point_t _point, uint32_t _life);
        void SetPoint(point_t _point);
        point_t GetPoint(Entity);
		void Move(dir_t _dir, uint32_t distance);
};

#ifdef __cplusplus
}
#endif

#endif
