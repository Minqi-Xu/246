#include "sepia.h"
#include "image.h"

Sepia::Sepia(Image *content): Decorator{content} {}

void Sepia::render(PPM &ppm) {
	content->render(ppm);
	for(int i = 0; i < ppm.getHeight(); ++i) {
		for(int j = 0; j < ppm.getWidth(); ++j) {
			int temp_r, temp_g, temp_b;
			Pixel *ptr = &((ppm.getPixels()).at(i*ppm.getWidth() + j));
			temp_r = ptr->r * 0.393 + ptr->g * 0.769 + ptr->b * 0.189;
			if(temp_r > 255) temp_r = 255;
			temp_g = ptr->r * 0.349 + ptr->g * 0.686 + ptr->b * 0.168;
			if(temp_g > 255) temp_g = 255;
			temp_b = ptr->r * 0.272 + ptr->g * 0.534 + ptr->b * 0.131;
			if(temp_b > 255) temp_b = 255;
			ptr->r = temp_r;
			ptr->g = temp_g;
			ptr->b = temp_b;
		}
	}
}
