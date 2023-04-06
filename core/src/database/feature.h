#pragma once

#ifndef FEATURE_H
#define FEATURE_H

#include <memory>
#include <opencv2/features2d.hpp>
#include "utils/common_include.h"

namespace simple_slam {

struct Frame;
struct MapPoint;

struct Feature
{
    public:
     Feature() {}
     Feature(std::shared_ptr<Frame> frame, const cv::KeyPoint &kp) 
       : _frame(frame), _position(kp){} 

    public:
     typedef std::shared_ptr<Feature> Ptr; 
     EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    private:
      std::weak_ptr<Frame> _frame;
      std::waek_ptr<MapPoint> _map_point;

      cv::KeyPoint _position;

      bool _is_outlier = false;
};

}

#endif 