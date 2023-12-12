#include "Observer.h"

Observer::Observer(MonitorStats &stats, MonitorCoordinates &coords, ShowField &view) : stats(stats), coords(coords), view(view){}

void Observer::observe() {
    bool stats_flag = stats.update();
    bool coords_flag = coords.update();
    if (stats_flag || coords_flag){
        view.PrintField();
    }

}