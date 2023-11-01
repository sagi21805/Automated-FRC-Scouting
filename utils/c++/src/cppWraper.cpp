#include "field.hpp"
#include "robot.hpp"
#include "imgAlgsCpu.hpp"
#include "tracker.hpp"

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

    Tracker* newTracker(){

        return new Tracker();

    }
    
    void _stablePoints(Tracker* t, int *points, int size, int **outArr){

        t -> stablePoints(points, size, outArr);

    }

}