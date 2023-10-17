#ifndef __ROBOT__HPP
#define __ROBOT__HPP
#include <opencv2/opencv.hpp>


class Robot{

    private:
        short int teamNumber;
        bool team; // red = false || blue = true
        cv::Size p1; //first cordinate of the bounding box 
        cv::Size p2; //second cordinate of the bounding box 
        short int conesHigh;
        short int conesMid;
        short int conesLow;
        short int cubesHigh;
        short int cubesMid;
        short int cubesLow;
        //other params in the future


    public:
        Robot(); //defualt contructor
        Robot(int teamNumber, bool team, cv::Size p1, cv::Size p2);
        int getTeamNumber();
        bool getTeam();
        cv::Size* getBox();
        short int* getCones();
        short int* getCubes();

};


#endif