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
	Mat edge;
	Mat blank;

	short int skipFrames = 7; 
	
	// cout << stableColor() << endl;
	while (true){	
	
		this->lastFrame = this->currentFrame; 
		// resize(this->lastFrame, this->lastFrame, Size(6, 340));

		cap.read(this->currentFrame);

		if (currentFrame.empty()){
			return;
		}

		// resize(currentFrame, currentFrame, Size(640, 340));

		this->currentFrame = stableColor(this->currentFrame, 2);
		
		// Canny(this->currentFrame, edge, 255, 255/3);


		imshow("video", this->currentFrame);
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

