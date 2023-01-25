import cv2
import numpy as np

# Part B - Manipulating individual pixels
img = cv2.imread('messi5.jpg')

cv2.imshow("Image Messi", img)

key = cv2.waitKey(0)

print('image shape:', img.shape)

# Access Single Pixel
pixel = img[255, 255]
print('Pixel Information:', pixel)
print('pixel at 255, 255', pixel)

pixel_blue = img[255, 255, 0]
print('blue color at 255, 250', pixel_blue)

#change single pixel
img[255, 255] = [255, 255, 255]
print('pixel at 255, 255:', img[255, 255])
img[0:100, 0:100] = [255, 0, 0]

cv2.imshow("Sample Image", img)
cv2.waitKey(0)

# just blue color
pixel_red = img[300, 300, 2]
print('Red color at pixel 300, 300:', pixel_red)