#include "tracker.hpp"
#include <iostream>

using std::cout;

int main(){

    int size = 2;
    int points[10] = {2, 2, 6, 6, 0, 4, 4, 6, 6, 1};

    Tracker t(points, size);

    cout << "size " << t.numOfCurrentBoundingBoxes << "\n";
    
    for (int i = 0; i < size; i++){
        cout << "\n";
        t.currentBoundingBoxes[i].print();
    }
    //TESTING STUFF
}