#include "calc.h"

void Calc::digit(int digit) {
	display = display * 10 + digit;
}

void Calc::op(char oper) {
	if(this->oper != 0) {
		switch(this->oper) {
			case '+' :
				result = display + result;
				display = 0;
				this->oper = oper;
				this->error = false;
				break;
			case '-' :
				result = result - display;
				display = 0;
				this->oper = oper;
				this->error = false;
				break;
			case '*' :
				result = result * display;
				display = 0;
				this->oper = oper;
				this->error = false;
				break;
			case '/' :
				if(display == 0) {
					result = 0;
					error = true;
					this->oper = oper;
					break;
				}
				result = result / display;
				display = 0;
				this->oper = oper;
				this->error = false;
				break;
			default:
				break;
		}
	} else {
		result = display;
		display = 0;
		this->oper = oper;
		this->error = false;
	}
}

void Calc::equals() {
	switch(oper) {
		case '+' :
			result = display + result;
			display = result;
			oper = 0;
			break;
		case '-' :
			result = result - display;
			display = result;
			oper = 0;
			break;
		case '*' :
			result = result * display;
			display = result;
			oper = 0;
			break;
		case '/' :
			if(display == 0) {
				result = 0;
				error = true;
				oper = 0;
				break;
			}
			result = result / display;
			display = result;
			oper = 0;
			break;
		default:
			result = display;
			oper = 0;
			break;
	}
}

void Calc::memPlus() {
	memory = memory + display;
	error = false;
}

void Calc::memClear() {
	memory = 0;
}

void Calc::memRecall() {
	display = memory;
}

bool Calc::isError() const {
	return error;
}

void Calc::allClear() {
	memory = 0;
	display = 0;
	result = 0;
	oper = 0;
	error = false;
}

std::ostream &operator<<(std::ostream &out, const Calc &c) {
	if(c.memory == 0) {
		out << c.display;
	} else {
		out << c.display << " M: " << c.memory;
	}
	if(c.error) {
		out << " E";
	}
	return out;
}

