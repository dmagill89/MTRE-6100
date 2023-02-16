#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "video_base.h"

using namespace cv;
using namespace cv::xfeatures2d;
using std::cout;
using std::cin;
using std::endl;
using std::string;

VideoBase::VideoBase() {
    cout << "Object default constructor called" << endl;
}

VideoBase::VideoBase(string file_name) {
    cout << "VideoBase custom constructor called." << endl;
    file_name = file_name;
    video = VideoCapture(file_name);
}

void VideoBase::play() {
    Mat valveTemplate = imread("../required_files/valve.png", IMREAD_GRAYSCALE);          // valve template for feature matching
    Mat circuitTemplate = imread("../required_files/circuit.png", IMREAD_GRAYSCALE);      // circuit template or freature mathcing

    if (!video.isOpened()) {
        cout << "Error opening video stream of file." << endl;
        exit(-1);
    }

    // loop over the frames of the video
    while (video.isOpened()) {
        Mat frame;

        // wait for a new frame from file and store it into frame
        video.read(frame);

        if (frame.empty()) {
            cout << "ERROR: Blank frame grabbed" << endl;
            exit(-1);
        }

        imshow("Frame", frame);

        if (waitKey(5) >= 0) {
            break;
        }
    }
}