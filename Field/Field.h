#include "iostream"
#include "Cell.h"
using namespace std;
#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 10
#define MAX_W 21
#define MIN_W 10
#define MAX_H 21
#define MIN_H 10
#ifndef OOP_FIELD_H
#define OOP_FIELD_H

class Field{
public:
    Field(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
    Field(Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(const Field&& other);

    ~Field();

    Cell& getCell(int x, int y);
    int getWidth() const;
    int getHeight() const;
    pair<int, int> getEntry() const;
    pair<int, int> getExit() const;

private:
    int height;
    int width;
    Cell ** cells;
    pair<int, int> entry;
    pair<int, int> exit;


};

#endif //OOP_FIELD_H
