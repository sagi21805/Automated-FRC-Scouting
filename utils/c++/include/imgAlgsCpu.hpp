#ifndef __IMG_ALGS_CPP__
#define __IMG_ALGS_CPP__

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "robot.hpp"

using cv::Mat;

void skipFrames(VideoCapture cap, short int framesToSkip);

Mat filterRed(Mat frame);

Mat filterBlue(Mat frame);

#endif
