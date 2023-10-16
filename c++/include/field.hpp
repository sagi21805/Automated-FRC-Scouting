#ifndef __FIELD__HPP
#define __FIELD__HPP
#include <opencv2/opencv.hpp>
#include "robot.hpp"

using namespace cv;

class Field{

    private:
        char *pathToGame; 
        Robot blueTeam[3]; 
        Robot redTeam[3]; 
        Mat currentFrame;
        Mat lastFrame;
        Mat mask; //temporary.


    public:
        Field(const char *path); //avilable "/home/sagi/Downloads/videoplayback.mp4" and /same/path/dcmp.mp4  
        ~Field();
        void run();
        Size* findRobots();
        void followRobot();


};


#endif