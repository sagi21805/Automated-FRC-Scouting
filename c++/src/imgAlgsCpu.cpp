#include <opencv2/cudaarithm.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "imgAlgsCpu.hpp"
#include <opencv2/cudafilters.hpp>

using namespace std;
using namespace cv;

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




//TODO make alg that cuts only the field from the video