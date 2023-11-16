#include "Field.h"
#include "../Control/Controller.h"
#include "../Player/Player.h"
#include "../Events/Heal.h"
#include "../Events/Enemy.h"
#include "../Events/Coin.h"
#include "../Events/Teleport.h"
#define DIMENSION_X_1 10
#define DIMENSION_Y_1 10
#define DIMENSION_X_2 20
#define DIMENSION_Y_2 20


#ifndef OOP_FIELDBUILDER_H
#define OOP_FIELDBUILDER_H
class FieldBuilder {
public:
    explicit FieldBuilder(Field& field, Player& player, Controller& cl, int level);
    ~FieldBuilder() = default;

    void buildField();

private:
    int level;
    Field& field;
    Player& player;
    Controller& cl;
};
#endif //OOP_FIELDBUILDER_H
