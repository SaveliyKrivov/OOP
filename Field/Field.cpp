#include "Field.h"

Field::Field(int width, int height) {
    if (width > MIN_W && width < MAX_W && height > MIN_H && height < MAX_H){
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
    exit = {width - 1 , height - 1};
}

Field::Field(Field& other) {
    width = other.width;
    height = other.height;
    entry = other.entry;
    exit = other.exit;

    cells = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        for (int i = 0; i < height; i++) {
            delete[] cells[i];
        }
        delete cells;
        height = other.height;
        width = other.width;
        entry = other.entry;
        exit = other.exit;
        cells = new Cell* [height];
        for (int i = 0; i < height; i++) {
            cells[i] = new Cell[width];
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;

}

Field::Field (Field&& other){
    for(int i = 0; i < height; i++){
        delete[] cells[i];
    }
    delete[] cells;

    width = other.width;
    height = other.height;
    cells = other.cells;
    entry = other.entry;
    exit = other.exit;

    other.cells = nullptr;
}

Field& Field::operator=(const Field&& other) {
    if (this != &other) {
        for (int i = 0; i < height; i++) {
            delete[] cells[i];
        }
        delete[] cells;
        height = other.height;
        width = other.width;
        entry = other.entry;
        exit = other.exit;
        cells = new Cell* [height];
        for (int i = 0; i < height; i++) {
            cells[i] = new Cell[width];
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;
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

pair<int, int> Field::getExit() const {
    return exit;
}

int Field::getWidth() const {
    return this->width;
}

int Field::getHeight() const {
    return this->height;
}

