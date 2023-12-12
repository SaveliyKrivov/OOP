#include <windows.h>
#include "../Logging/MessageHandler.h"
#include "../Logging/PlayerWon.h"
#include "../Logging/PlayerLost.h"
#include "../Logging/GameStarted.h"
#include <fstream>
#include <iostream>
#include "../Control/Controller.h"
#include "../Field/Field.h"
#include "../Field/FieldBuilder.h"
#include "../Field/ShowField.h"
#include "../Player/Player.h"
#include "ReadFile.h"
#include "ReadConsoleCmnds.h"
#include "../Observer/Observer.h"

#ifndef OOP_GAMERUNNER_H
#define OOP_GAMERUNNER_H

enum GameState{Active, Non_active, Win, Lose};

class GameManager {
private:
    GameState gameProgress;
    MessageHandler* consoleHandler = nullptr;
    MessageHandler* fileHandler = nullptr;
public:
    ~GameManager();
    void run();
    bool isRunning();
    void changeGameState(GameState state);
    void askToPlayAgain();
    void processMessage(const Message& msg);
    GameState getGameState();
};


#endif //OOP_GAMERUNNER_H
