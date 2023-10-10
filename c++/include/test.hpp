#ifndef Img_HPP_
#define Img_HPP_
#include <opencv2/opencv.hpp>

using namespace cv;

class Img{

    public:
        Mat img;
        Mat gray;
        int lenSize;
        Img(Mat liveImg, int lenSize);

};
 
#endif