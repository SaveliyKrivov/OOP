#include "PlayerEvent.h"
#ifndef OOP_COIN_H
#define OOP_COIN_H
class Coin: public PlayerEvent{
public:
    explicit Coin(Player& player);
    ~Coin() override = default;

    void execute() override;
};
#endif //OOP_COIN_H
