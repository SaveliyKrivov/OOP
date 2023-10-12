
#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell{
public:
    explicit Cell(bool state = true);

    void setState(bool state);
    bool isPassable() const;
private:
    bool state;
};

#endif //OOP_CELL_H
