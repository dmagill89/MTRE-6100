#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "object_detection.h"

using std::string;
using std::cout;
using std::endl;
using namespace cv;
using namespace cv::xfeatures2d;

ObjectDetection::ObjectDetection() {
    cout << "ObjectDetection default constructor called" << endl;
}

ObjectDetection::ObjectDetection(string file_name) : VideoBase(file_name) {
    cout << "ObjectDetection custom constructor called." << endl;
}

void ObjectDetection::play() {
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

        // match(frame);
        // match(frame);

        imshow("Frame", frame);

        if (waitKey(5) >= 0) {
            break;
        }
    }
}

void ObjectDetection::match(Mat frame) {
        Ptr<SIFT> detector = SIFT::create();
    std::vector<KeyPoint> keypoints_object, keypoints_scene;
    Mat descriptors_object, descriptors_scene;
    detector->detectAndCompute(image_template, noArray(), keypoints_object, descriptors_object);

    // Step 1: Detect the keypoints using SIFT dectector, compute descriptor
    detector->detectAndCompute(frame, noArray(), keypoints_scene, descriptors_scene);

    // Step 2: Matching descriptor vectors with FLANN based Matcher
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
    std::vector<std::vector<DMatch>> knnMatches;
    matcher->knnMatch(descriptors_object, descriptors_scene, knnMatches, 2);

    // Filter matches using the Lowe's ratio test
    const float ratioThreshold = 0.75f;
    std::vector<DMatch> goodMacthes;

    for (size_t i = 0; i < knnMatches.size(); i++) {
        if (knnMatches[i][0].distance < ratioThreshold * knnMatches[i][1].distance) {
            goodMacthes.push_back(knnMatches[i][0]);
        }
    }

    // Draw Matches
    // localize the object
    std::vector<Point2f> object;
    std::vector<Point2f> scene;

    for (size_t i = 0; i < goodMacthes.size(); i++) {
        // Get keypoints from good matches
        object.push_back(keypoints_object[goodMacthes[i].queryIdx].pt);
        scene.push_back(keypoints_scene[goodMacthes[i].trainIdx].pt);
    }

    Mat H = findHomography(object, scene, RANSAC);

    // Get the corners from template image
    std::vector<Point2f> objectCorners(4);
    objectCorners[0] = Point2f(0, 0);
    objectCorners[1] = Point2f((float) image_template.cols, 0);
    objectCorners[2] = Point2f((float) image_template.cols, (float) image_template.rows);
    objectCorners[3] = Point2f(0, (float) image_template.rows);

    std::vector<Point2f> sceneCorners(4);
    perspectiveTransform(objectCorners, sceneCorners, H);

    // draw to frame
    line(frame, sceneCorners[0], sceneCorners[1], Scalar(0, 0, 255), 4);
    line(frame, sceneCorners[1], sceneCorners[2], Scalar(0, 0, 255), 4);
    line(frame, sceneCorners[2], sceneCorners[3], Scalar(0, 0, 255), 4);
    line(frame, sceneCorners[3], sceneCorners[0], Scalar(0, 0, 255), 4);
}