#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include <cv_bridge/cv_bridge.h>

void handle_mono(double time0,cv::Mat img0);
void img_callback(const sensor_msgs::ImageConstPtr &img_msg);

std::shared_ptr<simple_slam::TrackBase> extractor;
ros::Publisher pub_active,pub_history;

int main(int argc, char **argv) {

    ros::init(argc, argv, "test_tracking");

    auto nh = std::make_shared<ros::NodeHandel>("~");

    ros::Subscriber sub_img = nh->subscribe("TOPIC_CAMERA",100,img_callback);

    pub_active = nh.advertise<sensor_msgs::Image>("/track_active",1000);
    
    pub_history = nh.advertise<sensor_msgs::Image>("/track_history",1000);
}

void img_callback(const sensor_msgs::ImageConstPtr &img_msg) {

    cv::Mat img0;
    double time0; 
    cv_bridge::CvImageConstPtr cv_ptr;
    if (img_msg->encoding == "8UC1")
    {
        sensor_msgs::Image img;
        img.header = img_msg->header;
        img.height = img_msg->height;
        img.width = img_msg->width;
        img.is_bigendian = img_msg->is_bigendian;
        img.step = img_msg->step;
        img.data = img_msg->data;
        img.encoding = "mono8";   
        cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::MONO8);     
    }
    else
        cv_ptr = cv_bridge::toCvCopy(img_msg, sensor_msgs::image_encodings::MONO8);

    time0 = cv_ptr->header.stamp.toSec();
    img0 = cv_ptr->image;
    handle_mono(time0,img0);
}

void handle_mono(double time0,cv::Mat img0) {

simple_slam::CameraData message;
message.timestamp = time0;
message.image = img0;
extractor->feed_new_camera(message);


}