// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgproc.hpp>
// #include <iostream>
// #include <stdio.h>
// using namespace cv;
// using namespace std;

// int main(){
// 	string path = "/home/sagi/Downloads/videoplayback.mp4";
// 	VideoCapture cap(path); //another vid /same/path/dcmp.mp4
// 	Mat img;
// 	// cout << getBuildInformation();
//     long x = 0;
// 	while (true){	
// 		// printf("%s\n", path);
// 		if (!cap.isOpened()){
// 			return 1;
// 		}
// 		cap.read(img);

// 		if (img.empty()){
// 			return 1;
// 		}
//         resize(img, img, Size(1280, 680));

// 		// cout << rgb[0];
// 		imshow("video", img);
// 		waitKey(1);
		
// 	}
// 	return 0;
// }