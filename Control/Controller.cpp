#include "Controller.h"
#include "../Events/Heal.h"
#include "../Events/Coin.h"
#include "../Events/Enemy.h"
#include "../Events/Teleport.h"
#include <tuple>
#include <iostream>


Controller::Controller(Player& player, Field& field) : player(player), field(field) {
    tie(x, y) = field.getEntry();

}

void Controller::move(Direction direction) {
    switch (direction) {
        case Direction::Down:
            if (y < field.getHeight() && field.getCell(x, y+1).isPassable()){
                y += 1;
            }
            break;
        case Direction::Up:
            if (y > 0 && field.getCell(x, y-1).isPassable()){
                y -= 1;
            }
            break;
        case Direction::Left:
            if (x > 0 && field.getCell(x-1, y).isPassable()){
                x -= 1;
            }
            break;
        case Direction::Right:
            if (x < field.getWidth() && field.getCell(x+1, y).isPassable()){
                x += 1;
            }
            break;
    }
    Event* event = field.getCell(x, y).getEvent();
    auto *pl = dynamic_cast<PlayerEvent *> (event);
    auto *fl = dynamic_cast<FieldEvent *> (event);
    if (pl || fl){
        field.getCell(x, y).setEvent(nullptr);
        event->execute();

    }
}

int Controller::getX() const{
    return x;
}

int Controller::getY() const {
    return y;
}

void Controller::setX(int value) {
    if(value < field.getWidth() && value > 0 && field.getCell(value, y).isPassable()){
        x = value;
    }
}

void Controller::setY(int value) {
    if(value < field.getHeight() && value > 0 && field.getCell(x, value).isPassable()){
        y = value;
    }
}

void Controller::showPlayerStats() {
    std::cout << "Health: " << player.getHealth() << endl;
    std::cout << "Score: " << player.getScore() << endl;
}

void Controller::showPlayerCoords() {
    std::cout << "Player is currently on " << this->getX() << " " << this->getY() << endl;
}



