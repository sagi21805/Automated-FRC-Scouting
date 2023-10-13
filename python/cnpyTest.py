import numpy as np


arr = np.array([[1, 2, 3, 4], 
                [1, 2, 3, 4], 
                [1, 2, 3, 4]], dtype = np.int32)

np.save("./data/arr2", arr)

arr = np.load("./data/arr3.npy")

print(arr)