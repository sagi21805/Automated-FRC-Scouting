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


double squareDistance(int *pointA, int *pointB){
    return pow(pointA[0] - pointB[0], 2) + pow(pointA[1] - pointB[1], 2);
}
