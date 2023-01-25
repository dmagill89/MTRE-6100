import cv2
import numpy as np

# Part A
# creating an empty canvas
img = np.zeros((512, 512, 3), np.uint8)

# Draw horizontal line across with thickness X
# line(image, starting point, ending point, color, thickness)
cv2.line(img, (0,0), (511, 511), (255, 0, 0), 7)

# Display Image
cv2.imshow("Image Window", img)

# Waitkey to not close the window
# Takes time in ms/0 = waits until key is pressed
key = cv2.waitKey(0)

# Draw rectangle
cv2.rectangle(img, (384, 0), (510, 128), (0, 255, 0), 5)

cv2.imshow("Image Window", img)
key = cv2.waitKey(0)

cv2.ellipse(img, (255,255), (100, 50), 0, 0, 180, (255, 255, 255), 7)

cv2.imshow("Image Window", img)
key = cv2.waitKey(0)

# Draw Polygon
points = np.array([[10, 5], [20, 30], [70, 20], [50, 10], [10, 5]])
print(points)
points.reshape((-1, 1, 2))
print(points)

cv2.polylines(img, [points], True, (0, 255, 255), 3)

cv2.imshow("Image Window", img)
key = cv2.waitKey(0)