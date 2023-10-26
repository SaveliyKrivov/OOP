#include "PlayerEvent.h"
#ifndef OOP_HEAL_H
#define OOP_HEAL_H

class Heal : public PlayerEvent {
public:
    explicit Heal(Player& player);
    ~Heal() override = default;

    void execute() override;
};
#endif //OOP_HEAL_H
