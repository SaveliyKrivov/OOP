#include "MonitorCoordinates.h"

MonitorCoordinates::MonitorCoordinates(Controller& cl) : cl(cl){
    prevCoordsX = cl.getX();
    prevCoordsY = cl.getY();
}

bool MonitorCoordinates::update() {
    if (prevCoordsX != cl.getX() || prevCoordsY != cl.getY()){
        prevCoordsX = cl.getX();
        prevCoordsY = cl.getY();
        return true;
    }
    return false;
}
