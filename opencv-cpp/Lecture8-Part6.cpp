#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include <stdio.h>
#include <iostream>


using namespace cv;
using namespace cv::xfeatures2d;
using std::cout;
using std::endl;

void resize_frame(Mat &ref_frame) {
    cv::resize(ref_frame, ref_frame, cv::Size(), 0.6, 0.6);
}

int main(int argc, char **argv) {
    Mat frame;
    VideoCapture cap;

    Mat img_object = imread("../required_files/Book.png", IMREAD_GRAYSCALE);
    
    if (img_object.empty()) {
        cout << "Could not open or find the object image\n" << endl;
        return -1;
    }

    // Ptr<SURF> detector = SURF::create(400);
    Ptr<SIFT> detector = SIFT::create();
    std::vector<KeyPoint> keypoints_object, keypoints_secne;
    Mat descriptors_object, descriptors_scene;
    detector->detectAndCompute(img_object, noArray(), keypoints_object, descriptors_object);


    cap.open("../required_files/IMG_6826.MOV");
    if (!cap.isOpened()) { 
        cout << "ERROR: Unable to open video.\n" << endl;
        return -1;
    }

    cout << "Start grabbing" << endl << "Press any key to terminate" << endl;

    for(;;) {
        double start_t = (double) getTickCount();

        // wait for a new frame from file and store it into frame
        cap.read(frame);

        // check if we succeeded
        if (frame.empty()) {
            cout << "ERROR: Blanke frame grabbed" << endl;
            return -1;
        }

        // Step 1: Detect the keypoints using SURF Detector, compute the descriptors
        detector->detectAndCompute(frame, noArray(), keypoints_secne, descriptors_scene);

        // Step 2: Matching descriptor vectors with a FLANN based matcher
        // Since SURF is a floating-point descriptor NORM_L2 is used
        Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
        std::vector<std::vector<DMatch>> knn_matches;
        matcher->knnMatch(descriptors_object, descriptors_scene, knn_matches, 2);

        // Filter matches using the Lowe's ratio test
        const float ratio_thresh = 0.75f;
        std::vector<DMatch> good_matches;
        
        for (size_t i = 0; i < knn_matches.size(); i++) {

            if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance) {
                good_matches.push_back(knn_matches[i][0]);
            }
        }

        // Draw Matches
        // localize the object
        std::vector<Point2f> obj;
        std::vector<Point2f> scene;
        
        for (size_t i = 0; i < good_matches.size(); i++) {
            // Get the keypoints from good matches
            obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
            scene.push_back(keypoints_secne[good_matches[i].trainIdx].pt);
        }

        Mat H = findHomography(obj, scene, RANSAC);

        // Get the corners from the image_1 ( the object to be "detected" )
        std::vector<Point2f> obj_corners(4);
        obj_corners[0] = Point2f(0, 0);
        obj_corners[1] = Point2f((float) img_object.cols, 0);
        obj_corners[2] = Point2f((float) img_object.cols, (float) img_object.rows);
        obj_corners[3] = Point2f(0, (float) img_object.rows);
        std::vector<Point2f> scene_corners(4);
        perspectiveTransform(obj_corners, scene_corners, H);

        // draw to video
        line(frame, scene_corners[0], scene_corners[1], Scalar(0, 0, 255), 4);
        line(frame, scene_corners[1], scene_corners[2], Scalar(0, 0, 255), 4);
        line(frame, scene_corners[2], scene_corners[3], Scalar(0, 0, 255), 4);
        line(frame, scene_corners[3], scene_corners[0], Scalar(0, 0, 255), 4);

        resize_frame(frame);
        imshow("Detected book", frame);
        keypoints_secne.clear();

        start_t = ((double) getTickCount() - start_t) / getTickFrequency();
        cout << "takes: " << start_t << endl;

        if (waitKey(5) >= 0) {
            break;
        }
    }

    return 0;
}