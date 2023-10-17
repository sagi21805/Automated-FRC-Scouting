#include <opencv2/opencv.hpp>
#include "field.hpp"

extern "C"{

    Field* newField(const char *path){

        return new Field(path);

    }

    void runField(Field* f){

        f -> run();

    }

}