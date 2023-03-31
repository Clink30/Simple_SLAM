#ifndef TRACK_BASE_H
#define TRACK_BASE_H

namespace simple_slam {
class TrackBase
{
public:
  TrackBase() {};
  virtual ~TrackBase(){}
  
  virtual void feed_new_camera() = 0;

protected:
};

} 

#endif /* TRACK_BASE_H */