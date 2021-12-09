//
// Created by Marcin Świderek on 25/11/2021.
//

#ifndef TEST_OBSTACLE_H
#define TEST_OBSTACLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Player.h"

class Obstacle {
private:
    // every how many frames obstacle should go down
    int frameCounterCap;
    int frameCounter;
    int speed;

    sf::RectangleShape *shape;

public:
    // constructor
    explicit Obstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    // increases frame counter by 1 (it should run every frame)
    void increaseFrameCounter();

    // increases obstacle Y position by speed
    void goDown();

    // sets obstacle Y position to 0
    void resetYPosition();

    // returns whether obstacle is vertically under the screen
    // (y position > WINDOW_HEIGHT
    bool isUnderTheScreen();

    // returns whether player is colliding with this obstacle
    bool isCollidingWithPlayer(Player *player);

    // getters
    sf::RectangleShape* getShape();
};

#endif //TEST_OBSTACLE_H
