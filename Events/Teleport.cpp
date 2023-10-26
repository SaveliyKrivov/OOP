#include "Teleport.h"

//Teleport::Teleport(Player& player, Field& field) : FieldEvent(player, field){}
//
//void Teleport::execute() {
//
//}

Teleport::Teleport(Player &player, Controller &cl, Field &fl) : PlayerEvent(player), cl(cl), fl(fl){}

void Teleport::execute() {
    if(cl.getX() + 3 < fl.getWidth()){
        cl.setX(cl.getX() + 3);
    }
    if(cl.getY() + 3 < fl.getHeight()){
        cl.setY(cl.getY() + 3);
    }
}