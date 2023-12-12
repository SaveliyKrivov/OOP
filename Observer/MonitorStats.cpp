
#include "MonitorStats.h"

MonitorStats::MonitorStats(Player &player) : player(player){
    prevHealth = player.getHealth();
}


bool MonitorStats::update() {
    if (prevHealth != player.getHealth()){
        prevHealth = player.getHealth();
        return true;
    }
    return false;
}

