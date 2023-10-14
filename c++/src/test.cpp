#include <iostream>
#include <stdio.h>
#include "imgAlgsGpu.hpp"
#include "NpyArrayFuncs.hpp"
#include "cnpy.h"
#include "vectorFuncs.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/cudaimgproc.hpp>

 

using namespace cv;
using namespace std;

// void onMouse(int event, int x, int y, int flags, void* param){ // now it's in param
//     Mat &xyz = *((Mat*)param); //cast and deref the param



//     if (event == EVENT_LBUTTONDOWN)
//     {
//         short val = xyz.at< short >(y,x); // opencv is row-major ! 
//         cout << "h: " << (int) xyz.at<cv::Vec3b>(y,x)[0] << " " << "s: " <<  (int) xyz.at<cv::Vec3b>(y,x)[1] << " " << "v: " << (int) xyz.at<cv::Vec3b>(y,x)[2] << endl; 
//     }
// }

// int main(){
// 	string path = "/home/sagi/Downloads/dcmp.mp4";
// 	VideoCapture cap(path); //another vid /same/path/dcmp.mp4
// 	Mat img;
// 	// cout << getBuildInformation();
//     long x = 0;
    
// 		// printf("%s\n", path);
//     if (!cap.isOpened()){
//         return 1;
//     }
//     cap.read(img);

//     if (img.empty()){
//         return 1;
//     }
//     // resize(img, img, Size(1280, 680));

//     // cout << rgb[0];

//     img = stableColor(img, 3);
		
// 	cvtColor(img, img, COLOR_BGR2HSV);

//     // resize(img, img, Size(640, 340));

//     imshow("video", img);

//     setMouseCallback("video", onMouse, &img);
//     waitKey(0);

		
	
// 	return 0;
// }

// int main(){
//     cnpy::NpyArray arr = cnpy::npy_load("../data/arr2.npy");

//     vector<vector<int>> v = NpyTo2D(arr);

//     cout << v << endl;
// }

// int main(){
//     std::cout << 0 << endl;

//     cv::Mat img;
//     cv::VideoCapture cap = cv::VideoCapture("/home/sagi/Downloads/dcmp.mp4");
//     std::cout << 1 << endl;

//     cap.read(img);
//     std::cout << 2 << endl;

//     cvtColor(img, img, COLOR_BGR2GRAY);

//     cv::cuda::GpuMat dst, src;
//     src.upload(img);
//     std::cout << 3 << endl;

//     cv::Ptr<cv::cuda::CLAHE> ptr_clahe = cv::cuda::createCLAHE(5.0, cv::Size(8, 8));
    
//     std::cout << 4 << endl;
//     ptr_clahe->apply(src, dst);

//     cv::Mat result;
//     dst.download(result);

//     std::cout << 5 << endl;

//     cv::imshow("result", result);
//     cv::waitKey(0);
// }