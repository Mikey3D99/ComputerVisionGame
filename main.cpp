#include "src/Visualisation.h"
#include "src/Game.h"
#include "opencv2/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "src/Player.h"
#include "ball_handler.h"

using namespace cv;
using namespace std;

int main(){

    VideoCapture cap(0);
    Mat img, flipped_img;
//    Mat img, flipped_img, mask;
    ColorHsv color = ColorHsv();
    Visualisation visualisation = Visualisation(cap, img, color);
    Game game;
    Player *player = game.getPlayer();

    // Main program loop
    while (game.getWindow()->isOpen()) {

        visualisation.handleFrame();
        visualisation.getContours(player);
        visualisation.showImages();

        waitKey(1);

        game.updateWindow();
    }

    return 0;

}

//int main() {
//
//    VideoCapture cap(0);
//    Mat imgHSV, mask;
//    MyPoint *middlePoint = new MyPoint();
//
//
//    Mat img = imread("C:/Studia/Semestr V/Projekt_kompetencyjny/pomidor.jpg");
//    cvtColor(img, imgHSV, COLOR_BGR2HSV);
//
//    struct colorsHSV ballColor;
//
//    Scalar lower(ballColor.hmin, ballColor.smin, ballColor.vmin);
//    Scalar upper(ballColor.hmax, ballColor.smax, ballColor.vmax);
//    inRange(imgHSV, lower, upper, mask);
//
//
//    Mat resultImageDil = convertImage(mask);
//    imshow("Dilated", resultImageDil);
//    getContours(middlePoint, resultImageDil);
//    showMiddlePixel(middlePoint, resultImageDil.size().height, resultImageDil.size().width);
//    imshow("Pomidor", img);
//
//    waitKey(0);
//
//    return 0;
//}

//        cap.read(img);
//
//        // flip image by Y axis
//        cv::flip(img, flipped_img, 1);
//
//        mask = setColor(flipped_img, mask);
//
//        Mat resultImageDil = convertImage(mask);
//        getContours(player, resultImageDil);