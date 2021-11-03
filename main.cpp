#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

int main(){

    VideoCapture cap(0);
    Mat img;
    Mat imgHSV, mask;

    int hmin = 94, smin = 182, vmin = 111;
    int hmax = 129, smax = 255, vmax = 243;

//    namedWindow("Trackbars", (640, 400));
//    createTrackbar("Hue Min", "Trackbars", &hmin, 359);
//    createTrackbar("Hue Max", "Trackbars", &hmax, 359);
//    createTrackbar("Sat Min", "Trackbars", &smin, 255);
//    createTrackbar("Sat Max", "Trackbars", &smax, 255);
//    createTrackbar("Val Min", "Trackbars", &vmin, 255);
//    createTrackbar("Val Max", "Trackbars", &vmax, 255);

    while(1){
        cap.read(img);
        cvtColor(img, imgHSV, COLOR_BGR2HSV);
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        inRange(imgHSV, lower, upper, mask);
        imshow("Image", img);
//        imshow("Image HSV", imgHSV);
        imshow("Mask", mask);
        waitKey(1);
    }

    return 0;

}