from ultralytics import YOLO
import cv2

print("loading video")
cap = cv2.VideoCapture('/home/sagi/Downloads/dcmp.mp4')

# model = YOLO('/home/sagi/Downloads/bumpers.pt')
print("loading YOLO")
modelBumpers = YOLO('./data/weights/best.pt')
# modelGamePiece = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train3/weights/best.pt')
print("DONE")

while cap.isOpened():
    # Read a frame from the video
    success, frame = cap.read()

    if success:
        # Run YOLOv8 inference on the frame
        resultsB = modelBumpers(frame)
        # resultsG = modelGamePiece(frame)
        for r in resultsB:
            boxes = r.boxes.cpu().numpy()
            for box in boxes:
                r = box.xyxy[0].astype(int)
                if box.cls[0] == 1:
                    frame = cv2.rectangle(frame, r[:2], r[2:], (0, 0 ,255), 5)
                if box.cls[0] == 0:
                    frame = cv2.rectangle(frame, r[:2], r[2:], (255, 0 ,0), 5)
        # frame = cv2.resize(frame, (640, 340))
        
        # for r in resultsG:
        #     boxes = r.boxes.cpu().numpy()
        #     for box in boxes:
        #         r = box.xyxy[0].astype(int)
        #         if box.cls[0] == 0:
        #             frame = cv2.rectangle(frame, r[:2], r[2:], (0, 255 ,255), 5)
        #         if box.cls[0] == 1:
        #             frame = cv2.rectangle(frame, r[:2], r[2:], (255, 0 ,255), 5)
        cv2.imshow("f", frame)
        cv2.waitKey(1)

        # cv2.imshow("YOLOv8 Inference", annotated_frame)


    

# Load the YOLOv8 model
# model = YOLO('/home/sagi/Desktop/vscode/Automated-FRC-Scouting/runs/detect/train/weights/best.pt')

# Open the video file

# Loop through the video frames