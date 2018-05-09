/** @file character.c
 *  @author Tien.P.V
 *  @date 08-May-2018
 */
#include "image.h"

const static uint16_t character[] =  {\
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x4, 0x82B6, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x82B6, 0x4, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x4, 0xFFFF, 0x4, 0x82B6, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x82B6, 0x4, 0xFFFF, 0x4, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xF7BE, 0x4, 0x4, 0x82B6, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x82B6, 0x4, 0x4, 0xF7BE, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xF7BE, 0xF7BE, 0x9492, 0x4, 0x4, 0x82B6, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x82B6, 0x4, 0x4, 0x9492, 0xF7BE, 0xF7BE, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xF7BE, 0xF7BE, 0xF7BE, 0x9492, 0x4, 0x4, 0x82B6, 0x82B6, 0x4, 0x4, 0x9492, 0xF7BE, 0xF7BE, 0xF7BE, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x82B6, 0x4, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x9492, 0x4, 0x4, 0x9492, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x4, 0x82B6, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xCCFF, 0x82B6, 0x4, 0x9492, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x9492, 0x4, 0x82B6, 0xCCFF, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xCCFF, 0x4, 0x4, 0x4, 0x4, 0x4, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x4, 0x4, 0x4, 0x4, 0x4, 0xCCFF, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xCCFF, 0x4, 0x12D, 0x4B76, 0x4B76, 0x4B76, 0x4, 0xF7BE, 0xF7BE, 0x4, 0x4B76, 0x4B76, 0x4B76, 0x12D, 0x4, 0xCCFF, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x82B6, 0xCCFF, 0x4, 0x4B76, 0x4B76, 0xF7BE, 0x4B76, 0x4, 0x4, 0x4B76, 0xF7BE, 0x4B76, 0x4B76, 0x4, 0xCCFF, 0x82B6, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xCCFF, 0x4, 0x12D, 0x4B76, 0xF7BE, 0x4B76, 0x4, 0x4, 0x4B76, 0xF7BE, 0x4B76, 0x12D, 0x4, 0xCCFF, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x82B6, 0xFED6, 0x4, 0x4, 0x4, 0x4, 0xFED6, 0xFED6, 0x4, 0x4, 0x4, 0x4, 0xFED6, 0x82B6, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xDC8D, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xDC8D, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x4, 0x4, 0xDC8D, 0xFED6, 0xFED6, 0xFED6, 0xFED6, 0xDC8D, 0x4, 0x4, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x82B6, 0xCCFF, 0xCCFF, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0xCCFF, 0xCCFF, 0x82B6, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x82B6, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x82B6, 0x82B6, 0x82B6, 0x82B6, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x82B6, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xCCFF, 0xCCFF, 0x4, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0xCCFF, 0x4, 0xCCFF, 0xCCFF, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xF7BE, 0x82B6, 0xCCFF, 0x4, 0x4, 0x4, 0xCCFF, 0x4, 0x4, 0xCCFF, 0x4, 0x4, 0x4, 0xCCFF, 0x82B6, 0xF7BE, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xF7BE, 0xF7BE, 0x82B6, 0x4, 0x9492, 0x9492, 0x4, 0xF7BE, 0xF7BE, 0x4, 0x9492, 0x9492, 0x4, 0x82B6, 0xF7BE, 0xF7BE, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0xF7BE, 0xF7BE, 0xF7BE, 0x4, 0x4, 0x4, 0x4, 0xF7BE, 0xF7BE, 0x4, 0x4, 0x4, 0x4, 0xF7BE, 0xF7BE, 0xF7BE, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4, 0x4, 0x4, 0x4, 0x82B6, 0x82B6, 0x82B6, 0x4, 0x4, 0x82B6, 0x82B6, 0x82B6, 0x4, 0x4, 0x4, 0x4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, \
};

const image_t img_character = {24, 24, (uint16_t *) character};

