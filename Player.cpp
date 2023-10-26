#include "Player.h"
Player::Player(int health, int score) {

    this->setHealth(health);
    this->setScore(score);
}

int Player::getHealth() const {
    return this->health;
}

int Player::getScore() const {
    return this->score;
}

int Player::getLevel() const {
    return this->level;
}

void Player::setLevel(int value) {
    if(value == 0 || value == 1) {
        this->level = value;
    }
    else{
        this->level = 0;
    }
}

void Player::setHealth(int value) {
    if(value >= 0 and value < 101) {
        this->health = value;
    }
    else if (value < 0){
        this->health = 0;
    }
    else{
        this->health = 100;
    }
}

void Player::setScore(int value) {
    if(value > 0) {
        this->score = value;
    }
    else{
        this->score = 0;
    }
}
