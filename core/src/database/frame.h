#pragma once

#ifndef FRAME_H
#define FRAME_H

#include "cam/CamBase.h"
#include "utils/common_include.h"

#include "feature.h"

namespace simple_slam{
struct Feature;

struct Frame
{
    public:
     Frame(){};
     Frame(long id, double time_stamp, const SE3 &pose, const Mat &img) : 
        _id(id), _time_stamp(time_stamp), _pose(pose), _img(img) {};

     SE3 Pose() {
        std::unique_lock<std::mutex> lck(_pose_mutex);
        return _pose;
     }

     void SetPose(const SE3 &pose) {
        std::unique_lock<std::mutex> lck(_pose_mutex);
        _pose = pose;
     }

     void SetKeyFrame();
    
     static std::shared_ptr<Frame> CreateFrame();
     
    public:

     EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
     typedef std::shared_ptr<Frame> Ptr;
     

    private:

     unsigned long _id = 0;
     unsigned _keyframe_id = 0;

     bool _is_keyframe = false;

     double _time_stamp;

     SE3 _pose;
     std::mutex _pose_mutex;
     cv::Mat _img;

     std::vector<std::shared_ptr<Feature>> features;
};

}

#endif