#include "cnpy.h"
#include <stdio.h>
#include "NpyArrayFuncs.hpp"
#include "vectorFuncs.hpp"

using namespace std;

/*
returns a 2D vector from .npy file. 
*/
vector<vector<int>> NpyTo2D(cnpy::NpyArray arr){
    vector<size_t> newShape = arr.shape;

    cout << "arr shape" << arr.shape << endl;

    vector<int> input = arr.as_vec<int>();
    return vector1Dto2D(input, newShape);
    
}