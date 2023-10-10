#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "test.hpp"

using namespace cv;
using namespace std;




Mat img;
Mat gray;
int lenSize;

Img::Img(Mat liveImg, int lenSize){

    resize(liveImg, img, Size(1280, 720));
    lenSize = lenSize;
    // float pixelsToMicro = 0.174 * lenSize;
    // cvtColor(img, gray, COLOR_BGR2GRAY);

}

void func(){
    cout << "hello" << endl;
}


int main(){

    // Mat liveImg;
    // VideoCapture vid;
    // vid.open(0, CAP_ANY);
    // while (true){
    //     if (vid.isOpened()){
    //         vid.read(liveImg);
    //         Img test(liveImg, 5);
    //         imshow("gray", test.gray);
    //         waitKey(1);
    //     }
    // }
    // return 1;
    printf("hello\n");
    int x = 5;
    int *p = &x;
    printf("%p\n", p);
}