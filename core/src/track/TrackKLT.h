#ifndef TRACK_KLT_H
#define TRACK_KLT_H

#include "database/sensor_data.h"

namespace simple_slam {
class TrackKLT
{     
public:
  TrackKLT(){}  

  void feed_new_camera(const CameraData &message);

  void feed_monocular(const CameraData &message);

  void perform_detection_monocular();      

  void perform_matching(); 
protected:       
};
}

#endif /* TRACK_KLT_H */