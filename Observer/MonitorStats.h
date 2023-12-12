#include "Monitor.h"
#include "../Player/Player.h"
#include "../Control/Controller.h"
#ifndef OOP_MONITORSTATS_H
#define OOP_MONITORSTATS_H


class MonitorStats: Monitor {
public:
    explicit MonitorStats(Player& player);
    bool update() override;
private:
    int prevHealth;
    Player& player;
};


#endif //OOP_MONITORSTATS_H
