#include <stdio.h>
#include "cnpy.h"
#include <iostream>
#include <stdexcept>

using namespace std;


/*
Turns a 1D vector into a 2D vector for a given 2D shape
Arg:
`input` the 1D input vector
`newShape` the shape 2D the vector is being turned to
*/
vector<vector<int>> vector1Dto2D(vector<int> input, vector<size_t> newShape){

    if (newShape.size() != 2){
        throw std::invalid_argument( "new shape must contain 2 items" );
    }

    if (!(input.size() == newShape[0] * newShape[1])){
        throw std::invalid_argument( "input shape and the wanted shape dont align" );
    }
    
    vector<vector< int>> out(newShape[0]);

    for (int i = 0, stop = newShape[0]; i < stop; i++){
        out[i].resize(newShape[1]);
    }

    for (int i = 0, stop = input.size(); i < stop; i++){
        int y = i / newShape[1];
        int x = i % newShape[1];
        out[y][x] = input[i];

    }

    return out;
}
