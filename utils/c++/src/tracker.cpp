#include <opencv4/opencv2/opencv.hpp>
#include <stdio.h>
#include "vectorFuncs.hpp"
#include "mathUtils.hpp"
#include "tracker.hpp"
#include "boundingBox.hpp"

using std::cout, std::endl;

/*
The default Tracker constractor
-
*/
Tracker::Tracker(){
	
}

/*
Sets the current BoundingBoxes of the tracker
-
Args: 
 - `pointsWithClass (int[])` -> SORTED xywh points with classes [x, y, w, h, c].
 - `size (int)` -> How many points are in the array (Size of the array / size of a point).
*/
void Tracker::setTrackPoints(int *pointsWithClass, int size){

	this-> numOfCurrentBoundingBoxes = size;
	this->currentBoundingBoxes = pointsToBoundingBoxes(pointsWithClass, size); //sets the currentStableStack inside stablePoints.
	cout << "Created\n"; 
}

/*
Finds points that are close together
-
Returns:
 - `SimilarPoints (int[])` -> array of indexes of the similar points 
[LocA, locB, locA, locB .... ,how many points removed]
- `All points between LocA and locB are similar.`

*/
int* Tracker::findSimilarBoundingBoxes(){
	
	unsigned short reduced = 0;
	unsigned short index = 0;
	const int distance = 150;
	int* similar = new int[this->numOfCurrentBoundingBoxes + 1]; // [locA, locB, locA, locB] (locA and locB are similar).

	for (int i = 0, size = this->numOfCurrentBoundingBoxes; i < size ; i++){
		
		similar[i] = size + 1; 

		if (this->currentBoundingBoxes[i].isCloseTo(this->currentBoundingBoxes[i+1], distance) && this->currentBoundingBoxes[i].getClass() == this->currentBoundingBoxes[i+1].getClass()){

			similar[index] = i;
			similar[index + 1] = i + 1;

			for (int k = i + 1; k < size - i -1 ; k++){

				if (this->currentBoundingBoxes[k].isCloseTo(this->currentBoundingBoxes[k+1], distance) && this->currentBoundingBoxes[k].getClass() == this->currentBoundingBoxes[k+1].getClass() && this->currentBoundingBoxes[i].isCloseTo(this->currentBoundingBoxes[i+1], (distance-50) * (k-i+1.5)) && this->currentBoundingBoxes[i].getClass() == this->currentBoundingBoxes[i+1].getClass()){
					
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

/*
Stables the BoundingBoxes that are stored in stableBoundingBoxes
-
*/
void Tracker::stablePoints(){

	int *similar = this->findSimilarBoundingBoxes();
	int constant = 0;
	this->stableBoundingBoxes = std::make_unique<BoundingBox[]>(this->numOfCurrentBoundingBoxes);

	for (int real = 0, size = this->numOfCurrentBoundingBoxes, reduced = similar[size]; real < size - reduced; real++){
		if (real == similar[real] + constant){
			avrageBoundingBoxes(this->stableBoundingBoxes[real], this->currentBoundingBoxes, similar[real] + constant, similar[real+1] + constant);
			constant += (similar[real+1] - similar[real]);
		}
		else{
			this->stableBoundingBoxes[real].setBox(this->currentBoundingBoxes[real + constant].getBox());
		}
		
	}
	
	this->numOfLastStableBoundingBoxes = this->numOfStableBoundingBoxes;
	this-> numOfStableBoundingBoxes = this->numOfCurrentBoundingBoxes - similar[this->numOfCurrentBoundingBoxes];
	delete[] similar;
}

	