#include "Message.h"
#include "../Player/Player.h"
#ifndef OOP_PLAYERWON_H
#define OOP_PLAYERWON_H


class PlayerWon: public Message {

public:
    PlayerWon(Player& player);
    void print(std::ostream& os) const override;

private:
    Player &player;
};


#endif //OOP_PLAYERWON_H
