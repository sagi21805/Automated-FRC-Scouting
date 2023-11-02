#include <opencv2/opencv.hpp>
#include <stdio.h>

using cv::Mat;

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

double squareDistance(int *pointA, int *pointB){
    return pow(pointA[0] - pointB[0], 2) + pow(pointA[1] - pointB[1], 2);
}
