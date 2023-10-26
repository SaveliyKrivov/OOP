#include "Event.h"
#include "../Controller.h"
#include "../Field/Field.h"
#include "../Player.h"
#ifndef OOP_FIELDEVENT_H
#define OOP_FIELDEVENT_H


class FieldEvent: public Event {
public:
    explicit FieldEvent(Player& player, Controller& cl, Field& fl);
    ~FieldEvent() override = default;

    void execute() override = 0;
protected:
    Player& player;
    Controller& cl;
    Field& fl;
};


#endif //OOP_FIELDEVENT_H
