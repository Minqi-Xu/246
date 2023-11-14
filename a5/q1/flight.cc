#include "flight.h"
#include <string>

Flight::Flight(const std::string &from, const std::string &to, int duration, int price,
		const std::string &name): from{from}, to{to}, duration{duration},
	price{price}, name{name} {}

std::string Flight::getFrom() { return from; }

std::string Flight::getTo() { return to; }

std::string Flight::getName() { return name; }

int Flight::getDuration() { return duration; }

int Flight::getPrice() { return price; }


