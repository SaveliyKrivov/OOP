#include "../Field/ShowField.h"
#include "MonitorStats.h"
#include "MonitorCoordinates.h"
#ifndef OOP_OBSERVER_H
#define OOP_OBSERVER_H


class Observer {
public:
    Observer(MonitorStats& stats, MonitorCoordinates& coords, ShowField& view);
    void observe();
private:
    MonitorStats& stats;
    MonitorCoordinates& coords;
    ShowField& view;


};


#endif //OOP_OBSERVER_H
