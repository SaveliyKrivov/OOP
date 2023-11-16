#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../GameExecution/ReadFile.h"
#ifndef OOP_CONTROLLER_H
#define OOP_CONTROLLER_H

class Controller {
public:
    explicit Controller(Player& player, Field& field);
    ~Controller() = default;

    void move(Direction direction);
    int getX() const;
    int getY() const;

    void setX(int value);
    void setY(int value);

    void showPlayerStats();
    void showPlayerCoords();
private:
    Player& player;
    Field& field;
    int x, y;
};
#endif //OOP_CONTROLLER_H
