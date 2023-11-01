import cv2
import numpy as np


def draw_circle(event,x,y,flags,param):
    if event == cv2.EVENT_LBUTTONDBLCLK:
        print([x, y])
    
               
cap = cv2.VideoCapture("/home/sagi/Downloads/d2.mp4")  

success, frame = cap.read()
if success:  
    
    
    # frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # # frame = cv2.resize(frame, (640, 340))
    
    # lowerBlue = np.array([165, 80, 80])
    # upperBlue = np.array([175, 255, 255])
    
    # frame2 = cv2.inRange(frame, lowerBlue, upperBlue)
    
    # lowerRed = np.array([100, 50, 50])
    # upperRed = np.array([130, 255, 255])
    
    # frame3 = cv2.inRange(frame, lowerRed, upperRed)

    # frame = frame[380:823]
    frame = cv2.resize(frame, (640, 640))
    frame = frame[245:487]
    while True:    
        cv2.imshow("image", frame)
        
        # cv2.imshow("blue", frame2)
        
        # cv2.imshow("red", frame3)

        cv2.setMouseCallback("image",draw_circle)
            
        cv2.waitKey(1)
        

