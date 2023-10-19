from ultralytics import YOLO
import cv2
from imgAlgs import stablePoints
import numpy as np
import ctypes
import time
print("loading video")
cap = cv2.VideoCapture('/home/sagi/Downloads/d2.mp4')

# model = YOLO('/home/sagi/Downloads/bumpers.pt')
print("loading YOLO")
modelBumpers = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')
# modelGamePiece = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train3/weights/best.pt')

t = time.time()

def skip(cap, skip):
    
    for i in range(skip):
        cap.read()

while cap.isOpened():
    # Read a frame from the video
    success, frame = cap.read()

    if success:
        # Run YOLOv8 inference on the frame\
        frame = cv2.resize(frame, (640, 640))
        frame = frame[230:487]
        
    
        results = modelBumpers(frame)
        for r in results:
            boxes = r.boxes.cpu().numpy()
            b = boxes.xyxy.astype(int)
            s = b[b[:, 0].argsort()]
            s = np.array(s, dtype=np.int32).flatten()
                        
            
            out = stablePoints(s, ctypes.c_int32(len(s) // 4))
                        
            for r in out:
                frame = cv2.rectangle(frame, r[:2], r[2:], (0, 255 ,255), 1)
                # frame = cv2.rectangle(frame, r[:2], r[2:], (255, 0 ,255), 1)
        
        
        # for r in resultsG:
        #     boxes = r.boxes.cpu().numpy()
        #     for box in boxes:
        #         r = box.xyxy[0].astype(int)
        #         if box.cls[0] == 0:
        #             frame = cv2.rectangle(frame, r[:2], r[2:], (0, 255 ,255), 5)
        #         if box.cls[0] == 1:
        #             frame = cv2.rectangle(frame, r[:2], r[2:], (255, 0 ,255), 5)
            frame = cv2.resize(frame, (1280, 640))
            cv2.imshow("f", frame)
            cv2.waitKey(1)
            # skip(cap, 1)
            # print(f"time: {time.time() - t}")
        # cv2.imshow("YOLOv8 Inference", annotated_frame)


    

# Load the YOLOv8 model
# model = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')

# Open the video file

# Loop through the video frames