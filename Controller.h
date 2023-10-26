#include "Player.h"
#include "Field/Field.h"
#ifndef OOP_CONTROLLER_H
#define OOP_CONTROLLER_H
enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class Controller {
public:
    explicit Controller(Player& player, Field& field);
    ~Controller() = default;

    void move(Direction direction);
    int getX() const;
    int getY() const;

    void setX(int value);
    void setY(int value);

    void heal(int value);
    void takeDamage(int value);
    void addScore(int value);
    void showPlayerStats();
    void showPlayerCoords();
    void showField();
private:
    Player& player;
    Field& field;
    int x, y;
};
#endif //OOP_CONTROLLER_H
