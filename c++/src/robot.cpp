#include "robot.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

/*
Constractour to the robot class
Args:
`teamNumber` the robot team number in the game
`team` the team of the robot (red = 0, blue = 1)
`p1 & p1` the points of the bounding box of the robot
*/
Robot::Robot(int teamNumber, bool team, Size p1, Size p2){
    this->teamNumber = teamNumber;
    this->team = team;
    this->p1 = p1;
    this->p2 = p2;
    this->conesHigh = 0;
    this->conesMid = 0;
    this->conesLow = 0;
    this->cubesHigh = 0;
    this->cubesMid = 0;
    this->cubesLow = 0;
    //other params in the future
}

/*
Default Constractour to the robot class
*/
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

/*
returns the robot teamNumber
*/
int Robot::getTeamNumber(){
    return this->teamNumber;
}

/*
returns the robot team
*/
bool Robot::getTeam(){
    return this->team;
}

/*
returns the box
*/
cv::Size* Robot::getBox(){
    cv::Size box[2];
    box[0] = this->p1;
    box[1] = this->p2;
    return box;
}

/*
returns array of cones scored [High, Mid, Low]
*/
short int* Robot::getCones(){
    short int cones[3];
    cones[0] = this->conesHigh;
    cones[1] = this->conesMid;
    cones[2] = this->conesLow;
    return cones;
}

/*
returns array of cubes scored [High, Mid, Low]
*/
short int* Robot::getCubes(){
    short int cubes[3];
    cubes[0] = this->conesHigh;
    cubes[1] = this->conesMid;
    cubes[2] = this->conesLow;
    return cubes;
}