#include "database/mappoint.h"

namespace simple_slam {

MapPoint::Ptr MapPoint::CreateNewMappoint() {
    static long factory_id = 0;
    MapPoint::Ptr new_mappoint(new MapPoint);
    new_mappoint->_id = factory_id ++;
    return new_mappoint;
} 

void MapPoint::RemoveObservation(std::shared_ptr<Feature> feature) {
    std::unique_lock<std::mutex> lck(_data_mutex);
    for( auto iter = _observations.begin(); iter != _observations.end(); iter++) {
        if(iter->lock() == feature) {
            _observations.erase(iter);
            feature->_map_point.reset();
            _observed_times --;
            break;
        }
    }
}

}