#ifndef TRACK_KLT_H
#define TRACK_KLT_H

namespace simple_slam {
class TrackKLT
{     
public:
  TrackKLT(){}  

  void feed_new_camera();

  void feed_monocular();

  void perform_detection_monocular();      

  void perform_matching(); 
protected:       
};
}

#endif /* TRACK_KLT_H */