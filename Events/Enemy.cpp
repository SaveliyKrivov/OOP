#include "Enemy.h"

Enemy::Enemy(Player &player) : PlayerEvent(player){}

void Enemy::execute() {
    player.setHealth(player.getHealth() - 5);
    player.setScore(player.getScore() + 2);
}