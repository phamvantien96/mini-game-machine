#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#include <stdint.h>
#include <stdbool.h>
#include "image.h"
#include "lcd_driver.h"

#ifdef __cplusplus
extern "C" 
{
#endif  /* __cplusplus */

/*
 * Direction for entity move
 */
#define LEFT 		0
#define RIGHT 		1
#define UP 	 		2
#define DOWN 		3

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************
typedef struct {
    uint32_t x;
    uint32_t y;
}point_t;

typedef uint8_t dir_t;
typedef uint32_t life_t;
typedef uint32_t distance_t;

///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Entity {
    public:
        point_t point;
        image_t image;
        life_t life;
    public:
		Entity(image_t _image);
        Entity(point_t _point, life_t _life, image_t _image);
        void SetPoint(point_t _point);
        point_t GetPoint(Entity);
		void Move(dir_t _dir, distance_t distance);
		void Draw();
		void Clear();
};

#ifdef __cplusplus
}
#endif

#endif
