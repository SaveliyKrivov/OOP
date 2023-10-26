#include <iostream>
using namespace std;
#include "Player.h"
#include "Controller.h"
#include "Field/Field.h"
#include "Field/FieldBuilder.h"


int main() {
    Player pl(50);
    Field fl(10, 10);
    Controller cl(pl, fl);
    FieldBuilder fb(fl, pl, cl);
    cl.showPlayerStats();
    fb.buildField();
    cl.showField();
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.move(Direction::Right);
    cl.showPlayerCoords();
    cl.showField();
    cl.showPlayerStats();
    cl.move(Direction::Right);
    cl.showField();
    cl.showPlayerCoords();
    cl.move(Direction:: Down);
    cl.move(Direction:: Down);
    cl.move(Direction:: Down);
    cl.move(Direction:: Down);
    cl.move(Direction:: Down);
    cl.move(Direction:: Down);
    cl.showField();
    cl.showPlayerCoords();
    cl.showPlayerStats();



//    Field fl2(10, 10);
//    fl2 = fl;
//
//    fl.getCell(1, 1).setState(false);
//    cout << fl.getWidth() << endl;
//    cout << fl.getHeight() << endl;
//
//    Controller cl(pl, fl);
//    Controller cl2(pl, fl2);
//
//    cl.showField();
//    cl.showPlayerCoords();
////    cl2.showField();
//
//    cl.move(Direction::Right);
////    cl.move(Direction::Right);
//    cl.move(Direction::Down);
//    cl.move(Direction::Down);
//    cl.move(Direction::Down);
//    cl.move(Direction::Down);



//
//
//    cl.showPlayerCoords();
//    cl.showField();
////    cl.move(Direction::Right);
////    cl.move(Direction::Right);
////    cl.move(Direction::Right);
////    cl.move(Direction::Right);
//    cl.takeDamage(15);
//    cl.showPlayerStats();
//
//    cout << cl.getY() << endl;
//    cout << cl.getX() << endl;


    return 0;
}
