#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "imgAlgs.hpp"

using namespace cv;
using namespace std;

//doc
int maxPool2D(Mat frame){

	short int rows = frame.rows;
	short int cols = frame.cols;

	short int highest = 0;

	for (int y = 0; y < rows; ++y){
		for (int x = 0; x < cols; ++x){
			short int val = frame.at<uchar>(y, x); 
			if (val > highest){

				highest = val;

			}

		}
	}
	return highest;
}

int minPool2D(Mat frame){

	short int rows = frame.rows;
	short int cols = frame.cols;

	short int lowest = 255;

	for (int y = 0; y < rows; ++y){
		for (int x = 0; x < cols; ++x){
			short int val = frame.at<uchar>(y, x); 
			if (val < lowest){

				lowest = val;

			}

		}
	}
	return lowest;
}

// TODO make more generic and effiecient 
vector<Mat> colorFilter(Mat frame, short int blockSize){
// three because it is a colored img.
	short int stride = blockSize;
	vector<Mat> out(2);
	vector<Mat> bgr(3);
	split(frame, bgr);

	float thresh = 0.4; //between 0-1
	//all the channels have the same num of rows and cols
	short int rows = bgr[0].rows; // y axis
	short int cols = bgr[0].cols; // x axis

	Mat red = Mat::zeros(cv::Size(cols, rows), CV_8UC1);
	Mat blue = Mat::zeros(cv::Size(cols, rows), CV_8UC1);

	for (int row = 0, rowStop = rows - blockSize; row < rowStop; row+=stride){
		for (int pixel = 0, pixelStop = cols - blockSize; pixel < pixelStop; pixel+=stride){
			Mat blueBlock = bgr[0](cv::Range(row, row + blockSize), cv::Range(pixel, pixel + blockSize));
			Mat greenBlock = bgr[1](cv::Range(row, row + blockSize), cv::Range(pixel, pixel + blockSize));
			Mat redBlock = bgr[2](cv::Range(row, row + blockSize), cv::Range(pixel, pixel + blockSize));
			//TODO make better 
			if (cv::sum(blueBlock)[0] < 50*blockSize*blockSize  && cv::sum(greenBlock)[0] < 50*blockSize*blockSize  && cv::sum(redBlock)[0] > 150*blockSize*blockSize ){

				for (int y = 0; y < blockSize; ++y){
					for (int x = 0; x < blockSize; ++x){
						red.at<uchar>(row + y, pixel + x) = 255;

					}
				}
			}

			if (cv::sum(blueBlock)[0] / (cv::sum(greenBlock)[0] + cv::sum(redBlock)[0] + cv::sum(blueBlock)[0]) > thresh ){

				for (int y = 0; y < blockSize; ++y){
					for (int x = 0; x < blockSize; ++x){
						blue.at<uchar>(row + y, pixel + x) = 255;

					}
				}
			}
		}
	}

	out[0] = red;
	out[1] = blue;

	return out;
}

Mat stableColor(Mat frame, short int blockSize){

//max pooling on red and blue and min pooling on green

	short int stride = blockSize;

	Mat out;

	vector<Mat> bgr(3);

	split(frame, bgr);
	//all the channels have the same num of rows and cols
	short int rows = bgr[0].rows; // y axis
	short int cols = bgr[0].cols; // x axis

	for (int d = 0; d < 3; ++d){
		for (int row = 0, rowStop = rows - blockSize; row < rowStop; row+=stride){
			for (int pixel = 0, pixelStop = cols - blockSize; pixel < pixelStop; pixel+=stride){
				
				Mat block = bgr[d](cv::Range(row, row + blockSize), cv::Range(pixel, pixel + blockSize));
				//TODO make better
				short int poolval = maxPool2D(block);

				// if (d % 2 == 0){
				// 	poolval = maxPool2D(block);
				// }
				// else{
				// 	poolval = minPool2D(block);
				// }

				for (int y = 0; y < blockSize; ++y){
					for (int x = 0; x < blockSize; ++x){
						bgr[d].at<uchar>(row + y, pixel + x) = poolval;

					}
				}
			}

				
			
		}
	}
	merge(bgr, out);

	return out;
}


Mat filterRed(Mat frame){
	Mat filter;

	Mat lower({100, 50, 50});
	Mat upper({141, 255, 255});

	inRange(frame, lower, upper, filter);

	return filter;

}

Mat filterBlue(Mat frame){
	Mat filter;

	Mat lower({160, 80, 80});
	Mat upper({175, 255, 255});

	inRange(frame, lower, upper, filter);

	return filter;
}

Mat cutField(){

}



//TODO make alg that cuts only the field from the video
