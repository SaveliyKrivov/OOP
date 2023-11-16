#include "Event.h"
#include "../Player/Player.h"
#ifndef OOP_PLAYEREVENT_H
#define OOP_PLAYEREVENT_H

class PlayerEvent : public Event{
public:
    explicit PlayerEvent(Player& player);

    void execute() override = 0;
    virtual ~PlayerEvent() = default;

protected:
    Player& player;
};

#endif //OOP_PLAYEREVENT_H
