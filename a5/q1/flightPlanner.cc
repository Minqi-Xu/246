#include "flightPlanner.h"
#include <map>
#include <vector>
#include <string>

FlightPlanner::FlightPlanner() {
	airports.clear();
	plan.clear();
}

void FlightPlanner::addAirport(const std::string &name) {
	for(auto it : this->airports) {
		if(it == name) throw FlightNameException();
	}
	airports.emplace_back(name);
}

void FlightPlanner::addFlight(const std::string &from, const std::string &to, int duration,
		int price, const std::string &name) {
	bool flag1 = true, flag2 = true;
	for(auto it : this->airports) {
		if( it == from ) {
			flag1 = false;
			break;
		}
	}
	if(flag1) throw FlightNameException();
	for(auto it : this->airports) {
		if( it == to ) {
			flag2 = false;
			break;
		}
	}
	if(flag2) throw FlightNameException();
	for(auto it : this->plan) {
		if(it->getName() == name) {
			throw FlightNameException();
		}
	}
	std::shared_ptr<Flight> t1 = std::shared_ptr<Flight>(new Flight(from, to, duration, price, name));
	std::shared_ptr<Flight> t2 = std::shared_ptr<Flight>(new Flight(to, from, duration, price, name));
	plan.emplace_back(t1);
	plan.emplace_back(t2);
}

std::vector<std::shared_ptr<FlightPlan>> FlightPlanner::planTrip(const std::string & from,
		const std::string to) {
	bool flag1 = true, flag2 = true;
	for(auto it : this->airports) {
		if( it == from ) {
			flag1 = false;
			break;
		}
	}
	if(flag1) throw FlightNameException();
	for(auto it : this->airports) {
		if( it == to ) {
			flag2 = false;
			break;
		}
	}
	if(flag2) throw FlightNameException();
	std::map<int, std::shared_ptr<FlightPlan>> result;
	std::vector<std::string> route;
	std::vector<std::shared_ptr<Flight>> path;
	search(from, to, result, route, path);
	std::vector<std::shared_ptr <FlightPlan>> ans;
	for(auto it : result) {
		ans.emplace_back(it.second);
	}
	return ans;
}

std::shared_ptr<FlightPlan> build(std::vector<std::shared_ptr<Flight>> path, std::string to) {
	int price = 0, duration = 0;
	std::string from = "";
	for(auto it : path) {
		if(it == path.at(1)) {
			from = it->getFrom();
		}
		duration = duration + it->getDuration();
		price = price + it->getPrice();
	}
	duration += path.size();
	--duration;
	std::shared_ptr<FlightPlan> ans = std::shared_ptr<FlightPlan>(new FlightPlan(from,
				to,duration, price, path));
	return ans;
}

void FlightPlanner::search(const std::string &from, const std::string &to, 
		std::map<int, std::shared_ptr<FlightPlan>> &result,
		std::vector<std::string> route, 
		std::vector<std::shared_ptr<Flight>> path) {
	bool flag = false;
	for(auto it : route) {
		if(it == from) {
			flag = true;
			break;
		}
	}
	if(from == to) {
		std::shared_ptr<FlightPlan> temp = build(path,to);
		if(temp->getSteps().size() != 0) {
			if(result.find(temp->getPain()) != result.end()) {
				result.emplace(temp->getPain() + 1, temp);
			}
			else {
				result.emplace(temp->getPain(), temp);	
			}
		}
		return;
	} else if (flag) {
		return;
	} else {
		std::vector<std::shared_ptr<Flight>> pre_path = path;;
		std::vector<std::string> pre_route = route;
		for(int i = 0 ; i < plan.size(); ++i) {
			if(plan.at(i)->getFrom() == from){
				path.emplace_back(plan.at(i));
				route.emplace_back(plan.at(i)->getFrom());
				search(plan.at(i)->getTo(), to, result, route, path);
			}
			path = pre_path;
			route = pre_route;
		}
	}
	return;
}



