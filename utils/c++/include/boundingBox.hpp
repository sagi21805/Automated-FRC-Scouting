#ifndef __BOUNDING_BOX_HPP
#define __BOUNDING_BOX_HPP

#include "mathUtils.hpp"

class BoundingBox{

    private:

        int id; 
        int box[4]; //[x, y, w, h]
        char type; 
        int area;
        int perimeter;
        int* center;

    public:
        BoundingBox(int *boxWithClass);

        void setBox(int* boxWithClass);

        int* getBox();

        char getClass();

        int* getCenter();

        int squareDistanceTo(BoundingBox b);

        bool isIntersectingTo(BoundingBox b, int x = 0);

        bool isCloseTo(BoundingBox b, double distance);

        int* findCenter();




};

#endif 