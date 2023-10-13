#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>
#include "imgAlgs.hpp"

using namespace std;

Field::Field(char *path){
    this->pathToGame = path;
}


void Field::run(){
    VideoCapture cap(this->pathToGame);
	
	vector<Mat> a; 

	if (!cap.isOpened()){
			printf("the frame is empty, program stopped.");
			return;
		}
	cap.read(this->currentFrame);

	Mat blank;

	Mat red;

	Mat blue;

	short int skipFrames = 7; 
	
	while (true){	
		
		
		this->lastFrame = this->currentFrame; 

		cap.read(this->currentFrame);

		if (currentFrame.empty()){
			return;
		}

		this->currentFrame = stableColor(this->currentFrame, 1);
		
		cvtColor(this->currentFrame, this->currentFrame, COLOR_BGR2HSV);

		blue = filterBlue(this->currentFrame);
		
		red = filterRed(this->currentFrame);

		cvtColor(this->currentFrame, this->currentFrame, COLOR_HSV2BGR);

		// resize(blue, blue, Size(640, 340));
		// resize(red, red, Size(640, 340));
		// resize(currentFrame, currentFrame, Size(640, 340));

		imshow("video", this->currentFrame);
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

