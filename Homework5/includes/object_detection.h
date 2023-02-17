#ifndef OBJECT_DETECTION_H
#define OBJECT_DETECTION_H

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "video_base.h"

using std::string;
using namespace cv;
using namespace cv::xfeatures2d;

class ObjectDetection : VideoBase {

    public:
        ObjectDetection(); // default constructor

        ObjectDetection(string file_name); // default constructor

        void object_selection(); // function to allow user to capture object

        void play(); // play video with object detection

        void save_video(); // saves the video

        void take_snapshot(Mat frame); // save a snapshot of the video
    
    private:

        Mat current_frame;

        Mat image_template;

        VideoWriter writer; // video writer for saving

        bool save;

        void match(Mat frame); // match based on selected object
};

#endif