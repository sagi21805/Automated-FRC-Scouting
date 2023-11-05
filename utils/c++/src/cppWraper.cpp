#include "field.hpp"
#include "robot.hpp"
#include "imgAlgsCpu.hpp"
#include "tracker.hpp"

extern "C"{

    Field* _Field(const char *path){

        return new Field(path);

    }

    void run(Field* f){

        f -> run();

    }

    Robot* _RobotDefualt(){

        return new Robot();

    }

    Robot* _Robot(int teamNumber, bool team, int p1[], int p2[]){

        return new Robot(teamNumber,team ,p1 ,p2);
        
    }

    Tracker* _Tracker(int *pointsWithClasses, int size){

        return new Tracker(pointsWithClasses, size);

    }
    
    void _stablePoints(Tracker* t, int *points, int size){

        t -> stablePoints(points, size);

    }

}