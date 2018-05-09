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
#define PORTE_PIN_USE 0x1F
#define PORTB_PIN_USE 0xFF

///****************************************************************************
///
/// TYPEDEF
///
///****************************************************************************
/**
 *  Use for Entity class
 */
typedef struct {
    uint32_t x;
    uint32_t y;
}point_t;

typedef enum {
	STAY,
	LEFT,
	RIGHT,
	UP,
	DOWN
}dir_t;

typedef uint32_t life_t;
typedef uint32_t distance_t;



#ifdef __cplusplus
}
#endif

#endif /* SRC_CONFIG_H_ */
