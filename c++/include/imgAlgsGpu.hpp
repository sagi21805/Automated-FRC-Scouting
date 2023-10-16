#include <opencv2/opencv.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;


cuda::GpuMat stableColor(cuda::GpuMat frame);

double max(cuda::GpuMat frame);

double min(cuda::GpuMat frame);

cuda::GpuMat filterRed(cuda::GpuMat frame);

cuda::GpuMat filterBlue(cuda::GpuMat frame);

