import numpy as np


# arr = np.array([[1, 2, 3, 4, 5], [1, 2, 3, 4, 5]], dtype = np.int32)

# np.save("./tmp/arr2", arr)

arr = np.load("./data/arr3.npy")

print(arr)