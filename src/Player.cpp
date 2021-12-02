//
// Created by Marcin Świderek on 25/11/2021.
//

#include "Player.h"

Player::Player(sf::Vector2<int> position, int radius) {
    this->position = position;
    this->radius = radius;
    this->moveSpeedDivider = 2;
}

sf::Vector2<int> Player::getPosition() {
    return this->position;
}

int Player::getY() const {
    return this->position.y;
}

int Player::getX() const {
    return this->position.x;
}

int Player::getRadius() {
    return this->radius;
}

void Player::setPosition(sf::Vector2<int> newPosition) {
    this->position = newPosition;
}

void Player::setY(int newY) {
    this->position.y = newY;
}

void Player::setX(int newX) {
    this->position.x = newX;
}

int Player::getMoveSpeedDivider() {
    return this->moveSpeedDivider;
}
