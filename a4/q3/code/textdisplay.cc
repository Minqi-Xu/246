#include "textdisplay.h"
#include <iostream>
#include <vector>

TextDisplay::TextDisplay(int n): gridSize{n} {
	for( int i = 0; i < n; ++i) {
		theDisplay.emplace_back();
		for(int j = 0; j < n; ++j) {
			theDisplay.emplace_back('_');
		}
	}
}

void TextDisplay::notify(Subject<Info, State> &whoNotified) override {
	for( int i = 0; i < gridSize; ++i) {
		for(int j = 0; j < gridSize; ++j) {
			if()
		}
	}
}

std::ostream &  TextDisplay::operator<<(std::ostream &out, const TextDisplay &td) {
	
}
