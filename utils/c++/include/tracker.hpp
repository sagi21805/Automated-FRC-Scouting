#ifndef __TRACKER__HPP
#define __TRACKER_HPP

#include "boundingBox.hpp"

class Tracker{
    
    private:

        BoundingBox* stableBoundingBoxes = nullptr;
        BoundingBox* lastStableBoundingBoxes = nullptr;
        int numOfStableBoundingBoxes = 0;
        int numOfLastStableBoundingBoxes = 0;
    
    public:

        BoundingBox* currentBoundingBoxes = nullptr;
        int numOfCurrentBoundingBoxes = 0;

        Tracker(int *pointsWithClass, int size);

        ~Tracker();

        void setTrackPoints(int *pointsWithClass, int size);

        BoundingBox* getStableBoundingBoxes();

        int* findSimilarBoundingBoxes();

        void stablePoints();

};


#endif