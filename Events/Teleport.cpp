#include "Teleport.h"


Teleport::Teleport(Player &player, Controller &cl, Field &fl) : FieldEvent(player, cl, fl){}

void Teleport::execute() {
    if(cl.getX() + 3 < fl.getWidth()){
        cl.setX(cl.getX() + 3);
    }
    if(cl.getY() + 3 < fl.getHeight()){
        cl.setY(cl.getY() + 3);
    }
}