#include<opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat frame;

    VideoCapture cap;
    cap.open(0);

    // open the default camera using default API

    while(true){
        cap.read(frame);

        imshow("test", frame);
        
        char key = waitKey(1);
        
        if ( key == 'q' ){
            break;
        }
    }

	cap.release();
	destroyAllWindows();
    
    return 0;
}