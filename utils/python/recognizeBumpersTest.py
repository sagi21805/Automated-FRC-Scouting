from ultralytics import YOLO
import cv2
import numpy as np
import time
print("loading video")
cap = cv2.VideoCapture('/home/sagi/Downloads/dcmp.mp4')

# model = YOLO('/home/sagi/Downloads/bumpers.pt')
print("loading YOLO")
# modelGamePiece = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')
modelBumpers = YOLO('data/BumperWeights.pt')

t = time.time()

def skip(cap, skip):
    
    for i in range(skip):
        cap.read()

while cap.isOpened():
    # Read a frame from the video
    success, frame = cap.read()
    print(success)
    if success:
        frame = cv2.resize(frame, (640, 640))
        frame = frame[150:400]
        resultsB = modelBumpers(frame)
        for r in resultsB:
            boxes = r.boxes.cpu().numpy()
            xywh = boxes.xywh
            cls = boxes.cls
            xywhWithCls = np.concatenate((xywh, np.reshape(cls, (6, 1))), 1)       
            s = np.array(xywhWithCls[xywhWithCls[:, 0].argsort()], dtype=np.int32)
            
            for r in s:
                print(r[:2] + r[2:4])
                if r[4] == 0:
                    frame = cv2.rectangle(frame, r[:2] - r[2:4]//2, r[:2] + r[2:4]//2, (0, 255 ,255), 1)    
                if r[4] == 1:
                    frame = cv2.rectangle(frame, r[:2] - r[2:4]//2, r[:2] + r[2:4]//2, (255, 0 ,255), 1)    
            s = s.flatten()
            print(s)
            cv2.imshow('f', frame)
            cv2.waitKey(0)
    break
            # print(out)
            
            # for r in s:
            #     print(r[:2], r[2:4])
            #     frame = cv2.rectangle(frame, xyxyClass[:2], xyxyClass[2:4], (0, 255 ,255), 1)        
        
            # frame = cv2.resize(frame, (640*2, 257*2))
            # cv2.imshow("f", frame)
            # cv2.waitKey(1)
  


    

