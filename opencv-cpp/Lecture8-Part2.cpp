/**
 * C++ program to demonstrate rectangle
 * over a self-formed background image
*/
#include <iostream>
#include <opencv2/core/core.hpp>

// drawing shapes
//#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    // Creating a blank image with black background
    Mat image(500, 500, CV_8UC3, Scalar(0, 0, 0));

    // Check if the image is created
    if (!image.data) {
        cout << "Could no open or find the image.\n" << endl;
        return 1;
    }

    // Top Left Corner
    Point p1(30, 30);

    // Bottom right corner
    Point p2(255, 255);

    int thickness = 2;

    // Drawing the rectangle
    rectangle(image, p1, p2, Scalar(0, 0, 255), thickness, LINE_8);

    // show our image inside a window
    imshow("Output", image);
    waitKey(0);

    return 0;
}
 