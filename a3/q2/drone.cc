#include <iostream>
#include "position.h"
#include "drone.h"

Drone::Drone() : cur{Position()}, dir{0}, numSteps{0} {}
Drone:: ~Drone() {}
	
void Drone::forward(int steps) {
	switch(dir) {
		case 0:
			cur += Position(0, steps);
			break;
		case 1:
			cur += Position(steps, 0);
			break;
		case 2:
			cur += Position(0, -steps);
			break;
		case 3:
			cur += Position(-steps, 0);
			break;
	}
	numSteps += steps;
}
void Drone::backward(int steps) {
	switch(dir) {
		case 0:
			cur -= Position(0, steps);
			break;
		case 1:
			cur -= Position(steps, 0);
			break;
		case 2: 
			cur -= Position(0, -steps);
			break;
		case 3:
			cur -= Position(-steps, 0);
			break;
		}
	numSteps += steps;
}

void Drone::left() {
	--dir;
	if(dir == -1) dir = 3;
}

void Drone::right() {
	++dir;
	if(dir == 4) dir = 0;
}

Position Drone::getPosition() const {
	return cur;
}

int Drone::getDirection() const {
	return dir;
}

int Drone::getTotalDistance() const {
	return numSteps;
}

int Drone::getManhattanDistance() const {
	return cur.getManhattanDistance();
}

std::ostream &operator<<(std::ostream &out, const Drone &drone) {
	std::cout << "Current position: " << drone.getPosition() << ", Facing ";
	switch(drone.getDirection()) {
		case 0:
			std::cout << "North";
			break;
		case 1:
			std::cout << "East";
			break;
		case 2:
			std::cout << "South";
			break;
		case 3:
			std::cout << "West";
			break;
	}
	return out;
}
