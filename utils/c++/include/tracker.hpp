#ifndef __TRACKER__HPP
#define __TRACKER_HPP

#include "boundingBox.hpp"

class Tracker{
    
    private:
        BoundingBox* currentStableTrack;
        int numOfPoints;
    
    public:
        Tracker(int *pointsWithClass, int size);

        void setTrackPoints(int *pointsWithClass, int size);

        BoundingBox* getTrackPoints();

        BoundingBox* pointsToBoundingBoxes(int *pointsWithClass, int size);

        void stablePoints(int *points, int size);

};


#endif