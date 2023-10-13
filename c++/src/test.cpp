#include <stdio.h>
#include <iostream>
#include "cnpy.h"
#include "vectorFuncs.hpp" 
#include "NpyArrayFuncs.hpp"

using namespace cnpy;
using namespace std;

int main(){
    NpyArray arr = npy_load("/home/sagi/Desktop/vscode/Automated-FRC-Scouting/data/arr2.npy");

    vector<vector<int>> vect = NpyTo2D(arr);
    
    cout << vect << endl;

    cout << vect[0][0] << endl;

    return 0;
}


