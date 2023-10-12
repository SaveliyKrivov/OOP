#include "Controller.h"
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
}

int Controller::getX(){
    return x;
}

int Controller::getY() {
    return y;
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
            if(field.getCell(j, i).isPassable()){
                if(x == j && y == i){
                    cout << " P ";
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

