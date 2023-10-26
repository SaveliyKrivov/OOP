#include "Heal.h"

Heal::Heal(Player& player) : PlayerEvent(player) {}

void Heal::execute() {
    player.setHealth(player.getHealth() + 10);
}