#include "CamBase.h"

namespace simple_slam {

Vec3 CamBase::world2camera(const Vec3 &p_w, const SE3 &T_c_w) {
    return _pose * T_c_w * p_w;
}

Vec3 CamBase::camera2world(const Vec3 &p_c, const SE3 &T_c_w) {
    return T_c_w.inverse() * _pose_inv * p_c;
}

Vec2 CamBase::camera2pixel(const Vec3 &p_c) {
    return Vec2(
            _fx * p_c(0, 0) / p_c(2, 0) + _cx,
            _fy * p_c(1, 0) / p_c(2, 0) + _cy,
    );
}

Vec3 CamBase::pixel2camera(const Vec2 &p_p, double depth) {
    return Vec3(
            (p_p(0, 0) - _cx) * depth / _fx,
            (p_p(1, 0) - _cy) * depth / _fy,
            depth
    );
}

Vec2 CamBase::world2pixel(const Vec3 &p_w, const SE3 &T_c_w) {
    return camera2pixel(world2camera(p_w, T_c_w));
}

Vec3 CamBase::pixel2world(const Vec3 &p_p, const SE3 &T_c_w, double depth) {
    return camera2world(pixel2camera(p_p, depth), T_c_w);
}

}