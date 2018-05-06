#include <stdint.h>

typedef struct{
	const uint16_t numRows; 
	const uint16_t numCols;
	const uint16_t *image;
} image_t;

extern image_t img_woof;
