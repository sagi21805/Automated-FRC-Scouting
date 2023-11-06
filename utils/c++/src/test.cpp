#include "tracker.hpp"
#include <iostream>

using std::cout;

int main(){

    int size = 1;
    int points[5] = {2, 2, 6, 6, 0};

    Tracker t(points, size);

    cout << "size " << t.numOfCurrentBoundingBoxes << "\n";
    
    for (int i = 0; i < size; i++){
        t.currentBoundingBoxes[i].print();
    }
    //TESTING STUFF
}