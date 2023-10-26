#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#define DEFAULT_HEALTH 100
#define DEFAULT_SCORE 0
class Player{
public:
    explicit Player(int health = DEFAULT_HEALTH, int score = DEFAULT_SCORE);

    ~Player() = default;

    int getHealth() const;

    int getLevel() const;

    int getScore() const;

    void setHealth(int value);

    void setLevel(int value);

    void setScore(int value);

private:
    int health;
    int score;
    int level;
};
#endif //OOP_PLAYER_H
