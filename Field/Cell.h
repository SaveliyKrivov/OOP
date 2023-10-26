#include "../Events/Event.h"
#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell{
public:
    explicit Cell(bool state = true, Event* event = nullptr);

    void setState(bool state);
    bool isPassable() const;

    void setEvent(Event * event);
    Event* getEvent() const;

private:
    bool state;
    Event* event;
};

#endif //OOP_CELL_H
