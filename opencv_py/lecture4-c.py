import cv2
import numpy as np

img = cv2.imread('ml.png')
print('image shape:', img.shape)
img_logo = cv2.imread('opencv-logo.png')

print('Image Shape:', img.shape)
print('Logo Shape:', img_logo.shape)

width = img.shape[1]
height = img.shape[0]

img_logo = cv2.resize(img_logo, (width, height), interpolation = cv2.INTER_AREA)
combined = cv2.addWeighted(img, 0.7, img_logo, 0.3, 0.0)

print('Combined shape:', combined.shape)

cv2.imshow('combined', combined)
cv2.waitKey(0)
cv2.destroyAllWindows()