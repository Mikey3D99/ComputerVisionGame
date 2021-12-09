//
// Created by Marcin Świderek on 25/11/2021.
//

#include "enemy.h"


Enemy::Enemy(sf::Vector2f position, sf::Vector2f size, const sf::String& fileName, int speed) {

    this->textureDir = fileName;
    this->texture.loadFromFile(this->textureDir);
    this->myEnemy.setTexture(this->texture);
    this->myEnemy.setPosition(position);
    this->myEnemy.scale(0.33, 0.33);
    this->spriteHeight= this->myEnemy.getTextureRect().height / 3;
    this->spriteWidth= this->myEnemy.getTextureRect().width / 3;

    // TODO

    this->frameCounterCap = 1;
    this->frameCounter = 0;
    this->speed = speed;
}

void Enemy::changeSize(float scaleX, float scaleY){
    this->myEnemy.scale(scaleX, scaleY);
}

void Enemy::changeSpeed(int x){
    srand (time(nullptr));
    int segment1 = rand() % x;
    this->speed = segment1 + 10;
}

void Enemy::goDown() {
    sf::Vector2f currentPosition = this->myEnemy.getPosition();
    this->myEnemy.setPosition(currentPosition.x, currentPosition.y + (float)this->speed);
}

void Enemy::increaseFrameCounter() {
    if (this->frameCounter < this->frameCounterCap) {
        this->frameCounter += 1;
    } else {
        this->frameCounter = 0;
        this->goDown();
    }
}

bool Enemy::isUnderTheScreen() {
    if (this->myEnemy.getPosition().y > WINDOW_HEIGHT)
        return true;

    return false;
}

void Enemy::resetYPosition(float x) {
    this->myEnemy.setPosition(x, 0);
}


bool Enemy::isCollidingWithPlayer(Player *player) {

    sf::Vector2f obstaclePosition = this->myEnemy.getPosition();

    auto playerX = (float)player->getX();
    auto playerY = (float)player->getY();

    // simple collisions for 3 points

    if (
            ((playerX + 55 >= obstaclePosition.x && playerX + 55  <= obstaclePosition.x + this->spriteWidth) &&
            (playerY >= obstaclePosition.y && playerY  <= obstaclePosition.y + this->spriteHeight))
            ||
            ((playerX  >= obstaclePosition.x && playerX  <= obstaclePosition.x + this->spriteWidth) &&
            (playerY + 55 >= obstaclePosition.y && playerY+ 55  <= obstaclePosition.y + this->spriteHeight))
            ||
            ((playerX + 110 >= obstaclePosition.x && playerX + 110  <= obstaclePosition.x + this->spriteWidth) &&
            (playerY + 55 >= obstaclePosition.y && playerY + 55  <= obstaclePosition.y + this->spriteHeight))
            ) return true;

    return false;
}

