#include <fstream>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using std::map;
using std::vector;
using std::string;
#ifndef OOP_READFILE_H
#define OOP_READFILE_H

enum Direction {Up, Right, Down, Left, Finish, Invalid};
extern const char* DirectionNames[];

class ReadFile {
private:
    map<string, Direction> commands;
    const map<string, Direction> default_commands{
            {"w", Direction::Up},
            {"a", Direction::Left},
            {"s", Direction::Down},
            {"d", Direction::Right},
            {"x", Direction::Finish}
    };
public:
    map<string, Direction> getCommands();
    void checkInputCommands(string& inputLine, vector<string> &includedCommands);
    void checkInputKey(string& keyLine, string &includedKeys);
    ReadFile();
};


#endif //OOP_READFILE_H
