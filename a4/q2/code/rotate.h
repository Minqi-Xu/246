#ifndef _ROTATE_H_
#define _ROTATE_H_
#include "decorator.h"
class Image;

class Rotate: public Decorator {
	public:
		Rotate(Image *content);
		void render(PPM &ppm) override; 
};

#endif
