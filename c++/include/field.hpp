#ifndef __FIELD__HPP
#define __FIELD__HPP
#include <opencv2/opencv.hpp>
#include "robot.hpp"
#include <opencv2/cudaarithm.hpp>

using namespace cv;

class Field{

    private:
        char *pathToGame; 
        Robot blueTeam[3]; 
        Robot redTeam[3]; 
        cuda::GpuMat currentFrame;
        cuda::GpuMat lastFrame;
        Mat mask; //temporary.


    public:
        Field(char *path); //avilable "/home/sagi/Downloads/videoplayback.mp4" and /same/path/dcmp.mp4  
        void run();
        Size* findRobots();
        void followRobot();


};


#endif