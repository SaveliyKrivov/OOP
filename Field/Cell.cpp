#include "Cell.h"

Cell::Cell(bool state, Event* event) {
    this->state = state;
    this->event = event;
}

Cell::~Cell(){
    delete event;
}

void Cell::setState(bool state) {
    this->state = state;
}

bool Cell::isPassable() const {
    return state;
}

void Cell::setEvent(Event *event) {
    this->event = event;
}

Event* Cell::getEvent() const {
    return event;
}