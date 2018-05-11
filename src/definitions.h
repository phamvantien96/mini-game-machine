/** @file definitions.h
 *  @author Tien.P.V
 *  @date 25-Apr-2018
 *  @breif Prototype for functions that configure the system
 */

#ifndef _DEFINITION_CONFIG_H_
#define _DEFINITION_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

///****************************************************************************
///
/// DEFINE
///
///****************************************************************************
#define PORTE_PIN_USE 				0x1F
#define PORTB_PIN_USE 				0xFF

#define ONE_MSEC 13333
#define ONE_USEC 14

/* Number of clock use in timer or systick reload to interrupt at FPS */
#define FPS							50
#define CPU_FREQ					80000000
#define FPS2CLK						(CPU_FREQ / FPS - 1)

/*
 * Define for map
 */
#define SQUARE_SIZE_PIXEL 			24
#define MAP_WIDTH					10
#define MAP_LENGTH					10
#define MAX_IDX						(MAP_WIDTH * MAP_LENGTH)
#define Y_MAP_OFFSET				48
#define X_MAP_OFFSET				0

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************
///
/// Use for Entity class
///
typedef int16_t coordinates_t;

typedef struct {
	coordinates_t x;
	coordinates_t y;
}point_t;

typedef enum {
	STAY,
	LEFT,
	RIGHT,
	UP,
	DOWN
}dir_t;

typedef int16_t life_t;
typedef int16_t distance_t;
typedef int16_t speed_t;

///
/// Use for Terrain class
///
/* Terrain index read from left to right, up to down */
typedef uint8_t terr_idx_t;

#ifdef __cplusplus
}
#endif

#endif /* SRC_CONFIG_H_ */
