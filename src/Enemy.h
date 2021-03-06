#ifndef TEST_ENEMY_H
#define TEST_ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Player.h"
#include "random"
#include <ctime>

class Enemy {
    private:
        int frameCounterCap;
        int frameCounter;
        int speed;

    public:
        sf::Texture texture;
        sf::String textureDir;
        sf::Sprite myEnemy;
        int spriteWidth;
        int spriteHeight;

        explicit Enemy(sf::Vector2f position, sf::Vector2f size, const sf::String& fileName, int speed);

        void changeSize(float scaleX, float scaleY);
        void changeSpeed(int x);
        void increaseFrameCounter();
        void goDown();
        void resetYPosition(float x);
        bool isUnderTheScreen();
        void randomizeSpeed(float x);
        bool isCollidingWithPlayer(Player *player);

};


#endif
