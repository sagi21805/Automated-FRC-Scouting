#include "boundingBox.hpp"
#include "mathUtils.hpp"

BoundingBox::BoundingBox(){
    this->id = -1;
}

BoundingBox::BoundingBox(int *boxWithClass, int id){
    
    this-> id = id;

    this->setBox(boxWithClass);

    this->type = (char) boxWithClass[4];

}

void BoundingBox::setBox(int* boxWithClass){
    
    memcpy(this->box, boxWithClass, 4 * sizeof(int));
    
    this->center = findCenter();

    this->area = boxWithClass[2] * boxWithClass[3]; //w * h

    this->perimeter = 2 * (boxWithClass[2] + boxWithClass[3]);
    
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

bool BoundingBox::isIntersectingTo(BoundingBox b, int difference = 0){
 
	return this->getBox()[0] < (b.getBox()[0] + b.getBox()[2]+ difference) && (this->getBox()[0] + this->getBox()[2]) > (b.getBox()[0] - difference) && this->getBox()[1] < (b.getBox()[1] + b.getBox()[3]+ difference) && (this->getBox()[1] + this->getBox()[3]) > (b.getBox()[1] - difference);
	
}