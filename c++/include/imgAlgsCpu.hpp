#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "robot.hpp"

using namespace cv;
using namespace std;

void skipFrames(VideoCapture cap, short int framesToSkip);

double max(Mat frame);

double min(Mat frame);

Mat filterRed(Mat frame);

Mat filterBlue(Mat frame);

bool intersectingRect(int *rectA, int *rectB, int x);

Robot* stablePoints(int points[], unsigned int size);

