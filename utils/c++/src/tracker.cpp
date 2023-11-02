#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "vectorFuncs.hpp"
#include "mathUtils.hpp"
#include "tracker.hpp"

using std::cout, std::endl;

Tracker::Tracker(){
    cout << "Created Tracker";
}

void Tracker::stablePoints(int *points, int size, int **pointsOut){

	short int pointsSize = 5; //points: [x, y, width, hieght, class]

	int newShape[2] = {size, pointsSize};

	
	int **points2D = arr1Dto2D(points, newShape);

	// for (int i = 0; i < size; i++){
	// 	for (int j = 0; j < 5; j++){
	// 		cout << points2D[i][j] << " ";
	// 	}
	// 	cout << endl; 
	// }

	unsigned short int reduced = 0;
	int similar[size]; // [locA, locB, locA, locB] (locA and locB are similar).
	for (int i = 0; i < size; i++){
		similar[i] = size + 1;
	}
	short int index = 0;
	const int thresh = 150;

	for (int i = 0; i < size - 1; i++){

		if (isClose(points2D[i], points2D[i+1], thresh)){


			similar[index] = i;
			similar[index + 1] = i + 1;

			for (int k = i + 1; k < size - i -1 ; k++){

				if (isClose(points2D[k], points2D[k+1], thresh) && isClose(points2D[i], points2D[k+1], (thresh-50) * (k-i+1.5))){
					
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

	int out[size-reduced][pointsSize];


	short int constant = 0;
	
	for (int i = 0; i < size; i++){
		cout <<  similar[i] << " "; 
	}	

	for (int real = 0; real < size - reduced; real++){
		if (real == similar[real] + constant){
			avrageVectorValues(out[real], points2D, similar[real] + constant, similar[real+1] + constant);
			constant += (similar[real+1] - similar[real]);
			out[real][4] = points2D[similar[real] + constant][4]
		}
		else{
			for (int i = 0; i < pointsSize ; i++){
				out[real][i] = points2D[real + constant][i];
			}
		}
		
	}
	
	memcpy(pointsOut, out, (size - reduced) * pointsSize * sizeof(int));

}

void Tracker::track(int ***currentPoints, int***prevPoints, short int sizeCurrent, short int sizePrev){

    cout << "Track" << endl;

}
	