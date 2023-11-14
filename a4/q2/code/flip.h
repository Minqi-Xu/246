#ifndef _FLIP_H_
#define _FLIP_H_
#include "decorator.h"
class Image;

class Flip: public Decorator {
	public:
		Flip(Image *content);
		void render(PPM &ppm) override;
};

#endif
