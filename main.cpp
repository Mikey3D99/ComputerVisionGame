#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <windows.h>

using namespace cv;
using namespace std;

struct point{
    int x;
    int y;
};

struct colorsHSV{
    int hmin = 129;
    int smin = 111;
    int vmin = 99;
    int hmax = 335;
    int smax = 196;
    int vmax = 194;
};

void trackbarWindow(struct colorsHSV& colors){
    //  pomidor - kolorki najęzorki
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

Mat convertImage(Mat image){
    Mat resultImage;
    //dla wideo
//    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    GaussianBlur(image, resultImage, Size(5, 5), 15, 15);
    Canny(resultImage, resultImage, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(resultImage, resultImage, kernel);
//    imshow("Dilated", res)
    return resultImage;
}

struct point findCenter(Rect const& rectangle){
    struct point p{};
    p.x = (rectangle.tl().x + rectangle.br().x) / 2;
    p.y = (rectangle.tl().y + rectangle.br().y) / 2;
    return p;
}

void showMiddlePixel(struct point p, int height, int width){
    Mat pixelImage(height, width, CV_8UC3, Scalar(255, 255, 255));


    if(p.y < height && p.x < width){
        for (int i = p.y - 25; i < p.y + 25; i++) {
            for (int j = p.x - 25; j < p.x + 25; j++) {
                pixelImage.at<Vec3b>(i, j)[0] = 0;
                pixelImage.at<Vec3b>(i, j)[1] = 0;
                pixelImage.at<Vec3b>(i, j)[2] = 0;
            }
        }

        imshow("found object", pixelImage);
    }
}

void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;


    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

//    for(int i = 0; i < contours.size(); i++){
//        cout << "New row: " << endl;
//        for(int j = 0; j < contours.at(i).size(); j++){
//            cout << contours.at(i).at(j) << ", ";
//        }
//    }

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++){
        int area = contourArea(contours[i]);
        //cout << "Area: " << area << endl;

        if (area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            cout << conPoly[i].size() << endl;
            boundRect[i] = boundingRect(conPoly[i]);

            int objCor = (int)conPoly[i].size();

            if (objCor > 4){
                cout << "Mamy kolko" << endl;
                struct point middlePoint = findCenter(boundRect[i]);
                cout << "X: " << middlePoint.x << " Y: " << middlePoint.y << endl;
                cout << boundRect[i].tl();
                rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 255), 5);
                showMiddlePixel(middlePoint, imgDil.size().height, imgDil.size().width);
            }

//            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

        }
    }
}

//int main() {
//
//    VideoCapture cap(0);
////    Mat img;
//    Mat imgHSV, mask;
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
//    getContours(resultImageDil, img);
//    imshow("Pomidor", img);
//
//    waitKey(0);
//
//    return 0;
//}


int main(){

    VideoCapture cap(0);
    Mat img;
    Mat imgHSV, mask;


    while(1){
        cap.read(img);
        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        //ustawienie koloru
    struct colorsHSV ballColor;

    Scalar lower(ballColor.hmin, ballColor.smin, ballColor.vmin);
    Scalar upper(ballColor.hmax, ballColor.smax, ballColor.vmax);
    inRange(imgHSV, lower, upper, mask);

    imshow("Mask", mask);


    Mat resultImageDil = convertImage(mask);
    imshow("Dilated", resultImageDil);
    getContours(resultImageDil, img);
    imshow("Pomidor", img);

    imshow("Image", img);

    waitKey(1);
    }

    return 0;

}