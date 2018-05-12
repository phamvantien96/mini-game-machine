/** @file Character.h
 *  @author Tien.P.V
 *  @date 10-May-2018
 */

#ifndef SRC_BOOM_H_
#define SRC_BOOM_H_

#include "Terrain.h"

#ifdef __cplusplus
extern "C"
{
#endif  /* __cplusplus */
///****************************************************************************
///
/// DEFINE AND MARCO
///
///****************************************************************************
#define BOOM_TIMEOUT		(2 * FPS)
#define BOOM_EXIST			1
#define BOOM_NOT_EXIST		0

///****************************************************************************
///
/// EXTERNAL VARIABLE AND FUNCTION
///
///****************************************************************************

///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Boom:public Terrain {
public:
	time_t timeLife;
public:
	Boom();
	Boom(life_t _life, image_t _image, terr_idx_t _boomIdx);
	void DecreaseTimeLife();
};

#ifdef __cplusplus
}
#endif

#endif /* SRC_BOOM_H_ */
