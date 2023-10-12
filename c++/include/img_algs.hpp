#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;

vector<Mat> colorFilter(Mat frame, short int blockSize);

Mat stableColor(Mat frame, short int blockSize);

int maxPool2D(Mat block);

int minPool2D(Mat block);