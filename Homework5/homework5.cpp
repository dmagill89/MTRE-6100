#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "includes/video_base.h"
#include "includes/object_detection.h"

using namespace cv;
using namespace cv::xfeatures2d;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv) {
    string file_name;

    cout << "Enter Filer Name: ";
    cin >> file_name;
    cout << file_name << endl;

    ObjectDetection video_base(file_name);

    video_base.play();

    return 0;
}