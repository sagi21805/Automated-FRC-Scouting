#include <stdio.h>
#include "cnpy.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

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

int** arr1Dto2D(int *input, int *newShape){
    
    int** out = new int*[newShape[0]];
    // for (int i = 0, stop = newShape[0]; i < stop; i++){
    //     out[i].resize(newShape[1]);
    // }
    for (int i = 0, stop = newShape[0]; i < stop; i++){
        out[i] = new int[newShape[1]];
    }
    for (int i = 0, stop = newShape[0] * newShape[1]; i < stop; i++){
        int y = i / newShape[1];
        int x = i % newShape[1];
        out[y][x] = input[i];

    }

    return out;
}

bool isClose(int* pointA, int* pointB, short int thresh){

	return pow(pointA[0] - pointB[0], 2) + pow(pointA[1] - pointB[1], 2) <  thresh;

}

int* avrageVectorValues(int** inputArr, int startLoc, int stopLoc){

    int x1, x2, y1, y2 = 0;

    for (int i = startLoc; i < stopLoc + 1; i++){
        x1 += inputArr[i][0];
        y1 += inputArr[i][1];
        x2 += inputArr[i][2];
        y2 += inputArr[i][3];
    }

    int out[4] = {x1, y1, x2, y2};

    return out;
    
}
