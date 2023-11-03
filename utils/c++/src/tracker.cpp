#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "vectorFuncs.hpp"
#include "mathUtils.hpp"
#include "tracker.hpp"
#include "boundingBox.hpp"

using std::cout, std::endl;

Tracker::Tracker(int *pointsWithClass, int size){
    this->setTrackPoints(pointsWithClass, size);
}

void Tracker::setTrackPoints(int *pointsWithClass, int size){
	this->currentStableTrack = stablePoints(pointsWithClass, size);
}

BoundingBox* Tracker::getTrackPoints(){
	return this->currentStableTrack;	
}

BoundingBox* Tracker::pointsToBoundingBoxes(int *pointsWithClass, int size){
	
	BoundingBox boundingBoxes[size];

	int pointWithClass[5];
	int constant = 0;

	for (int i = 1; i < size + 1; i++){

		for (int j = 0; i < 5; i++){
			pointWithClass[j] = pointsWithClass[j + constant];
		}

		constant += 5;

		boundingBoxes[i] = BoundingBox(pointWithClass, i);	
	}

	return boundingBoxes;

}

BoundingBox* Tracker::stablePoints(int *pointsWithClass, int size){

	short int pointsSize = 5; //points: [x, y, width, hieght, class]

	BoundingBox *boundingBoxes = pointsToBoundingBoxes(pointsWithClass, size);

	unsigned short int reduced = 0;
	int similar[size]; // [locA, locB, locA, locB] (locA and locB are similar).
	for (int i = 0; i < size; i++){
		similar[i] = size + 1;
	}
	short int index = 0;
	const int distance = 150;

	for (int i = 0; i < size - 1; i++){

		if (boundingBoxes[i].isCloseTo(boundingBoxes[i+1], distance) && boundingBoxes[i].getType() == boundingBoxes[i+1].getType()){

			similar[index] = i;
			similar[index + 1] = i + 1;

			for (int k = i + 1; k < size - i -1 ; k++){

				if (boundingBoxes[k].isCloseTo(boundingBoxes[k+1], distance) && boundingBoxes[k].getType() == boundingBoxes[k+1].getType() && boundingBoxes[i].isCloseTo(boundingBoxes[i+1], (distance-50) * (k-i+1.5)) && boundingBoxes[i].getType() == boundingBoxes[i+1].getType()){
					
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

	BoundingBox out[size-reduced];


	short int constant = 0;
	
	for (int i = 0; i < size; i++){
		cout <<  similar[i] << " "; 
	}	

	for (int real = 0; real < size - reduced; real++){
		if (real == similar[real] + constant){
			avrageBoundingBoxes(out[real], boundingBoxes, similar[real] + constant, similar[real+1] + constant);
			constant += (similar[real+1] - similar[real]);
		}
		else{
			out[real].setBox(boundingBoxes[real + constant].getBox());
		}
		
	}
	

}

	