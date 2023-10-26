#include "FieldEvent.h"

#ifndef OOP_TELEPORT_H
#define OOP_TELEPORT_H


class Teleport: public FieldEvent {
public:
    explicit Teleport(Player& player, Controller& cl, Field& fl);
    ~Teleport() override = default;

    void execute() override;

};

#endif //OOP_TELEPORT_H
