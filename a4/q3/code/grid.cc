#include "grid.h"
#include <iostream>
#include <vector>

Grid::~Grid() {
	theGrid.clear();
}

void Grid::setObserver(Observer<Info, State> *ob) {
	this->ob = ob;
}

bool Grid::isFull() const {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(theGrid.at(i).at(j).colour == Colour::Nocolour)
				return false;
		}
	}
	return true;
}

Colour Grid::whoWon() const {
	int num_black=0, num_white=0;
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(theGrid.at(i).at(j).colour == Colour::White) ++num_white;
			if(theGrid.at(i).at(j).colour == Colour::Black) ++num_black;
		}
	}
	if(num_black > num_white) return Colour::Black;
	if(num_black < num_white) return Colour::White;
	return Colour::NoColour;

}

int my_max(int a, int b) {
	if(a > b) return a;
	return b;
}

int my_min(int a, int b) {
	if(a < b) return a;
	return b;
}

void Grid::init(size_t n) {
	theGrid.clear();
	td = &theGrid;
	td->size = n;
	for(int i = 0; i < n; ++i)
		theGrid.emplace_back();
		for(int j = 0; j < n; ++j) {
			theGrid.emplace_back(Cell(i, j));
		}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = my_max(0,i-1); k < my_min(n,i+1); ++k)
				for(int l = my_max(0,j-1); l < my_min(n,j+1); ++l) {
					if(i==k && j==l) continue;
					theGrid.at(i).at(j).attach()(&theGrid.at(k).at(l));
				}

					
}

void setPiece(size_t r, size_t c, Colour colour) {
	(theGrid.at(r).at(c)).setPiece(colour);
	(theGrid.at(r).at(c)).setState(StateType::NewPiece);
	


}

void toggle(size_t r, size_t c) {
	(theGrid.at(r).at(c)).toggle();
}

std::ostream & Grid::operator<<(std::ostream &out, const Grid &g) {
	/*
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(theGrid.at(i * size + j).colour == Colour::Nocolour)
				out << "-";
			else if (theGrid.at(i * size + j).colour == Colour::White)
				out << "W";
			else if (theGrid.at(i * size + j).colour == Colour::Black)
				out << "B";
		}
		out << std::endl;
	}
	*/

	return out;
}
