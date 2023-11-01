#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>
#include "imgAlgsCpu.hpp"

using namespace std;

/*
Field class Constructour
Args:
`path` = the path to the video.
*/
Field::Field(const char *path){

    this->pathToGame = strdup(path);

}

/*
plays the video, and apply recogniton algs
*/
void Field::run(){

    VideoCapture cap(this->pathToGame);
	
	cout << this->pathToGame << endl;

	vector<Mat> a; 

	if (!cap.isOpened()){
			printf("the frame is empty, program stopped.\n");
			return;
		}
	cap.read(this->currentFrame);

	Mat red;
	Mat blue;
	
	while (true){	
		
		
		
		this->lastFrame = this->currentFrame; 

		cap.read(this->currentFrame);

		if (this->currentFrame.empty()){
			return;
		}

		// this->currentFrame = stableColor(this->currentFrame);

		cv::cvtColor(this->currentFrame, this->currentFrame, COLOR_BGR2HSV);

		red = filterRed(this->currentFrame);
		blue = filterBlue(this->currentFrame);

		cv::cvtColor(this->currentFrame, this->currentFrame, COLOR_HSV2BGR);

		resize(blue, blue, Size(640, 340));
		resize(red, red, Size(640, 340));
		resize(currentFrame, currentFrame, Size(640, 340));


		imshow("video", currentFrame);
		imshow("red", red);
		imshow("blue", blue);


		waitKey(1);

		skipFrames(cap, 4);
		
		// break;
		
	}


}

/*
Field Destructour
*/
Field::~Field(){

	if (this->pathToGame != NULL){
		free(this->pathToGame);
	}

}


// Size* Field::findRobots(){

// 	Mat rgb[3]; //[B, G, R]
// 	Mat lb(Vec3i());
// 	Mat hb();
// 	split(this->currentFrame, rgb);

// 	inRange(this->currentFrame, )


// }

