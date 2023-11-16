
#include "ReadFile.h"

//ReadFile::ReadFile() {
////    string inputLine;
//    string includedKeys;
//    vector<string> includedCommands;
//    vector<pair<string, Direction>> commandKeyPairs = {
//            {"command1", Direction::up},
//            {"command2", Direction::left},
//            {"command3", Direction::down},
//            {"command4", Direction::right},
//            {"command5", Direction::finish}
//    };
//
//    fstream file("../commands.txt");
//    if (file.is_open()){
////        file >> inputLine;
////        checkInputCommands(inputLine, includedCommands);
////        file >> inputLine;
////        checkInputKey(inputLine, includedKeys);
////        commands.insert(pair<string, Direction>(inputLine, up));
//        for (const auto& pair : commandKeyPairs) {
//            std::string inputLine;
//            file >> inputLine;
//            checkInputCommands(inputLine, includedCommands);
//            file >> inputLine;
//            checkInputKey(inputLine, includedKeys);
//            commands.insert(pair);
//        }
//    }
//    else{
//        cout << "Error occured when reading a file\n";
//    }
//}
ReadFile::ReadFile() {
    string inputLine;
    string includedKeys;
    vector<string> includedCommands;
    vector<Direction> directions {Up, Left, Down, Right, Finish};

    std::fstream file("../commands.txt");
    if (file.is_open()) {

        int index = 0;
        while (file >> inputLine) {
            checkInputCommands(inputLine, includedCommands);
//            std::cout << "inputLine = " << inputLine << '\n';
            file >> inputLine;
//            std::cout << "inputLine = " << inputLine << '\n';
            checkInputKey(inputLine, includedKeys);
            commands.insert(std::pair<string, Direction>(inputLine, directions[index]));
            index++;
        }
    }
    else {
        std::cout << "Error occurred when reading a file\n";
    }
}


void ReadFile::checkInputCommands(std::string &inputLine, vector<std::string> &includedCommands) {
    if (find(includedCommands.begin(), includedCommands.end(), inputLine) == includedCommands.end()){
        includedCommands.push_back(inputLine);
    }
    else{
        throw std::invalid_argument("commands.txt is incorrect: command duplication");
    }
}

void ReadFile::checkInputKey(std::string &inputLine, std::string &includedKeys) {
    if (inputLine.length() == 1 && includedKeys.find(inputLine) == string::npos){
        includedKeys.append(inputLine);
    }
    else{
        throw std::invalid_argument("commands.txt is incorrect: key error");
    }
}

map<string, Direction> ReadFile::getCommands() {
    return commands;
}