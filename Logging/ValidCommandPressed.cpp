
#include "ValidCommandPressed.h"

ValidCommandPressed::ValidCommandPressed(std::string keyPressed, Direction direction): keyPressed(keyPressed), str_direction(DirectionNames[direction]) {}

void ValidCommandPressed::print(std::ostream &os) const {
    os << "Key: " << keyPressed << " was pressed. " << "Command: " << str_direction << " executed." << std::endl;
}