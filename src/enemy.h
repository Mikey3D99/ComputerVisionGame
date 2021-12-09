//
// Created by vm on 09.12.2021.
//

#ifndef TEST_ENEMY_H
#define TEST_ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Player.h"
#include "random"
#include <ctime>

class Enemy {
    private:
        // every how many frames obstacle should go down
        int frameCounterCap;
        int frameCounter;
        int speed;

    public:
        sf::Texture texture;
        sf::String textureDir;
        sf::Sprite myEnemy;
        int spriteWidth;
        int spriteHeight;
        // constructor
        explicit Enemy(sf::Vector2f position, sf::Vector2f size, const sf::String& fileName, int speed);

        //change sprite size
        void changeSize(float scaleX, float scaleY);

        void changeSpeed(int x);

        // increases frame counter by 1 (it should run every frame)
        void increaseFrameCounter();

        // increases obstacle Y position by speed
        void goDown();

        // sets obstacle Y position to 0
        void resetYPosition(float x);

        // returns whether obstacle is vertically under the screen
        // (y position > WINDOW_HEIGHT
        bool isUnderTheScreen();

        void randomizeSpeed(float x);

        // returns whether player is colliding with this obstacle
        bool isCollidingWithPlayer(Player *player);

};


#endif //TEST_ENEMY_H
