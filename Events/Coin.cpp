#include "Coin.h"

Coin::Coin(Player& player) : PlayerEvent(player) {}

void Coin::execute() {
    player.setScore(player.getScore() + 1);
}
