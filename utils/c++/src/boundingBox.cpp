#include "boundingBox.hpp"
#include "mathUtils.hpp"

BoundingBox::BoundingBox(int *boxWithClass){
    
    this->setBox(boxWithClass);
}

void BoundingBox::setBox(int* boxWithClass){
    
    memcpy(this->box, boxWithClass, 4 * sizeof(int));
    
    this->type = (char) boxWithClass[4];

    this->center = findCenter();
    
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