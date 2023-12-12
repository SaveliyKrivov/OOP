#include "Monitor.h"
#include "../Control/Controller.h"
#ifndef OOP_MONITORCOORDINATES_H
#define OOP_MONITORCOORDINATES_H


class MonitorCoordinates: Monitor {
public:
    explicit MonitorCoordinates(Controller& cl);
    bool update() override;
private:
    int prevCoordsX;
    int prevCoordsY;
    Controller& cl;
};



#endif //OOP_MONITORCOORDINATES_H
