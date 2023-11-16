#include <windows.h>
#include <iostream>
#include "../Control/Controller.h"
#include "../Field/Field.h"
#include "../Field/FieldBuilder.h"
#include "../Field/ShowField.h"
#include "../Player/Player.h"
#include "ReadFile.h"
#include "ReadConsoleCmnds.h"

#ifndef OOP_GAMERUNNER_H
#define OOP_GAMERUNNER_H

enum GameState{Active, Non_active, Win, Lose};

class GameManager {
private:
    GameState gameProgress;
public:
    void run();
    bool isRunning();
    void changeGameState(GameState state);
    GameState getGameState();
};


#endif //OOP_GAMERUNNER_H
