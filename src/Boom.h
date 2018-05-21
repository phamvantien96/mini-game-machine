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
#define EXPLODE_TIME		(FPS)
#define BOOM_EXIST			1
#define BOOM_NOT_EXIST		0

#define NOT_EXPLODE			-1

#define DEFAULT_BOOM_LEN	1

///****************************************************************************
///
/// EXTERNAL VARIABLE AND FUNCTION
///
///****************************************************************************
extern uint16_t * GetImageFromIdx(terr_idx_t idx);

///****************************************************************************
///
/// CLASS PROTOTYPE
///
///****************************************************************************
class Boom:public Terrain {
public:
	time_t timeLife;
	time_t timeExplode;
	int8_t boomLength;
public:
	Boom();
	Boom(life_t _life, image_t _image, terr_idx_t _boomIdx, int8_t _boomLength);
	bool WaitExplode();
	void Explode();
};

#ifdef __cplusplus
}
#endif

#endif /* SRC_BOOM_H_ */
