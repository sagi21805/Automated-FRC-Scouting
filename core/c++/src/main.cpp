#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>


int main(){

    std::cout << cv::getBuildInformation() << std::endl;

    Field f("/home/sagi21805/Downloads/dcmp.mp4");
    f.run();
    
}


