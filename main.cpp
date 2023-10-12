#include <iostream>
using namespace std;
#include "Player.h"
#include "Controller.h"
#include "Field.h"

int main() {
    Player pl;
    Field fl(10, 10);
    fl.getCell(1, 1).setState(false);
    cout << fl.getWidth() << endl;
    cout << fl.getHeight() << endl;

//    cout << pl.getHealth() << endl;
//    cout << pl.getScore() << endl;
//    pl.setHealth(90);
//    cout << pl.getHealth() << endl;

    Controller cl(pl, fl);
    cl.showField();
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.move(Direction::Down);
    cl.move(Direction::Down);
    cl.move(Direction::Down);
    cl.move(Direction::Down);

    cl.showPlayerCoords();
    cl.showField();
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.takeDamage(15);
    cl.showPlayerStats();

    cout << cl.getY() << endl;
    cout << cl.getX() << endl;


    return 0;
}
