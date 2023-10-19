import ctypes 
import numpy as np

lib = ctypes.CDLL('./build/libmain.so')

ROBOT_OBJECT = ctypes.POINTER(ctypes.c_char)
c2D_int_array = np.ctypeslib.ndpointer(dtype=np.int32, ndim=2, flags='C_CONTIGUOUS')
c_int_array = np.ctypeslib.ndpointer(dtype=np.int32, ndim=1, flags='C_CONTIGUOUS')

def stablePoints(points: np.ndarray, size: int):
    
    lib._stablePoints.argtypes = [c_int_array, ctypes.c_int]
    lib._stablePoints.restype = ctypes.POINTER(c2D_int_array)
    return lib._stablePoints(points, size)