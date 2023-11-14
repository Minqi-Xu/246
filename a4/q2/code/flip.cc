#include "flip.h"
#include "image.h"

Flip::Flip(Image *content): Decorator{content} {}

void Flip::render(PPM &ppm) {
	content->render(ppm);
	for(int i = 0; i < ppm.getHeight(); ++i) {
		for(int j = 0; j <= (ppm.getWidth()-1)/2; ++j) {
			Pixel temp = (ppm.getPixels()).at(i*ppm.getWidth() + j);
			(ppm.getPixels()).at(i*ppm.getWidth() + j) = (ppm.getPixels()).at(i*ppm.getWidth() + ppm.getWidth() - 1 - j);
			(ppm.getPixels()).at(i*ppm.getWidth() + ppm.getWidth() - 1 - j) = temp;
		}
	}
}
