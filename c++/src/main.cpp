#include <opencv2/opencv.hpp>
#include "field.hpp"
#include <stdio.h>


int main(){
    Field f("/home/sagi/Downloads/videoplayback.mp4");
    f.run();
    
}


