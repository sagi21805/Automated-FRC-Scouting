#ifndef __ROBOT__HPP
#define __ROBOT__HPP
#include <opencv2/opencv.hpp>
#include "byte.hpp"


class Robot{

    private:
        short int teamNumber;
        bool team; // red = false || blue = true
        cv::Size p1; //first cordinate of the bounding box 
        cv::Size p2; //second cordinate of the bounding box 
        byte conesHigh;
        byte conesMid;
        byte conesLow;
        byte cubesHigh;
        byte cubesMid;
        byte cubesLow;
        //other params in the future


    public:
        Robot(); //defualt contructor
        Robot(int teamNumbar, bool team, cv::Size p1, cv::Size p2);
        int getTeamNumber();
        bool getTeam();
        cv::Size* getBox();
        byte* getCones();
        byte* getCubes();

};


#endif