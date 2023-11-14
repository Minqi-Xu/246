#include "position.h"
#include <iostream>

// constructor
Position::Position(int ew, int ns): ew{ew}, ns{ns} {}

// add rhs.ew to this position's ew and
// rhs.ns to this position's ns
Position & Position::operator+=(const Position &rhs) {
	this->ew = this->ew + rhs.ew;
	this->ns = this->ns + rhs.ns;
	return *this;
}

// substrcts rhs.ew from this position's ew and
// rhs.ns from this position's ns
Position & Position::operator-=(const Position &rhs) {
	this->ew = this->ew - rhs.ew;
	this->ns = this->ns - rhs.ns;
	return *this;
}
	
// Accessor
int Position::getEW() const {
	return this->ew;
}
int Position::getNS() const {
	return this->ns;
}

// Calculates the Manhattan distance of the this position to the origin
// (the absolute north-south displacement plus the absolute east-west displacement)
int Position::getManhattanDistance() const {
	int abs_ew = ew, abs_ns = ns;
	if(ew < 0) abs_ew = -abs_ew;
	if(ns < 0) abs_ns = -abs_ns;
	return (abs_ew + abs_ns);
}

// Prints the current values of the position to out in the format:
// (ew,ns)
std::ostream &operator<<(std::ostream &out, const Position &pos) {
	std::cout << "(" << pos.getEW() << "," << pos.getNS() <<")";
	return out;
}
