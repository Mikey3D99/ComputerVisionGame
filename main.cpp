#include "ball_handler.h"
#include "src/Game.h"
#include "opencv2/core.hpp"

int main(){
    VideoCapture cap(0);
    Mat img, flipped_img, mask;

    Game game;
    Player *player = game.getPlayer();

    // Main program loop
    while (game.getWindow()->isOpen()) {
        cap.read(img);

        // flip image by Y axis
        cv::flip(img, flipped_img, 1);

        mask = setColor(flipped_img, mask);

        Mat resultImageDil = convertImage(mask);
        getContours(player, resultImageDil);

//        to nizej wywala błąd, dzieją się rzeczy niestworzone
//        showMiddlePixel(&middlePoint, resultImageDil.size().height, resultImageDil.size().width);

        imshow("Dilated", resultImageDil);
        imshow("Image", flipped_img);

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