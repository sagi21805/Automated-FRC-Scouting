import ctypes 

lib = ctypes.CDLL('./build/libmain.so')

FIELD_OBJECT = ctypes.POINTER(ctypes.c_char)



class Field():
  
    def __init__(self, path: str):
        
        lib.newField.argtypes = [ctypes.c_char_p]
        lib.newField.restype = FIELD_OBJECT
        
        s = path.encode("utf-8")
        buff = ctypes.create_string_buffer(s)
        self.obj = lib.newField(buff)
  
    def run(self):
        
        lib.runField.argtypes = [FIELD_OBJECT]
        
        lib.runField(self.obj)
        