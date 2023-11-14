#include "image.h"
#include "decorator.h"

Decorator::Decorator(Image *content): content{content} {}

Decorator::~Decorator() {delete content;}
