#include "iostream"
#include "Cell.h"
using namespace std;
#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 10
#ifndef OOP_FIELD_H
#define OOP_FIELD_H

class Field{
public:
    explicit Field(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
    ~Field();

    Cell& getCell(int x, int y);
    int getWidth() const;
    int getHeight() const;
    pair<int, int> getEntry() const;

private:
    int height;
    int width;
    Cell ** cells;
    pair<int, int> entry;
    pair<int, int> exit;


};

#endif //OOP_FIELD_H
