#include "cell.h"

Cell::Cell(size_t r, size_t c): r{r}, c{c} {}

void Cell::setPiece(Colour colour) {
	this->colour = colour;
}

void Cell::toggle() {
	if(colour == Colour::Black) colour = Colour::White;
	else if(colour == Colour::White) colour = Colour::Black;
}


void Cell::notify(Subject<Info, State> &whoFrom) override {
	if(whoFrom.getInfo().colour == this->colour) {
		this.setState(StateType::Reply);
	} else {
		this.setState(StateType::Relay);
	}
}

Info getInfo() const override {
	return Info{r,c,colour};
}
