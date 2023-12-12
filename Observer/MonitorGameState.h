#include "Monitor.h"
#include "../GameExecution/GameManager.h"
#ifndef OOP_MONITORGAMESTATE_H
#define OOP_MONITORGAMESTATE_H


class MonitorGameState: Monitor {
public:
    explicit MonitorGameState(GameManager& game);
    bool update() override;
private:
    GameManager& game;
    GameState prevState;
};


#endif //OOP_MONITORGAMESTATE_H
