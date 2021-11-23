//
// Created by nowak on 11/23/2021.
//

#ifndef TEST_BALL_HANDLER_H
#define TEST_BALL_HANDLER_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <windows.h>
#include "src/MyPoint.cpp"

using namespace cv;
using namespace std;

struct colorsHSV{
    int hmin = 94;
    int smin = 182;
    int vmin = 111;
    int hmax = 129;
    int smax = 255;
    int vmax = 243;
};

void trackbarWindow(struct colorsHSV& colors);  //trackbar do ustawienia kolorow
Mat setColor(Mat img, Mat mask);
Mat convertImage(Mat image); //zamiana obrazu tak, żeby wykrywał piłkę
void showMiddlePixel(MyPoint *p, int height, int width); // chyba raczej to do znalezienia srodka
void getContours(MyPoint* middlePoint, Mat imgDil); //tutaj jest wszystko

#endif //TEST_BALL_HANDLER_H
