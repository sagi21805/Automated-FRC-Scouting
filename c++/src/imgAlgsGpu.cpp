#include <opencv2/cudaarithm.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "imgAlgsGpu.hpp"
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
double max(cuda::GpuMat frame){

	double highest;
	cuda::minMax(frame, NULL, &highest);

	return highest;
}

/*
Find Minimum a matrix
Args:
`frame` the frame being minPooled
return:
`lowest` the lowest number in the frame
*/
double min(cuda::GpuMat frame){

	double lowest;
	cuda::minMax(frame, &lowest, NULL);

	return lowest;
}

/*
Filters the Red color from a given frame.
Args:
`frame` the frame being minPooled
Return:
`filtered` the filtered Frame
*/
cuda::GpuMat filterRed(cuda::GpuMat frame){

	cuda::GpuMat filtered;

	Ptr<cuda::Filter> guassionFillter = cuda::createGaussianFilter(CV_8UC3, CV_8UC3, {5, 5}, 1, 1);
	guassionFillter->apply(frame, filtered);

	cuda::inRange(frame, {90, 45, 45}, {150, 255, 255}, filtered);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 9));
	Ptr<cuda::Filter> morph = cuda::createMorphologyFilter(MORPH_OPEN, CV_8UC1, kernel);

	morph->apply(filtered, filtered);

	return filtered;

}

/*
Filters the Blue color from a given frame.
Args:
`frame` the frame being minPooled
Return:
`filtered` the filtered Frame
*/
cuda::GpuMat filterBlue(cuda::GpuMat frame){

	cuda::GpuMat out;

	Ptr<cuda::Filter> guassionFillter = cuda::createGaussianFilter(CV_8UC3, CV_8UC3, {5, 5}, 1, 1);
	guassionFillter->apply(frame, out);

	cuda::inRange(frame, {130, 50, 50}, {190, 255, 255}, out);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 9));
	Ptr<cuda::Filter> morph = cuda::createMorphologyFilter(MORPH_OPEN, CV_8UC1, kernel);
	
	morph->apply(out, out);

	return out;
}




//TODO make alg that cuts only the field from the video
