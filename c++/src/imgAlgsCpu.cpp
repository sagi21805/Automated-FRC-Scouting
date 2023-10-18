#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "imgAlgsCpu.hpp"
#include <cmath>
#include "vectorFuncs.hpp"

using namespace std;
using namespace cv;

/*
Skips given number of frames
Args:
`cap` the vidoe instance that is being captured
`framesToSkip` the number of frames that is being skipped
*/
void skipFrames(VideoCapture cap, short int framesToSkip){

	Mat blank;
	for (int i = 0; i < framesToSkip; i++){
		cap.read(blank);
	}

}

/*
Find Maximum in a matrix
Args:
`frame` the frame being maxPooled
return:
`highest` the highest number in the frame
*/
double max(Mat frame){

	double highest;
	cv::minMaxLoc(frame, NULL, &highest, NULL, NULL);

	return highest;
}

/*
Find Minimum a matrix
Args:
`frame` the frame being minPooled
return:
`lowest` the lowest number in the frame
*/
double min(Mat frame){

	double lowest;
	cv::minMaxLoc(frame, &lowest, NULL, NULL, NULL);

	return lowest;
}

/*
Filters the Red color from a given frame.
Args:
`frame` the frame being minPooled
Return:
`filtered` the filtered Frame
*/
Mat filterRed(Mat frame){

	Mat filtered;

	cv::GaussianBlur(frame, filtered, {5, 5}, 1, 1);
	cv::inRange(frame, cv::Scalar(90, 45, 45), cv::Scalar(150, 255, 255), filtered);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 9));

	cv::morphologyEx(filtered, filtered, MORPH_OPEN, kernel);

	return filtered;

}

/*
Filters the Red color from a given frame.
Args:
`frame` the frame being minPooled
Return:
`filtered` the filtered Frame
*/
Mat filterBlue(Mat frame){

	
	Mat filtered;

	cv::GaussianBlur(frame, filtered, {5, 5}, 1, 1);
	cv::inRange(frame, cv::Scalar(130, 50, 50), cv::Scalar(190, 255, 255), filtered);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 9));

	cv::morphologyEx(filtered, filtered, MORPH_OPEN, kernel);
	

	return filtered;
}

/*
checks if two rectangles are intersecting.
Args:
`rectA` array of rectA points [X1, Y1, X2, Y2]
`rectB` array of rectB points [X1, Y1, X2, Y2]
****notice (x1, y1) stands for the top left corner, and (x2, y2) stands for the bottom right corner***
`x` increases the size of rect B in size x in all directions, Defualts to 0
return:
true if the rectangles are intersecting, false otherwise
*/
bool intersectingRect(int *rectA, int *rectB, int x = 0){

	if (rectA[0] < rectB[2] + x && rectA[2] > rectB[0] - x && rectA[1] < rectB[3] + x && rectA[3] > rectB[1] - x) { return true; }
	
	return false;
}

/*
Gets a sorted array of all the pairs of points recognized by YOLO in python, and removes similarities
Args:
`points` array of points sorted by x1 [[x1, y1, x2, y2], [x1, y1 ...] ...]
`size` how many pairs of points are in the array
*/
int** stablePoints(int *points, int size){

	int newShape[2] = {size, 4};

	int** points2D = arr1Dto2D(points, newShape);
	short int reduced = 0;
	short int similar[size]; // [locA, locB, locA, locB] (locA and locB are similar).
	short int index = 0;
	int **out;

	for (short int i = 0; i < size - 1; i++){

		if (isClose(points2D[i], points2D[i+1], 125)){

			similar[index] = i;
			similar[index + 1] = i + 1;

			for (short int k = i + 1; k < size - i -1 ; k++){

				if (isClose(points2D[k], points2D[k+1], 125) && isClose(points2D[i], points2D[k+1], (125-50) * (k-i+1.5))){
					
					similar[index + 1] = k + 1;

					if (k == size - i - 1){ //last time
						reduced += k-i;
					}

				}
				else{
					i += k - i - 1;
					reduced += k - i;
					break;
				}


			}
			index+=2;
		}

	}

	short int constant = 0;
	for (int i = 0, stop = newShape[0]; i < stop; i++){
        out[i] = new int[newShape[1]];
	}
	//real + constant = the row in points2D	
	for (int real = 0; real < size - reduced; real++){
		if (real == similar[real + constant]){
			out[real] = avrageVectorValues(points2D, similar[real + constant], similar[real+constant+1]);
			constant += (similar[real+constant+1] - similar[real + constant]);
		}
		else{
			out[real] = points2D[real + constant]; 
		}
		
	}

	return out;


}
	
		

//TODO make alg that cuts only the field from the video