#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <Eigen/Eigen>
#include <opencv2/opencv.hpp>
#include <vector>

namespace my_slam {

    struct ImuData
    {
        double timestamp;

        Eigen::Matrix<double, 3, 1> wm;

        Eigen::Matrix<double, 3, 1> am;

        bool operator<(const ImuData &other) { return timestamp < other.timestamp; }
    };

    struct CameraData
    {
        double timestamp;

        std::vector<cv::Mat> images;

        bool operator<(const CameraData &other) { return timestamp < other.timestamp; }
    };
        
} // namespace ov_core


#endif