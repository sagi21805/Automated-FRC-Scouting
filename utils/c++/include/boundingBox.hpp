#ifndef __BOUNDING_BOX_HPP
#define __BOUNDING_BOX_HPP

#include "mathUtils.hpp"
#include <opencv4/opencv2/opencv.hpp>


class BoundingBox{

    private:

        int id; 
        int box[4]; //[x, y, w, h]
        char type; 
        int area;
        int perimeter;
        int* center;

    public:

        BoundingBox();
        BoundingBox(int *pointWithClasses, int id);

        void setBox(int *pointWithClasses);

        int* getBox();

        char getClass();

        int* getCenter();

        char getType();

        int squareDistanceTo(BoundingBox b);

        bool isIntersectingTo(BoundingBox b, int difference = 0);

        bool isCloseTo(BoundingBox b, double distance);

        int* findCenter();



};

void avrageBoundingBoxes(BoundingBox dest, BoundingBox* boundingBoxes, int startLoc, int stopLoc);

#endif 