#include "tracker.hpp"
#include <iostream>

using std::cout;

int main(){

    int size = 2;
    int points[10] = {2, 2, 6, 6, 0, 4, 4, 6, 6, 1};

    Tracker t(points, size);

    t.stablePoints();

    cout << "size " << t.numOfCurrentBoundingBoxes << "\n";
    
    //TESTING STUFF
}