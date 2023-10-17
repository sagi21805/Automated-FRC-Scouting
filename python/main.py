from field import Field
from robot import Robot
import numpy as np

f = Field('/home/sagi/Downloads/dcmp.mp4')

r = Robot()

r.test(np.array([[1, 3, 4], [1, 2, 3]], dtype=np.int32))

