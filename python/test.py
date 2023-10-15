# import the module
import ctypes  
# load the library
lib = ctypes.cdll.LoadLibrary('./build/libmain.so')
  
# create a Geek class
class Test(object):
  
    # constructor
    def __init__(self):
  
        # attribute
        self.obj = lib.Test_new()
  
    # define method
    def setX(self, x):
        lib.setX(self.obj, x)
        
    def getX(self):
        return lib.getX(self.obj)


f = Test()

f.setX(109)
print(f.getX())
