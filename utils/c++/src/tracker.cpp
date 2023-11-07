#include <opencv4/opencv2/opencv.hpp>
#include <stdio.h>
#include "vectorFuncs.hpp"
#include "mathUtils.hpp"
#include "tracker.hpp"
#include "boundingBox.hpp"

using std::cout, std::endl;

Tracker::Tracker(int *pointsWithClass, int size){
	this->setTrackPoints(pointsWithClass, size);
}

Tracker::~Tracker(){
	cout << "Tracker Destructor\n";
	delete[] currentBoundingBoxes;
	delete[] stableBoundingBoxes;
	delete[] lastStableBoundingBoxes;
}

void Tracker::setTrackPoints(int *pointsWithClass, int size){
	this-> numOfCurrentBoundingBoxes = size;

	this->currentBoundingBoxes = pointsToBoundingBoxes(pointsWithClass, size); //sets the currentStableStack inside stablePoints.
}

BoundingBox* Tracker::getStableBoundingBoxes(){
	return this->stableBoundingBoxes;
}

int* Tracker::findSimilarBoundingBoxes(){
	
	unsigned short reduced = 0;
	int* similar = new int[this->numOfCurrentBoundingBoxes + 1]; // [locA, locB, locA, locB] (locA and locB are similar).
	unsigned short index = 0;
	const int distance = 150;

	for (int i = 0, size = this->numOfCurrentBoundingBoxes; i < size ; i++){
		
		similar[i] = size + 1; 

		if (this->currentBoundingBoxes[i].isCloseTo(this->currentBoundingBoxes[i+1], distance) && this->currentBoundingBoxes[i].getType() == this->currentBoundingBoxes[i+1].getType()){

			similar[index] = i;
			similar[index + 1] = i + 1;

			for (int k = i + 1; k < size - i -1 ; k++){

				if (this->currentBoundingBoxes[k].isCloseTo(this->currentBoundingBoxes[k+1], distance) && this->currentBoundingBoxes[k].getType() == this->currentBoundingBoxes[k+1].getType() && this->currentBoundingBoxes[i].isCloseTo(this->currentBoundingBoxes[i+1], (distance-50) * (k-i+1.5)) && this->currentBoundingBoxes[i].getType() == this->currentBoundingBoxes[i+1].getType()){
					
					similar[index + 1] = k + 1;

					if (k == size - i - 1){ //last time
						reduced += k-i;
					}

				}
				else{
					reduced += k - i;
					i += k - i - 1;
					break;
				}


			}
			
			index+=2;

		}


	}

	similar[this->numOfCurrentBoundingBoxes] = reduced;

	return similar;

}


void Tracker::stablePoints(){

	int *similar = this->findSimilarBoundingBoxes();
	int constant = 0;
	BoundingBox* stable = new BoundingBox[this->numOfCurrentBoundingBoxes];

	for (int real = 0, size = this->numOfCurrentBoundingBoxes, reduced = similar[size]; real < size - reduced; real++){
		if (real == similar[real] + constant){
			avrageBoundingBoxes(stable[real], this->currentBoundingBoxes, similar[real] + constant, similar[real+1] + constant);
			constant += (similar[real+1] - similar[real]);
		}
		else{
			stable[real].setBox(this->currentBoundingBoxes[real + constant].getBox());
		}
		
	}
	
	this->numOfLastStableBoundingBoxes = this->numOfStableBoundingBoxes;
	this-> numOfStableBoundingBoxes = this->numOfCurrentBoundingBoxes - similar[this->numOfCurrentBoundingBoxes];
	this->stableBoundingBoxes = stable;
	delete[] similar;
}

	