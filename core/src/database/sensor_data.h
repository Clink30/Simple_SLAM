#pragma once

#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <Eigen/Eigen>
#include <opencv2/opencv.hpp>
#include <vector>

namespace simple_slam {

struct ImuData
{
    double timestamp;

    Eigen::Matrix<double, 3, 1> wm;

    Eigen::Matrix<double, 3, 1> am;

    bool operator<(const ImuData &other) { return timestamp < other.timestamp; }

    typedef std::shared_ptr<ImuData> Ptr;
};

struct CameraData
{
    double timestamp;

    cv::Mat image;

    bool operator<(const CameraData &other) { return timestamp < other.timestamp; }

    typedef std::shared_ptr<CameraData> Ptr;
};
        
} // namespace ov_core


#endif