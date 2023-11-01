import ctypes 
import numpy as np

lib = ctypes.CDLL('./build/libmain.so')

ROBOT_OBJECT = ctypes.POINTER(ctypes.c_char)
c_int_array = np.ctypeslib.ndpointer(dtype=np.int32, ndim=2, flags='C_CONTIGUOUS')

class Robot():
  
    def __init__(self):
        
        lib.RobotDefualt.restype = ROBOT_OBJECT
        
        self.obj = lib.RobotDefualt()
        
    def __init__(self, teamNumber: int, team: bool, p1: np.ndarray, p2: np.ndarray):
        
        lib.newRobot.argtypes = [int, bool, c_int_array, c_int_array]
        lib.newRobot.restype = ROBOT_OBJECT
        
        self.obj = lib.newRobot(teamNumber, team, p1, p2)

        