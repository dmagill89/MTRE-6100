#!/usr/bin/env python3
import cv2
import numpy as np

# detect the feature, SIFT detector, Scale-Invariant Feature Transform
def match(img_template, frame):
    sift = cv2.SIFT_create()

    # find the keypoints and descriptors with SIFT
    kp1, des1 = sift.detectAndCompute(img_template, None)
    kp2, des2 = sift.detectAndCompute(frame, None)

    # Algorithm Selection
    FLANN_INDEX_KDTREE = 1

    # get index parameters as dictionary
    index_params = dict(algorithm = FLANN_INDEX_KDTREE, trees=5)

    # get search params
    search_params = dict(checks=50)

    # Use flann based matcher
    flann = cv2.FlannBasedMatcher(index_params, search_params)

    # get KNN matches for K value of 2
    matches = flann.knnMatch(des1, des2, k=2)

    # store all the good matches
    good = []
    for m, n in matches:
        if m.distance < 0.7 * n.distance:
            good.append(m)
    
    if len(good) > 10:
        # Get the source and destination points and reshape array
        source_points = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)
        destination_points = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)

        # Find homography on source/destination points
        M, mask = cv2.findHomography(source_points, destination_points, cv2.RANSAC, 5.0)

        # get height width and depth
        height, width, depth = img_template.shape

        # Reshape points array to match height/width
        points = np.float32([[0, 0], [0, height - 1], [width - 1, height -1], [width - 1, 0]]).reshape(-1, 1, 2)
        destination = cv2.perspectiveTransform(points, M)

        img_polylines = cv2.polylines(frame, [np.int32(destination)], True, 255, 3, cv2.LINE_AA)

        return img_polylines

def main():
    video_capture = cv2.VideoCapture('video.mp4')   # video we want to match against
    valve_template = cv2.imread('valve.png')        # vale template for feature matching       
    circuit_template = cv2.imread('circuit.png')    # circuit template for feature matching

    # Validate that the video has opened and the template images are loaded
    if video_capture.isOpened() == False:
        print("Error opening video stream of file")

    if valve_template is None:
        print("Valce template image does not exist")

    if circuit_template is None:
        print("Circuit template image does not exist")
    
    # loop over the frames of the video
    while(video_capture.isOpened()):
        ret, frame = video_capture.read()

        if ret == True:

            # get the polyines matched image agains both the valve and circtuit templates
            polylines = match(valve_template, frame)
            polylines = match(circuit_template, frame)

            if polylines is not None:
                cv2.imshow('Matching Image', polylines)
                
                key = cv2.waitKey(100)
                if key == ord('q'):
                    exit()
        else:
            print("Unable to capture frame.")
            break

    video_capture.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()