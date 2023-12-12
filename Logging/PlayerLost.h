#include "Message.h"
#include "../Control/Controller.h"
#ifndef OOP_PLAYERLOST_H
#define OOP_PLAYERLOST_H


class PlayerLost: public Message{
public:
    PlayerLost(Controller &controller);
    void print(std::ostream& os) const override;

private:
    Controller &controller;
};


#endif //OOP_PLAYERLOST_H
