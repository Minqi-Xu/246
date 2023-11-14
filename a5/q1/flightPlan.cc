#include "flightPlan.h"
#include "flight.h"
#include <string>
#include <vector>
#include <cmath>

FlightPlan::FlightPlan(std::string from, std::string to, int duration, int price,
		std::vector<std::shared_ptr<Flight>> steps) : from{from}, to{to}, 
	duration{duration}, price{price}, steps{steps} {}

std::string FlightPlan::getFrom() { return from; }
std::string FlightPlan::getTo() { return to; }
int FlightPlan::getDuration() { return duration; }
int FlightPlan::getPrice() { return price; }
std::vector<std::shared_ptr<Flight>> FlightPlan::getSteps() { return steps; }

int FlightPlan::getPain() {
	double temp = pow(1.2, this->getDuration()) * this->getPrice();
	int ans = temp;
	return ans;
}
