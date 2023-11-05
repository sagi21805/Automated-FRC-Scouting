import cpp_utils as cpp
import numpy as np

class Tracker():
    
    def __init__(self, points: np.ndarray[int], size:int) -> None:
        
        cpp.lib.newTracker.argtypes = [cpp.int_array, cpp.int]
        cpp.lib.newTracker.restype = cpp.object
        self.obj = cpp.lib._Tracker(points, size)
        
    def stablePoints(self, points: np.ndarray[int], size:int):
        
        cpp.lib.newTracker.argtypes = [cpp.int_array, cpp.int]
        cpp.lib.newTracker.restype = cpp.object
        cpp.lib._stablePoints(points, cpp.c_int(size))
        
    
        
        