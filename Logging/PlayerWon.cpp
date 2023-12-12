#include "PlayerWon.h"

PlayerWon::PlayerWon(Player &player) : player(player) {}

void PlayerWon::print(std::ostream& os) const {
    os << "Player won with: " << player.getHealth() << "hp, " << player.getScore() << " scores" << std::endl;
}