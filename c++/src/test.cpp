#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include "imgAlgs.hpp"
#include "NpyArrayFuncs.hpp"
#include "cnpy.h"
#include "vectorFuncs.hpp"

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