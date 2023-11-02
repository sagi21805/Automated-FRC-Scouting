#ifndef __TRACKER__HPP
#define __TRACKER_HPP

#include "boundingBox.hpp"

class Tracker{
    
    private:
        BoundingBox *currentTrack;
    
    public:
        Tracker(BoundingBox *boundingBoxes);

        BoundingBox* pointsToBoundingBoxes(int **pointsWithClass, int size);

        void stablePoints(int *points, int size, int **pointsOut);

        void track(int ***currentPoints, int ***prevPoints, short int sizeCurrent, short int sizePrev);

};


#endif