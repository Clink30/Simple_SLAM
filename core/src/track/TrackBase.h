#ifndef TRACK_BASE_H
#define TRACK_BASE_H

#include <opencv/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#include "database/feature.h"
#include "database/sensor_data.h"

namespace simple_slam {
    class Feature;
    class CamBase;
    class Feature;


    class TrackBase
    {
       public: 
        enum HistogramMethod {NONE, HISTOGRAM, CLAHE}

        TrackBase();

        virtual ~TrackBase() {};

        vitrual void feed_new_camera(const CameraData &message) = 0;

        virtual void feed_monocular() = 0;

        virtual void display_active(cv::Mat &img_out, int r1, int g1, int b1, int r2, int g2, int b2, std::string overlay = "");

        virtual void display_history(cv::Mat &img_out, int r1, int g1, int b1, int r2, int g2, int b2, std::vector<size_t> highlighted = {},
                               std::string overlay = ""); 

        std::shared_ptr<Feature> get_feature() {return _feature; }

        void change_feat_id(size_t id_old, size_t id_new);

        int get_num_features() {return _num_feature; }

        void set_num_features(int num_feature) {_num_feature = num_feature};


       protected:
         
        std::shared_ptr<CamBase> _cam_calib;

        std::shared_ptr<Feature> _feature;

        int _num_feature;

        HistogramMethod _histogram_method;
        
        cv::Mat _img_curr;
        cv::Mat _img_last;
        
        std::vector<cv::KeyPoint> _pts_curr;
        std::vector<cv::KeyPoint> _pts_last;

        std::vector<size_t> _ids_last;

    };
    
}


#endif  /* TRACK_BASE_H */