#ifndef _DECORATOR_H
#define _DECORATOR_H
#include "image.h"

class Decorator: public Image {
	protected:
		Image *content;
	public:
		Decorator(Image *content);
		virtual ~Decorator(); 
};

#endif
