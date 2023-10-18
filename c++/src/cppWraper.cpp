#include <opencv2/opencv.hpp>
#include "field.hpp"
#include "robot.hpp"
#include "imgAlgsCpu.hpp"

extern "C"{

    Field* newField(const char *path){

        return new Field(path);

    }

    void run(Field* f){

        f -> run();

    }

    Robot* RobotDefualt(){

        return new Robot();

    }

    Robot* newRobot(int teamNumber, bool team, int p1[], int p2[]){

        return new Robot(teamNumber,team ,p1 ,p2);
        
    }
    
    void _stablePoints(int *points, int size, int **arrayOut){
        
        stablePoints(points, size, arrayOut);

    }

}