
#include "InvalidCommandPressed.h"

InvalidCommandPressed::InvalidCommandPressed(std::string keyPressed) {
    this->keyPressed = keyPressed;
}

void InvalidCommandPressed::print(std::ostream &os) const {
    os << "Invalid key: " << keyPressed << " was pressed." << std::endl;
}