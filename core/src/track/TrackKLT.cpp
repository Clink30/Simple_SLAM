#include "TrackKLT.h"
#include "utils/print.h"

void TrackKLT::feed_new_camera(const CameraData &message) {
    // (1) 检查数据是否为空
    if(message.image.empty()) {
        PRINT_ALL("[ERROR]: Image is Empty!!! \n");
    }
    // (2) 对图像做直方图均衡化处理
    cv::Mat img;
    if(_histogram_method == HistogramMethod::HISTOGRAM) {
       cv::equalizeHist(message.image,img);
    }
    else if(_histogram_method == HistogramMethod::CLAHE) {
       double eq_clip_limit = 10.0;
       cv::Size eq_win_size = cv::Size(8, 8);
       cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(eq_clip_limit, eq_win_size);
       clahe->apply(message.image, img);
    }
    else {
       img = message.image;
    }

    // (3) 做图像金字塔
    //TODO 可以留着备用，不过暂时用不上。
    
    // (4) Save 
    _img_curr = img;

    // (5) 调用feed_monocular函数处理数据
    feed_monocular(message);
}

void feed_monocular(const CameraData &message) {
     
    // (1) 从类成员中获取图像数据

    // (2) 执行单目特征点计算
    // 如果不存在img_last，则对当前图像执行特征检测操作
    // 如果存在img_last，则对img_last执行特征检测操作

    // (3) 执行特征匹配操作

}