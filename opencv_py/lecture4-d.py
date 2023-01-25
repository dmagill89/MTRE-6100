import cv2
import numpy as np
import sys

img = cv2.imread("starry_night.jpg")

if img is None:
    sys.exit("Could not read the image")

# print total number of elements
print('Image Size:', img.size)
print('Image Shape:', img.shape)

# Display Image
cv2.imshow("Image Starry Night", img)

key = cv2.waitKey(0)

# ord returns the ASCII/Unicode integer value of the input
if (key == ord('s')):
    cv2.imwrite('starry_save.png', img)

area_of_interest = img[10:131, 10:131]

# replease section with area of interest
img[100:221, 100:221] = area_of_interest

print('Share of area of interest', area_of_interest.shape)

cv2.imshow("Image Starry Night", img)
key = cv2.waitKey(0)

gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Display Image
cv2.imshow("Gray Image", gray_img)
key = cv2.waitKey(0)

import_gray_img = cv2.imread('starry_night.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow("Gray Image", import_gray_img)
key = cv2.waitKey(0)

