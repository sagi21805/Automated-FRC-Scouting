#include "boundingBox.hpp"
#include "mathUtils.hpp"

BoundingBox::BoundingBox(){
    this->id = -1;
}

BoundingBox::BoundingBox(int *pointWithClass, int id){
    
    this-> id = id;

    this->setBox(pointWithClass);

    this->type = (char) pointWithClass[4];

}

void BoundingBox::setBox(int *pointWithClass){
    
    memcpy(this->box, pointWithClass, 4 * sizeof(int));
    
    this->center = findCenter();

    this->area = pointWithClass[2] * pointWithClass[3]; //w * h

    this->perimeter = 2 * (pointWithClass[2] + pointWithClass[3]);
    
}

int* BoundingBox::getBox(){
    return this->box;
}

char BoundingBox::getClass(){
    return this->type;
}

int* BoundingBox::getCenter(){
    return this->center;
}

char BoundingBox::getType(){
    return this->type;
}

int BoundingBox::squareDistanceTo(BoundingBox b){
    return squareDistance(this->center, b.getCenter());
}

bool BoundingBox::isCloseTo(BoundingBox b, double distance){
	return this->squareDistanceTo(b) <  distance;
}

int* BoundingBox::findCenter(){

	int center[2] = {this->box[0] + this->box[2] / 2, this->box[1] + this->box[3] / 2};
    
    return center;
}

bool BoundingBox::isIntersectingTo(BoundingBox b, int difference){
 
	return this->getBox()[0] < (b.getBox()[0] + b.getBox()[2]+ difference) && (this->getBox()[0] + this->getBox()[2]) > (b.getBox()[0] - difference) && this->getBox()[1] < (b.getBox()[1] + b.getBox()[3]+ difference) && (this->getBox()[1] + this->getBox()[3]) > (b.getBox()[1] - difference);
	
}

//TODO fix this to work with BoundingBoxes
void avrageBoundingBoxes(BoundingBox dest, BoundingBox* boundingBoxes, int startLoc, int stopLoc){


    int x = 0, y = 0, w = 0, h = 0;
    for (int i = startLoc; i < stopLoc + 1; i++){
        x += boundingBoxes[i].getBox()[0];
        y += boundingBoxes[i].getBox()[1];
        w += boundingBoxes[i].getBox()[2];
        h += boundingBoxes[i].getBox()[3];
    }

    short times = stopLoc - startLoc + 1;

    int out[4] = {x/times, y/times, w/times, h/times};

    dest.setBox(out);

}