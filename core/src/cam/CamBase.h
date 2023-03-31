#pragma once

#ifndef CAMBASE_H
#define CAMBASE_H

#include "utils/common_include.h"

namespace simple_slam {

class CamBase
{
public:
    CamBase(){};
    CamBase(double fx, double fy, double cx, double cy, const SE3 &pose) 
        : _fx(fx), _fy(fy), _cx(cx), _cy(cy), _pose(pose){
            _pose_inv = pose.inverse();
        };

    SE3 pose() { return _pose; }

    Mat33 K() {
        Mat33 k;
        k << _fx, 0, _cx, 0, _fy, _cy, 0, 0, 1;
        return k;
    }
    
    Vec3 world2camera(const Vec3 &p_w, const SE3 &T_c_W);
    
    Vec3 camera2world(const Vec3 &p_c, const SE3 &T_c_W);

    Vec2 camera2pixel(const Vec3 &p_c);

    Vec3 pixel2camera(const Vec2 &p_p);

    Vec3 pixel2world(const Vec3 &p_p, const SE3 &T_c_W double depth = 1);

    Vec2 world2pixel(const Vec3 &p_w, const SE3 &T_c_w);

    typedef std::shared_ptr<CamBase> Ptr;

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
private:
    
    double _fx = 0, _fy = 0, _cx = 0, _cy = 0;
    SE3 _pose;
    SE3 _pose_inv;
};

}


#endif //CAMBASE_H