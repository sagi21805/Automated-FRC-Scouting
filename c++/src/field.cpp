#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>

Field::Field(char *path){
    this->pathToGame = path;
}


void Field::run(){
    VideoCapture cap(this->pathToGame); 
	while (true){	
        if (!cap.isOpened()){
			return;
		}

        if (!currentFrame.empty()){
			this->lastFrame = currentFrame; 
		}

		cap.read(this->currentFrame);

		if (currentFrame.empty()){
			return;
		}
        
        resize(currentFrame, currentFrame, Size(1280, 680));

		imshow("video", currentFrame);
		waitKey(1);
		
	}
	return;
}
