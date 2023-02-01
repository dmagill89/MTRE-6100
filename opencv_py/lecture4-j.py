import cv2
import numpy as np

# Part J - Template Matching

# read in the image as gray of conver using cv2.cvtColor()
img = cv2.imread('messi5.jpg', cv2.IMREAD_GRAYSCALE)

# create copy
img_copy = img.copy()

# open template
template = cv2.imread('messi_face.jpg', cv2.IMREAD_GRAYSCALE)

cv2.imshow("Original Image", img)
cv2.imshow("Template", template)
cv2.waitKey(0)

# All the 6 methods for comparrision in a list
methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR', 
            'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']

width, height = template.shape[::-1]

for method in methods:
    img = img_copy.copy()
    method_eval = eval(method)

    # Apply tempalte Matching
    result = cv2.matchTemplate(img, template, method_eval)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)

    # threshold = 0,8
    # loc = np.where( result >= threshold)
    # for pt in zip(*loc[::-1]):
    #     cv2.rectangle(img, pt, (pt[0] + width, pt[1] + height), (0,0,255), 2)

    # If the method is TM_SQDIFF or TM_SQDIFF_NORMED, take minimum
    if method_eval in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
        top_left = min_loc
    else:
        top_left = max_loc
    
    bottom_right = (top_left[0] + width, top_left[1] + height)
    cv2.rectangle(img, top_left, bottom_right, 255, 2) # mark the face on the image

    cv2.imshow("Matched Result", img)
    cv2.waitKey(0)
        
         