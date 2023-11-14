#ifndef FLIGHTPLAN_H_
#define FLIGHTPLAN_H_

#include <string>
#include <vector>
#include "flight.h"

class Flight;

class FlightPlan {
	std::string from, to;
	int duration, price;
	std::vector<std::shared_ptr<Flight>> steps;
    public:
	FlightPlan(std::string from, std::string to, int duration, int price,
		       	std::vector<std::shared_ptr<Flight>> steps);
	std::string getFrom();
	std::string getTo();
	int getDuration();
	int getPrice();
	std::vector<std::shared_ptr<Flight>> getSteps();
	int getPain();
};

#endif
