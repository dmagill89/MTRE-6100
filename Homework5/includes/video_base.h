#ifndef VIDEO_BASE_H
#define VIDEO_BASE_H

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

using std::string;
using namespace cv;
using namespace cv::xfeatures2d;

class VideoBase {

    public:
        VideoBase(); // Default constructor

        VideoBase(string file_name); // Overloaded constructor

        void play(); // function to play video

    protected:
        VideoCapture video;

        string file_name;

    private:

};

#endif