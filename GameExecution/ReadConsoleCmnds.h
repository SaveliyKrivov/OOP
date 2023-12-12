#include "ReadFile.h"
#ifndef OOP_READCONSOLE_H
#define OOP_READCONSOLE_H


class ReadConsoleCmnds {
private:
    bool gameInterruption;
    std::map<std::string, Direction> cmnds;
public:
    explicit ReadConsoleCmnds(std::map<std::string, Direction> cmnds, bool gameInterruption = false);
    bool getGameInterruption() const;
    std::tuple<Direction, std::string, bool>readInput();
    char getch();
};


#endif //OOP_READCONSOLE_H
