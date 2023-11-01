#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>


int main(){

    std::cout << ::getBuildInformation() << std::endl;

    Field f("/home/sagi21805/Downloads/dcmp.mp4");
    f.run();
    
}


