//#include "FieldEvent.h"
#include "PlayerEvent.h"
#include "../Controller.h"
#include "../Field/Field.h"
#ifndef OOP_TELEPORT_H
#define OOP_TELEPORT_H

//
//class Teleport: public FieldEvent {
//public:
//    explicit Teleport(Player& player, Field& field);
//    ~Teleport() override = default;
//
//    void execute() override;
//
//};


class Teleport: public PlayerEvent {
public:
    explicit Teleport(Player& player, Controller& cl, Field& fl);
    ~Teleport() override = default;

    void execute() override;
private:
    Controller& cl;
    Field& fl;

};

#endif //OOP_TELEPORT_H
