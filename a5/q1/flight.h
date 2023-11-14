#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include "flightPlanner.h"
#include <memory>

class FlightNameException {
};

class Flight {
	std::string from, to, name;
	int duration, price;
    public:
	Flight(const std::string &from, const std::string &to, int duration, int price,
		       	const std::string &name);
	std::string getFrom();
	std::string getTo();
	std::string getName();
	int getDuration();
	int getPrice();
};


#endif
