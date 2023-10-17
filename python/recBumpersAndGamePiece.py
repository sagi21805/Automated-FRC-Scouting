from ultralytics import YOLO
import numpy as np
from robot import Robot

ROBOT_MODEL = YOLO("ROBOT.pt")

GAMEPIECE_MODEL = YOLO("gamepiece.pt")

def recRobots(frame: np.ndarray) -> [Robot]:
    
    results = ROBOT_MODEL(frame)
    
    for r in results:
        robots = []
        boxes = r.boxes.cpu().numpy()
        
                
    return robots

def recGamePiece(frame: np.ndarray) -> [Robot]:
    
    results = GAMEPIECE_MODEL(frame)
    
    for r in results:
        robots = []
        boxes = r.boxes.cpu().numpy()
    

        for box in boxes:
            arr = np.array(box.xyxy[0].astype(int), dtypeb = np.int32)
            robots.append(Robot(9999, True, arr[:2], arr[2:]))
                
    return robots
