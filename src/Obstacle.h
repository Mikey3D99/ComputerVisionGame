#ifndef TEST_OBSTACLE_H
#define TEST_OBSTACLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Player.h"

class Obstacle {
private:
    int frameCounterCap;
    int frameCounter;
    int speed;

    sf::RectangleShape *shape;

public:
    explicit Obstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void increaseFrameCounter();
    void goDown();
    void resetYPosition();
    bool isUnderTheScreen();
    bool isCollidingWithPlayer(Player *player);
    sf::RectangleShape* getShape();
};

#endif
