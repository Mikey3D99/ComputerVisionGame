//
// Created by nowak on 12/9/2021.
//

#include "Visualisation.h"

#include <utility>

Visualisation::Visualisation(const VideoCapture& cap, cv::Mat video, ColorHsv color){
    this->cap = cap;
    this->image = std::move(video);
    this->color = color;
    this->mask = Mat(480, 640, CV_32F);
    this->flipped_video = Mat(480, 640, CV_32F);
    this->result = Mat(480, 640, CV_32F);
}

void Visualisation::handleFrame(){
        this->readAndFlip();
        this->setColor();
        this->convertImage();
}

void Visualisation::readAndFlip(){
    cap.read(this->image);
    // flip image by Y axis
    cv::flip(this->image, this->flipped_video, 1);
}

//void Visualisation::trackbarWindow(){
//    //  pomidor
////    int hmin = 129, smin = 111, vmin = 99;
////    int hmax = 335, smax = 196, vmax = 194;
//
//
//    //  niebieska pilka
////    int hmin = 94, smin = 182, vmin = 111;
////    int hmax = 129, smax = 255, vmax = 243;
//
//    namedWindow("Trackbars", (640, 400));
//    createTrackbar("Hue Min", "Trackbars", color.hmin, 359);
//    createTrackbar("Hue Max", "Trackbars", color.hmax, 359);
//    createTrackbar("Sat Min", "Trackbars", color.smin, 255);
//    createTrackbar("Sat Max", "Trackbars", color.smax, 255);
//    createTrackbar("Val Min", "Trackbars", color.vmin, 255);
//    createTrackbar("Val Max", "Trackbars", color.vmax, 255);
//}

void Visualisation::setColor(){
    Mat imgHsv;
    cvtColor(this->flipped_video, imgHsv, COLOR_BGR2HSV);

    Scalar lower(this->color.getHmin(), this->color.getSmin(), this->color.getVmin());
    Scalar upper(this->color.getHmax(), this->color.getSmax(), this->color.getVmax());

    inRange(imgHsv, lower, upper, this->mask);
}

void Visualisation::convertImage(){
    GaussianBlur(this->mask, this->result, Size(5, 5), 15, 15);
    Canny(this->result, this->result, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(this->result, this->result, kernel);
}

void Visualisation::getContours(Player* player){

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    //finding areas
    findContours(this->result, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    //creating vector of polys of founs areas
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++){
        int area = contourArea(contours[i]);

        //if poly is large enough
        if (area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            boundRect[i] = boundingRect(conPoly[i]);

            int objCor = (int)conPoly[i].size();

            if (objCor > 4){

                int divider = player->getMoveSpeedDivider();

                player->setPosition(
                        sf::Vector2<int>(
                        (boundRect[i].tl().x + boundRect[i].br().x / divider),
                        (boundRect[i].tl().y + boundRect[i].br().y / divider)
                    )
                );

                //draw rectangle and contours over color
                //rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 255), 5);
                //drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
            }
        }
    }
}


void Visualisation::showImages(){
    imshow("Video Camera", this->image);
    imshow("Mask", this->mask);
}
