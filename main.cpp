#include "ball_handler.h"
#include "game.h"

int main(){

    VideoCapture cap(0);
    Mat img, mask;
    MyPoint middlePoint;

    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML Test", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    while(window.isOpen()){
        cap.read(img);
        mask = setColor(img, mask);

        Mat resultImageDil = convertImage(mask);
        getContours(&middlePoint, resultImageDil);
        showMiddlePixel(&middlePoint, resultImageDil.size().height, resultImageDil.size().width);
        imshow("Dilated", resultImageDil);
        imshow("Image", img);

        waitKey(1);

        gameWindow(&window, &middlePoint);
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