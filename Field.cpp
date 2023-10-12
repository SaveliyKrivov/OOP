#include "Field.h"

Field::Field(int width, int height) {
    if (width > 2 && width < 101 && height > 2 && height < 101){
        this->width = width;
        this->height = height;
        }
    else{
        this->width = DEFAULT_WIDTH;
        this->height = DEFAULT_HEIGHT;
    }
    cells = new Cell*[height];
    for(int i=0; i < height; i++) {
        cells[i] = new Cell[width];
    }
    entry = {0, 0};
    exit = {width, height};
}
Field::~Field() {
    for(int i = 0; i < height; i++){
        delete[] cells[i];
    }
    delete[] cells;
}

Cell &Field::getCell(int x, int y) {
    if (x < 0 or x > this->width or y < 0 or y > this->height){
        throw out_of_range("No such cell");
    }
    else{
        return cells[y][x];
    }
}

pair<int, int> Field::getEntry() const {
    return entry;
}

int Field::getWidth() const {
    return this->width;
}

int Field::getHeight() const {
    return this->height;
}

