from ultralytics import YOLO
import cv2
import numpy as np
import numpy.lib.stride_tricks
from numba import njit, prange

print("loading video")
cap = cv2.VideoCapture('/home/sagi/Downloads/dcmp.mp4')

# model = YOLO('/home/sagi/Downloads/bumpers.pt')
print("loading YOLO")
modelBumpers = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train3/weights/best.pt')
# modelGamePiece = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train3/weights/best.pt')
print("DONE")

@njit(fastmath = True)
def func(img: np.ndarray, blockSize: tuple[int, int], thresh):
    blocked = numpy.lib.stride_tricks.sliding_window_view(img, blockSize)
    new = np.zeros((blocked.shape[0], blocked.shape[1]), np.uint8)
    for i in prange(len(blocked)):
        for j in prange(len(blocked[0])):
            if np.sum(blocked[i][j]) > thresh:
                new[i][j] = 255
    return new

while cap.isOpened():
    # Read a frame from the video
    success, frame = cap.read()

    if success:
        # Run YOLOv8 inference on the frame\
        frame = cv2.resize(frame, (640, 340))
        results = modelBumpers(frame)
        for r in results:
            robots = []
            boxes = r.boxes.cpu().numpy()
            boxes = boxes.xyxy.astype(int)
            
            boxes = boxes[boxes[:, 0].argsort()]

            print(boxes)
            
            for r in boxes:
                frame = cv2.rectangle(frame, r[:2], r[2:], (0, 255 ,255), 2)

        
        
        # for r in resultsG:
        #     boxes = r.boxes.cpu().numpy()
        #     for box in boxes:
        #         r = box.xyxy[0].astype(int)
        #         if box.cls[0] == 0:
        #             frame = cv2.rectangle(frame, r[:2], r[2:], (0, 255 ,255), 5)
        #         if box.cls[0] == 1:
        #             frame = cv2.rectangle(frame, r[:2], r[2:], (255, 0 ,255), 5)
        cv2.imshow("f", frame)
        cv2.waitKey(0)

        # cv2.imshow("YOLOv8 Inference", annotated_frame)


    

# Load the YOLOv8 model
# model = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')

# Open the video file

# Loop through the video frames