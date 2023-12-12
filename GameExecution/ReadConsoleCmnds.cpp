#include "ReadConsoleCmnds.h"
#include <windows.h>

ReadConsoleCmnds::ReadConsoleCmnds(std::map<std::string, Direction> cmnds, bool gameInterruption): cmnds(cmnds), gameInterruption(gameInterruption) {}

char ReadConsoleCmnds::getch() {
    char ch;
    HANDLE console;
    DWORD writingMode = 0, ip;
    console = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(console, &writingMode);
    SetConsoleMode(console, writingMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
    ReadConsole(console, &ch, 1, &ip, nullptr);
    SetConsoleMode(console, writingMode);
    return ch;
}

bool ReadConsoleCmnds::getGameInterruption() const {
    return gameInterruption;
}

std::tuple<Direction, std::string, bool> ReadConsoleCmnds::readInput() {
    std::string command;
    bool isValid = true;
    char ch;
    command = "";
    ch = getch();
    command.push_back(ch);
    if (cmnds.find(command) == cmnds.end()) {
        isValid = false;
        return {Direction::Invalid, command, isValid};
    }

    if (cmnds.at(command) == Finish){
        gameInterruption = true;
    }

    return {cmnds.at(command), command, isValid};
}