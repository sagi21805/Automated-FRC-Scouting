#ifndef __TRACKER__HPP
#define __TRACKER_HPP

#include "boundingBox.hpp"

class Tracker{
    
    private:

        BoundingBox* currentBoundingBoxes = nullptr;
        BoundingBox* stableBoundingBoxes = nullptr;
        BoundingBox* lastStableBoundingBoxes = nullptr;
        int numOfCurrentBoundingBoxes = 0;
        int numOfStableBoundingBoxes = 0;
        int numOfLastStableBoundingBoxes = 0;
    
    public:
        Tracker(int *pointsWithClass, int size);

        void setTrackPoints(int *pointsWithClass, int size);

        BoundingBox* getStableBoundingBoxes();

        int* findSimilarBoundingBoxes();

        BoundingBox* pointsToBoundingBoxes(int *pointsWithClass, int size);

        void stablePoints();

};


#endif