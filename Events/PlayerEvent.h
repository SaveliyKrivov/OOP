#include "Event.h"
#include "../Player.h"
#ifndef OOP_PLAYEREVENT_H
#define OOP_PLAYEREVENT_H

class PlayerEvent : public Event{
public:
    explicit PlayerEvent(Player& player);

    virtual void execute() = 0;
    virtual ~PlayerEvent() = default;

protected:
    Player& player;
};

#endif //OOP_PLAYEREVENT_H
