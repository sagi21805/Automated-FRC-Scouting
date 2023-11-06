#include "boundingBox.hpp"
#include "mathUtils.hpp"
#include <iostream>

using std::cout;

BoundingBox::BoundingBox(){
    this->id = -1;
}

BoundingBox::BoundingBox(int *pointWithClass, int id){

    this-> id = id;

    this->setBox(pointWithClass);

    this->type = (char) pointWithClass[4];

}

BoundingBox::~BoundingBox(){
    cout << "DESTROYED\n";
    delete[] this->center;
}

void BoundingBox::setBox(int *pointWithClass){

    memcpy(this->box, pointWithClass, 4 * sizeof(int));
    
    this->center = findCenter();

    this->area = pointWithClass[2] * pointWithClass[3]; //w * h

    this->perimeter = 2 * (pointWithClass[2] + pointWithClass[3]);
    
}

void BoundingBox::print(){
    cout << "id " << this->id << "\n"; 
    cout << "x " << this->box[0] << " y " << this->box[1] << " w " << this->box[2] << " h " << this->box[3] << "\n"; //[x, y, w, h]
    cout << "type " << this->type << "\n";
    cout << "area " << this->area << "\n";
    cout << "perimeter " << this->perimeter << "\n";
    cout << "center " << *this->center << "\n";
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

    int* center = new int[2]; 
	center[0] = this->box[0] + this->box[2] / 2;
    center[1] = this->box[1] + this->box[3] / 2;

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

BoundingBox* pointsToBoundingBoxes(int *pointsWithClass, int size){
	
	BoundingBox* boundingBoxes = new BoundingBox[size];

	int pointWithClass[5]; //[x y w h Class] // TODO may be smarter with a smart pointer

	for (int i = 0; i < size; i++){

		memcpy(&pointWithClass[0], &pointsWithClass[i*5], 5 * sizeof(int));
		boundingBoxes[i] = BoundingBox(pointWithClass, i);	
	}

	return boundingBoxes;

}