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
modelGamePiece = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')
modelBumpers = YOLO('/home/sagi/Downloads/best.pt')

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
        
    
        results = modelGamePiece(frame)
        resultsB = modelBumpers(frame)
        for r in results:
            boxes = r.boxes.data.cpu().numpy()
            xyxyClass = np.delete(boxes, 4, 1)
            s = xyxyClass[xyxyClass[:, 0].argsort()]
            s = np.array(s, dtype=np.int32).flatten()
            out = np.empty((len(s) // 5, 5), dtype=np.int32)
            stablePoints(s, ctypes.c_int32(len(s) // 5), out)
            
            print(out)
            
            for r in out:
                frame = cv2.rectangle(frame, r[:2], r[2:], (0, 255 ,255), 1)
                # frame = cv2.rectangle(frame, r[:2], r[2:], (255, 0 ,255), 1)
        
        
        for r in resultsB:
            boxes = r.boxes.cpu().numpy()
            for box in boxes:
                r = box.xyxy[0].astype(int)
                frame = cv2.rectangle(frame, r[:2], r[2:5], (255, 0 ,0), 1)
                
            frame = cv2.resize(frame, (640*2, 257*2))
            cv2.imshow("f", frame)
            cv2.waitKey(1)
            # skip(cap, 1)
            # print(f"time: {time.time() - t}")
        # cv2.imshow("YOLOv8 Inference", annotated_frame)


    

# Load the YOLOv8 model
# model = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')

# Open the video file

# Loop through the video frames