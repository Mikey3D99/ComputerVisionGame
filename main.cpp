#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++){
        int area = contourArea(contours[i]);
        cout << "Area: " << area << endl;
        string objectType;

        if (area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            cout << conPoly[i].size() << endl;
            boundRect[i] = boundingRect(conPoly[i]);

            int objCor = (int)conPoly[i].size();

            if (objCor > 4){
                objectType = "Circle";
                cout << "Mamy kolko" << endl;
            }

//            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 255), 20);
        }
    }
}

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

    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    while(1){
        cap.read(img);
        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        //ustawienie koloru
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);
        imshow("Mask", mask);


        GaussianBlur(mask, imgBlur, Size(5, 5), 15, 15);

        imshow("Image", imgBlur);
        Canny(imgBlur, imgCanny, 25, 75);
        imshow("Image Canny", imgCanny);

        Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

        dilate(imgCanny, imgDil, kernel);
        imshow("Image dilate", imgDil);

        getContours(imgDil,img);

        imshow("Image", img);
//        imshow("Image HSV", imgHSV);

        waitKey(1);
    }

    return 0;

}