#include "Controller.h"
#include "Events/Heal.h"
#include "Events/Coin.h"
#include "Events/Enemy.h"
#include "Events/Teleport.h"
#include <tuple>
#include <iostream>
using namespace std;

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
    if (pl){
        event->execute();
        field.getCell(x, y).setEvent(nullptr);
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
    cout << "Health: " << player.getHealth() << endl;
    cout << "Score: " << player.getScore() << endl;
}

void Controller::showPlayerCoords() {
    cout << "Player is currently on " << this->getX() << " " << this->getY() << endl;
}

void Controller::showField() {
    for(int i = 0; i < field.getHeight(); i++){
        for(int j = 0; j < field.getWidth(); j++){
            Event* event = field.getCell(j, i).getEvent();
            if(field.getCell(j, i).isPassable()){
                if(x == j && y == i){
                    cout << " P ";
                }
                else if(field.getExit().first == j && field.getExit().second == i){
                    cout << " E ";
                }
                else if(dynamic_cast<Heal *>(event)){
                    cout << " + ";
                }
                else if(dynamic_cast<Coin *>(event)){
                    cout << " $ ";
                }
                else if(dynamic_cast<Enemy *>(event)){
                    cout << ":D ";
                }
                else if(dynamic_cast<Teleport *>(event)){
                    cout << " @ ";
                }
                else{
                    cout << " _ ";
                }
            }
            else{
                cout << " # ";
            }
        }
        cout << '\n';
    }
}
void Controller::heal(int value) {
    if (value > 0) {
        player.setHealth(player.getHealth() + value);
    }
}

void Controller::takeDamage(int value) {
    if (value > 0){
        player.setHealth(player.getHealth() - value);
    }
}

void Controller::addScore(int value) {
    if (value > 0) {
        player.setScore(player.getScore() + value);
    }
}

