
#include "GameStarted.h"

GameStarted::GameStarted(Field &field): field(field) {}

void GameStarted::print(std::ostream& os) const {
    os << "New game started! Field size: [" << field.getWidth() << "," << field.getHeight() << "]\n"
    << "Player on [" << field.getEntry().first << "," << field.getEntry().second << "]" << std::endl;
}