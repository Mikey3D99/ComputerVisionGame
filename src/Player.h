//
// Created by Marcin Świderek on 25/11/2021.
//

#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    // player position
    sf::Vector2<int> position;

    // player's ball radius
    int radius;

    // used in ball_handler.cpp
    // the higher it is, the slower player can move
    int moveSpeedDivider;
public:
    // constructor
    explicit Player(sf::Vector2<int> position, int radius);

    // get X and Y position as a Vector2<int>
    sf::Vector2<int> getPosition();

    // getters
    int getY() const;
    int getX() const;
    int getRadius();
    int getMoveSpeedDivider();

    // sets new position as new Vector2<int>
    void setPosition(sf::Vector2<int> newPosition);

    // setters
    void setY(int newY);
    void setX(int newX);
};

#endif //TEST_PLAYER_H
