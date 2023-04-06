#include "database/frame.h"

namespace simple_slam {

Frame::Ptr Frame::CreateFrame() {
    static long factory_id = 0;
    Frame::Ptr new_frame(new Frame);
    new_frame->_id = factory_id++;
    return new_frame;
}

void Frame::SetKeyFrame() {
    static long keyframe_factory_id = 0;
    _is_keyframe = true;
    _keyframe_id = keyframe_factory_id++;
}

}