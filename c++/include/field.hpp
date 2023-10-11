#ifndef __FIELD__HPP
#define __FIELD__HPP
#include <opencv2/opencv.hpp>
#include "robot.hpp"

using namespace cv;

class Field{

    private:
        char *pathToGame; 
        Robot blueTeam[3]; //commented because no defualt constructor
        Robot redTeam[3]; //commented because no defualt constructor
        Mat currentFrame;
        Mat lastFrame;


    public:
        Field(char *path); //avilable "/home/sagi/Downloads/videoplayback.mp4" and /same/path/dcmp.mp4  
        void run();
        void findRobots();
        void followRobot();


};


#endif