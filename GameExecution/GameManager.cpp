#include "GameManager.h"

GameManager::~GameManager() {
    delete consoleHandler;
    delete fileHandler;
}

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

    std::ofstream file;
    int choice;
    std::cout << "Hello! Where would you like to store logging information?\n File - 0, Console - 1, Both - 2\n";
    std::cin >> choice;
    if (choice == 0){
        file.open("game_log.txt");
        if (!file.is_open()) {
            std::cout << "File broken";
        }
        fileHandler = new MessageHandler(file);
    }
    else if (choice == 1){
        consoleHandler = new MessageHandler(std::cout);
    }
    else if (choice == 2){
        file.open("game_log.txt");
        if (!file.is_open()) {
            std::cout << "File broken";
        }
        fileHandler = new MessageHandler(file);
        consoleHandler = new MessageHandler(std::cout);
    }
    else{
        std::cout << "Incorrect input: logging info will be stored in console\n";
        consoleHandler = new MessageHandler(std::cout);
    }

    system("cls");


    Player player;
    Field field;
    Controller controller(player, field);
    ShowField view(field, controller);
    MonitorStats stats(player);
    MonitorCoordinates coords(controller);
    Observer observer(stats, coords, view);
    class ReadFile commands;
    ReadConsoleCmnds cmndsReader(commands.getCommands());

    char level = ' ';
    cout << "Please select which level you would like to play! 1/2\n";
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
    GameStarted startMessage(field);
    processMessage(startMessage);
    view.PrintField();
    Direction direction;


    while(!cmndsReader.getGameInterruption()){
        direction = cmndsReader.readInput();
        controller.move(direction);
        observer.observe();
        if (player.getHealth() == 0){
            changeGameState(Lose);
        }
        else if (controller.getX() == field.getExit().first and controller.getY() == field.getExit().second){
            changeGameState(Win);
        }
        if (!isRunning()){
            break;
        }

    }
    view.PrintField();
    if (getGameState() == Lose){
        PlayerLost loseMessage(controller);
        processMessage(loseMessage);
        std::cout << "You lost! Try again\n";
        askToPlayAgain();
    }
    else if (getGameState() == Win){
        PlayerWon winMessage(player);
        processMessage(winMessage);

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

void GameManager::processMessage(const Message& msg) {
    if (consoleHandler != nullptr) {
        consoleHandler->trackMessage(msg);
        consoleHandler->sendMessages();
    }

    if (fileHandler != nullptr) {
        fileHandler->trackMessage(msg);
        fileHandler->sendMessages();
    }
}


