#include "PlayerEvent.h"
#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H


class Enemy: public PlayerEvent {
public:
    explicit Enemy(Player& player);
    ~Enemy() override = default;

    void execute() override;
};


#endif //OOP_ENEMY_H
