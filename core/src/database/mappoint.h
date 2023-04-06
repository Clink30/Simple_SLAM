#pragma once

#ifndef MAPPOINT_H
#define MAPPOINT_H

#include "utils/common_include.h"

namespace simple_slam {
struct Frame;
struct Feature;
    
    
struct MapPoint 
{
    public:
     MapPoint() {}

     MapPoint(long id, const Vec3 &position) : _id(id), _pos(position){}

     Vec3 Pos() {
        std::unique_lock<std::mutex> lck(_data_mutex);
        return _pos;
     }

     void SetPos(const Vec3 &pos) {
        std::unique_lock<std::mutex> lck(_data_mutex);
        _pos = pos;
     }

     
     void AddObservation() {
        std::unique_lock<std::mutex> lck(_data_mutex);
        _observation.push_back(feature);
        _observed_times ++;
     }

     void GetObservated() {
        std::unique_lock<std::mutex> lck(_data_mutex);
        return _observations;
     }

     static MapPoint::Ptr CreateNewMappoint();

     void RemoveObservation(std::shared_ptr<Feature> feature);

    public:

     EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
     typedef std::shared_ptr<MapPoint> Ptr;
     


    private:


     unsigned long _id = 0;

     bool _is_outlier = false;

     Vec3 _pos = Vec3::Zero();

     std::mutex _data_mutex;

     int _observed_times = 0;

     std::list<std::weak_ptr<Feature>> _observations;

}
}


#endif 