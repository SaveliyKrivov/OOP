#include "MonitorGameState.h"


MonitorGameState::MonitorGameState(GameManager& game) : game(game) {
    prevState = game.getGameState();
}

bool MonitorGameState::update() {
    if(prevState != game.getGameState()){
        prevState = game.getGameState();
        return true;
    }
    return false;
}