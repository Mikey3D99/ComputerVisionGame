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

    findContours(this->result, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++){
        int area = contourArea(contours[i]);

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
            }
        }
    }
}


void Visualisation::showImages(){
    imshow("Video Camera", this->image);
    imshow("Mask", this->mask);
}
