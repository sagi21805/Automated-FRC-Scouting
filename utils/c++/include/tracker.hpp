#ifndef __TRACKER__HPP
#define __TRACKER_HPP

#include "boundingBox.hpp"

class Tracker{
    
    private:
        BoundingBox *currentStableTrack;
    
    public:
        Tracker(int *pointsWithClass, int size);

        BoundingBox* pointsToBoundingBoxes(int *pointsWithClass, int size);

        BoundingBox* stablePoints(int *points, int size);

        void track(int ***currentPoints, int ***prevPoints, short int sizeCurrent, short int sizePrev);

};


#endif