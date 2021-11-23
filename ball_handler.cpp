//
// Created by nowak on 11/23/2021.
//

#include "ball_handler.h"

void trackbarWindow(struct colorsHSV& colors){
    //  pomidor
//    int hmin = 129, smin = 111, vmin = 99;
//    int hmax = 335, smax = 196, vmax = 194;


    //  niebieska pilka
//    int hmin = 94, smin = 182, vmin = 111;
//    int hmax = 129, smax = 255, vmax = 243;

    namedWindow("Trackbars", (640, 400));
    createTrackbar("Hue Min", "Trackbars", &colors.hmin, 359);
    createTrackbar("Hue Max", "Trackbars", &colors.hmax, 359);
    createTrackbar("Sat Min", "Trackbars", &colors.smin, 255);
    createTrackbar("Sat Max", "Trackbars", &colors.smax, 255);
    createTrackbar("Val Min", "Trackbars", &colors.vmin, 255);
    createTrackbar("Val Max", "Trackbars", &colors.vmax, 255);
}

Mat setColor(Mat img, Mat mask){
    Mat imgHSV;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    struct colorsHSV ballColor;
    Scalar lower(ballColor.hmin, ballColor.smin, ballColor.vmin);
    Scalar upper(ballColor.hmax, ballColor.smax, ballColor.vmax);
    inRange(imgHSV, lower, upper, mask);
    return mask;
}

Mat convertImage(Mat image){
    Mat resultImage;
    GaussianBlur(image, resultImage, Size(5, 5), 15, 15);
    Canny(resultImage, resultImage, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(resultImage, resultImage, kernel);
    return resultImage;
}

void showMiddlePixel(MyPoint *p, int height, int width){
    Mat pixelImage(height, width, CV_8UC3, Scalar(255, 255, 255));


    if(p->getY() < height && p->getX() < width){
        for (int i = p->getY() - 25; i < p->getY() + 25; i++) {
            for (int j = p->getX() - 25; j < p->getX() + 25; j++) {
                pixelImage.at<Vec3b>(i, j)[0] = 0;
                pixelImage.at<Vec3b>(i, j)[1] = 0;
                pixelImage.at<Vec3b>(i, j)[2] = 0;
            }
        }

        imshow("Watch dat shit", pixelImage);
    }
}

void getContours(MyPoint* middlePoint, Mat imgDil){

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;


    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++){
        int area = contourArea(contours[i]);

        if (area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            cout << conPoly[i].size() << endl;
            boundRect[i] = boundingRect(conPoly[i]);

            int objCor = (int)conPoly[i].size();

            if (objCor > 4){
                cout << "Mamy kolko" << endl;
                middlePoint->set((boundRect[i].tl().x + boundRect[i].br().x) / 2, (boundRect[i].tl().y + boundRect[i].br().y) / 2);

                //draw rectangle and contours over color
                //rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 255), 5);
                //drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);


            }


        }
    }
}