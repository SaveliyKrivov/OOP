#include "Field.h"
#include "../Control/Controller.h"
#include "../Events/Heal.h"
#include "../Events/Coin.h"
#include "../Events/Enemy.h"
#include "../Events/Teleport.h"
#include <iostream>
#ifndef OOP_SHOWFIELD_H
#define OOP_SHOWFIELD_H


class ShowField {
private:
    Field& field;
    Controller& controller;
public:
    ShowField(Field& field, Controller& controller);
    void PrintField();
};


#endif //OOP_SHOWFIELD_H
