import cv2
import numpy as np
from numba import njit
from numba import prange
import numpy.lib.stride_tricks


# important!! - for very large operations (like s > 15 or even 20) parallel = True improves the calcs by a lot
@njit(fastmath=True)
def stable_color(img: np.ndarray, blockSize: tuple[int, int], thresh):
    blocked = numpy.lib.stride_tricks.sliding_window_view(img, blockSize, axis = 2)
    new = np.zeros((blocked.shape[0], blocked.shape[1]), np.uint8)
    print(blocked[0])
    # for i in prange(len(blocked)):
    #     for j in prange(len(blocked[0])):
    #         if np.sum(blocked[i][j]) > thresh:
    #             new[i][j] = 255
    # return new    

def add_contrast(img):

    lab= cv2.cvtColor(img, cv2.COLOR_BGR2LAB)
    l_channel, a, b = cv2.split(lab)

    clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
    cl = clahe.apply(l_channel)

    limg = cv2.merge((cl,a,b))

    enhanced_img = cv2.cvtColor(limg, cv2.COLOR_LAB2BGR)

    # Stacking the original image with the enhanced image
    return np.hstack((img, enhanced_img))

  
def main():
    # cap = cv2.VideoCapture("/home/sagi/Desktop/vscode/Automated-FRC-Scouting/data/example_vid.mp4")  
    
    # while(1):         
    #     success, frame = cap.read()
    #     if success:  
    #         # hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    #         # h, s, v = cv2.split(hsv)
    #         # s = s + 20
    #         # hsv = cv2.merge((h, s, v))
    #         # hsv = cv2.cvtColor(hsv, cv2.COLOR_HSV2BGR)
    #         # lower_blue = np.array([110,50,50]) 
    #         # upper_blue = np.array([130,255,255]) 
    #         print("\n\n\n\n")
    #         test = stable_color(frame, 2, 1)
    #         # mask = cv2.inRange(hsv, lower_blue, upper_blue) 
    #         # sharpf = add_contrast(hsv)
    #         # cv2.imshow('frame',frame) 
    #         # cv2.imshow('sharpf',sharpf) 
    #         # cv2.imshow('test',test) 

    #         cv2.waitKey(0)
    #     break
    #     # else:
    #     #     break
    test = np.array([[[1, 1, 1], [2, 2, 2], [3, 3, 3], [4, 4, 4]], 
                     [[1, 1, 1], [2, 2, 2], [3, 3, 3], [4, 4, 4]],
                     [[1, 1, 1], [2, 2, 2], [3, 3, 3], [4, 4, 4]], 
                     [[1, 1, 1], [2, 2, 2], [3, 3, 3], [4, 4, 4]]])
    stable_color(test, 2, 3)

    # Destroys all of the HighGUI windows. 
    cv2.destroyAllWindows() 
    
    # release the captured frame 
    # cap.release() 
    
if __name__ == "__main__":
    main()

