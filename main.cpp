#include "src/Visualisation.h"
#include "src/Game.h"
#include "opencv2/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "src/Player.h"

using namespace cv;
using namespace std;

int main(){

    VideoCapture cap(0);
    Mat img, flipped_img;
    ColorHsv color = ColorHsv();
    Visualisation visualisation = Visualisation(cap, img, color);
    Game game;
    Player *player = game.getPlayer();

    while (game.getWindow()->isOpen()) {

        visualisation.handleFrame();
        visualisation.getContours(player);
        visualisation.showImages();

        waitKey(1);

        game.updateWindow();
    }

    return 0;

}