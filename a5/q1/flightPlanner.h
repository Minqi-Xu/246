#ifndef FLIGHTPLANER_H_
#define FLIGHTPLANER_H_

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "flight.h"
#include "flightPlan.h"

class Flight;
class FlightPlan;

class FlightPlanner {
	std::vector<std::string> airports;
	std::vector<std::shared_ptr<Flight>> plan;
    public:
	FlightPlanner();
	void addAirport(const std::string &name);
	void addFlight(const std::string &from, const std::string &to, int duration,
			int price, const std::string &name);
	std::vector<std::shared_ptr<FlightPlan>> planTrip(const std::string &from,
			const std::string to);
	void search(const std::string &from, const std::string &to, 
			std::map <int, std::shared_ptr <FlightPlan>> &g, 
			std::vector<std::string> route,
			std::vector<std::shared_ptr<Flight>> path);
};

#endif
