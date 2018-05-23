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
#define BOOM_TIMEOUT		(3 * FPS)
#define EXPLODE_TIME		(FPS / 10)
#define NOT_EXPLODE			-7869

/* Boom life encode */
#define UNPLANT				0
#define PLANT				1

#define DEFAULT_BOOM_LEN	1

///****************************************************************************
///
/// EXTERNAL VARIABLE AND FUNCTION
///
///****************************************************************************
extern uint16_t * GetImageFromIdx(terr_idx_t idx);

///****************************************************************************
///
/// FUNCTION PROTOTYPE
///
///****************************************************************************
uint8_t GetDistance2ClosestBomb(terr_idx_t idx, dir_t dir);

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
	void UnsetBomb();
	bool CheckExplode();
	void Exploding();
};

#ifdef __cplusplus
}
#endif

#endif /* SRC_BOOM_H_ */
