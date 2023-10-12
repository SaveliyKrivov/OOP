#include "Cell.h"

Cell::Cell(bool state) {
    this->state = state;
}

void Cell::setState(bool state) {
    this->state = state;
}

bool Cell::isPassable() const {
    return state;
}