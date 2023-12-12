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
    std::cout << "Hello! Where would you like to store logging information?\n File - 0, Console - 1, Both - 2, Nowhere - any other key\n";
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
//        std::cout << "Incorrect input: logging info will be stored in console\n";
//        consoleHandler = new MessageHandler(std::cout);
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
    Message* startMessage = new GameStarted(field);
    trackMessage(startMessage);

    system("cls");
    changeGameState(Active);

    view.PrintField();
    Direction direction;


    while(!cmndsReader.getGameInterruption()){
        bool isValid = true;
        std::string keyPressed;
        do{
            auto input = cmndsReader.readInput();
            direction = std::get<0>(input);
            keyPressed = std::get<1>(input);
            isValid = std::get<2>(input);
            if(!isValid){
                Message* invalidCommand = new InvalidCommandPressed(keyPressed);
                trackMessage(invalidCommand);
            }

        }while(!isValid);

        controller.move(direction);
        Message* moveMessage = new ValidCommandPressed(keyPressed, direction);
        trackMessage(moveMessage);
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
        Message* loseMessage = new PlayerLost(controller);
        trackMessage(loseMessage);
        sendMessage();
        std::cout << "You lost! Try again\n";
        askToPlayAgain();
    }
    else if (getGameState() == Win){
        Message* winMessage = new PlayerWon(player);
        trackMessage(winMessage);
        sendMessage();
        std::cout << "You won! Congratulations!\n";
        std::cout <<  "Check out another level if you haven't already!\n";
        askToPlayAgain();
    }
    else{
        std::cout << "Game was stopped\n";
        askToPlayAgain();
    }
    system("pause");

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

void GameManager::trackMessage(Message* msg) {
    if (consoleHandler != nullptr) {
        consoleHandler->trackMessage(*msg);
    }

    if (fileHandler != nullptr) {
        fileHandler->trackMessage(*msg);
    }
}

void GameManager::sendMessage() {
    if (consoleHandler != nullptr) {
        consoleHandler->sendMessages();
    }

    if (fileHandler != nullptr) {
        fileHandler->sendMessages();
    }
}

