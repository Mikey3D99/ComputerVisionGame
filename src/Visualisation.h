#ifndef TEST_VISUALISATION_H
#define TEST_VISUALISATION_H
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Player.h"
#include "ColorHsv.h"
using namespace std;
using namespace cv;

class Visualisation {
private:
    VideoCapture cap;
    ColorHsv color;
    cv::Mat image;
    cv::Mat flipped_video;
    cv::Mat mask;
    cv::Mat result;

    void readAndFlip();
    void trackbarWindow();
    void setColor();
    void convertImage();

public:
    explicit Visualisation(const VideoCapture& cap, cv::Mat video, ColorHsv color);
    void handleFrame();
    void getContours(Player* middlePoint);
    void showImages();
};


#endif
