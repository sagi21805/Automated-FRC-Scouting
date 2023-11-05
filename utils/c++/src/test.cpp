#include "tracker.hpp"

int main(){

    int points[5] = {1, 3, 5, 6, 0};

    Tracker *t = new Tracker(points, 5);

    delete t;

}