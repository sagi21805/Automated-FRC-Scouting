#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>
#include "imgAlgsGpu.hpp"
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudaimgproc.hpp>

using namespace std;

Field::Field(char *path){
    this->pathToGame = path;
}


void Field::run(){

	Mat currentFrame;

    VideoCapture cap(this->pathToGame);
	
	vector<Mat> a; 

	if (!cap.isOpened()){
			printf("the frame is empty, program stopped.");
			return;
		}
	cap.read(currentFrame);

	this->currentFrame.upload(currentFrame);

	Mat blank;

	cuda::GpuMat redGpu;
	cuda::GpuMat blueGpu;
	Mat red;
	Mat blue;

	short int skipFrames = 3; 
	
	while (true){	
		
		
		
		this->lastFrame = this->currentFrame; 

		cap.read(currentFrame);

		this->currentFrame.upload(currentFrame);

		if (currentFrame.empty()){
			return;
		}

		// this->currentFrame = stableColor(this->currentFrame);

		cuda::cvtColor(this->currentFrame, this->currentFrame, COLOR_BGR2HSV);

		redGpu = filterRed(this->currentFrame);
		blueGpu = filterBlue(this->currentFrame);

		cuda::cvtColor(this->currentFrame, this->currentFrame, COLOR_HSV2BGR);

		redGpu.download(red);
		blueGpu.download(blue);
		resize(blue, blue, Size(640, 340));
		resize(red, red, Size(640, 340));
		resize(currentFrame, currentFrame, Size(640, 340));


		imshow("video", currentFrame);
		imshow("red", red);
		imshow("blue", blue);


		waitKey(1);

		for (int i = 0; i < skipFrames; i++){
			cap.read(blank);
		}
		// break;
		
	}
	return;
}


// Size* Field::findRobots(){

// 	Mat rgb[3]; //[B, G, R]
// 	Mat lb(Vec3i());
// 	Mat hb();
// 	split(this->currentFrame, rgb);

// 	inRange(this->currentFrame, )


// }

