#include "Field.h"
#include "../Controller.h"
#include "../Player.h"
#include "../Events/Heal.h"
#include "../Events/Enemy.h"
#include "../Events/Coin.h"
#include "../Events/Teleport.h"

#ifndef OOP_FIELDBUILDER_H
#define OOP_FIELDBUILDER_H
class FieldBuilder {
public:
    explicit FieldBuilder(Field& field, Player& player, Controller& cl);
    ~FieldBuilder() = default;

    void buildField();

private:
    Field& field;
    Player& player;
    Controller& cl;
};
#endif //OOP_FIELDBUILDER_H
