#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    this->shape = new sf::RectangleShape(size);
    this->shape->setFillColor(color);
    this->shape->setPosition(position);

    // TODO
    this->frameCounterCap = 1;
    this->frameCounter = 0;
    this->speed = 10;
}

void Obstacle::goDown() {
    sf::Vector2f currentPosition = this->shape->getPosition();
    this->shape->setPosition(currentPosition.x, currentPosition.y + (float)this->speed);
}

void Obstacle::increaseFrameCounter() {
    if (this->frameCounter < this->frameCounterCap) {
        this->frameCounter += 1;
    } else {
        this->frameCounter = 0;
        this->goDown();
    }
}

sf::RectangleShape *Obstacle::getShape() {
    return this->shape;
}

bool Obstacle::isUnderTheScreen() {
    if (this->shape->getPosition().y > WINDOW_HEIGHT) return true;

    return false;
}

void Obstacle::resetYPosition() {
    this->shape->setPosition(this->shape->getPosition().x, 0);
}

bool Obstacle::isCollidingWithPlayer(Player *player) {
    sf::Vector2f obstaclePosition = this->shape->getPosition();
    sf::Vector2f obstacleDimensions = this->shape->getSize();
    float playerX = (float)player->getX();
    float playerY = (float)player->getY();

    if (
        (playerX >= obstaclePosition.x && playerX <= obstaclePosition.x + obstacleDimensions.x) &&
        (playerY >= obstaclePosition.y && playerY <= obstaclePosition.y + obstacleDimensions.y)
    ) return true;

    return false;
}

