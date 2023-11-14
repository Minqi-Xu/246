#include "rotate.h"
#include "image.h"
#include <vector>

Rotate::Rotate(Image *content): Decorator{content} {}

void Rotate::render(PPM &ppm) {
	content->render(ppm);
	std::vector<Pixel> newppm = ppm.getPixels();
	for(int i = 0; i < ppm.getWidth(); ++i) {
		for(int j = 0; j < ppm.getHeight(); ++j) {
			newppm.at(i * ppm.getHeight() + j) = (ppm.getPixels()).at(ppm.getWidth() * (ppm.getHeight() - j - 1) + i);
		}
	}
	(ppm.getPixels()).swap(newppm);
	int temp = ppm.getWidth();
	ppm.getWidth() = ppm.getHeight();
	ppm.getHeight() = temp;
}

