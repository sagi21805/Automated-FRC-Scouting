import numpy as np
import cv2

# cap = cv2.VideoCapture("/home/sagi/Downloads/dcmp.mp4")

# suc, frame = cap.read()

# # frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

# frame = np.array(frame, dtype=np.int32)

# np.save("./data/arr2", frame)

# frame = np.load("./data/arr2.npy")

# print(frame)

arr = np.array([[2, 2 , 3], [4, 2, 2], [2,21, 2]], dtype = np.int32)
np.save("./data/arr2.npy", arr)
