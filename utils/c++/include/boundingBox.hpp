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
        BoundingBox(int *pointsWithClasses, int id);

        void setBox(int* pointsWithClasses);

        int* getBox();

        char getClass();

        int* getCenter();

        int squareDistanceTo(BoundingBox b);

        bool isIntersectingTo(BoundingBox b, int difference = 0);

        bool isCloseTo(BoundingBox b, double distance);

        int* findCenter();


};

#endif 