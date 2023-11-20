#include "GameManager.h"

bool GameManager::isRunning() {
    return gameProgress == Active;
}

void GameManager::changeGameState(GameState state) {
    gameProgress = state;
}

GameState GameManager::getGameState() {
    return gameProgress;
}

void GameManager::run(){
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    changeGameState(Non_active);

    Player player;
    Field field;
    Controller controller(player, field);
    ShowField view(field, controller);

    class ReadFile commands;
    ReadConsoleCmnds cmndsReader(commands.getCommands());

    char level = ' ';
    cout << "Hello! Please select which level you would like to play! 1/2\n";
    while(level != '1' and level != '2'){
        cin >> level;
    }
    if (level == '1'){
        FieldBuilder builder(field, player, controller, 1);
        builder.buildField();
    }
    else if (level == '2'){
        FieldBuilder builder(field, player, controller, 2);
        builder.buildField();
    }

    system("cls");
    changeGameState(Active);
    view.PrintField();
    Direction direction;
    direction = cmndsReader.readInput();

    while(!cmndsReader.getGameInterruption()){
        controller.move(direction);
        if (player.getHealth() == 0){
            changeGameState(Lose);
        }
        else if (controller.getX() == field.getExit().first and controller.getY() == field.getExit().second){
            changeGameState(Win);
        }
        system("cls");
        view.PrintField();
        if (!isRunning()){
            break;
        }
        direction = cmndsReader.readInput();
    }
    if (getGameState() == Lose){
        std::cout << "You lost! Try again\n";
        askToPlayAgain();
    }
    else if (getGameState() == Win){
        std::cout << "You won! Congratulations!\n";
        std::cout <<  "Check out another level if you haven't already!\n";
        askToPlayAgain();
    }
    else{
        std::cout << "Game was stopped\n";
        askToPlayAgain();
    }

}

void GameManager::askToPlayAgain() {
    char choice;
    std::cout << "Would you like to play again? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        run();
    } else if (choice == 'n' || choice == 'N') {
        std::cout << "Thanks for playing!\n";
        exit(0);
    } else {
        std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
        askToPlayAgain();
    }
}


