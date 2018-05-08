#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdint.h>

typedef struct {
	uint16_t numRows;
	uint16_t numCols;
	uint16_t *image;
} image_t;

extern const image_t img_woof;
extern const image_t img_thuy;

#endif /* image.h */
