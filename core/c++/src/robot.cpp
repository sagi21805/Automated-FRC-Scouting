#include "robot.hpp"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "vectorFuncs.hpp"


using namespace cv;
using namespace std;

Robot::Robot(int teamNumber, bool team, int p1[], int p2[]){
    this->teamNumber = teamNumber;
    this->team = team;
    this->p1 = Size(p1[0], p1[1]);
    this->p2 = Size(p2[0], p2[1]);
    this->conesHigh = 0;
    this->conesMid = 0;
    this->conesLow = 0;
    this->cubesHigh = 0;
    this->cubesMid = 0;
    this->cubesLow = 0;
    //other params in the future
}

Robot::Robot(){
    this->teamNumber = 9999;
    this->team = false;
    this->p1 = Size(0, 0);
    this->p2 = Size(0, 0);
    this->conesHigh = 0;
    this->conesMid = 0;
    this->conesLow = 0;
    this->cubesHigh = 0;
    this->cubesMid = 0;
    this->cubesLow = 0;
}

int Robot::getTeamNumber(){
    return this->teamNumber;
}

bool Robot::getTeam(){
    return this->team;
}

cv::Size* Robot::getBox(){
    cv::Size box[2];
    box[0] = this->p1;
    box[1] = this->p2;
    return box;
}

short int* Robot::getCones(){
    short int cones[3];
    cones[0] = this->conesHigh;
    cones[1] = this->conesMid;
    cones[2] = this->conesLow;
    return cones;
}

short int* Robot::getCubes(){
    short int cubes[3];
    cubes[0] = this->conesHigh;
    cubes[1] = this->conesMid;
    cubes[2] = this->conesLow;
    return cubes;
}

