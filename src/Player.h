#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Vector2<int> position;
    int radius;
    int moveSpeedDivider;
public:
    explicit Player(sf::Vector2<int> position, int radius);
    sf::Vector2<int> getPosition();
    int getY() const;
    int getX() const;
    int getRadius();
    int getMoveSpeedDivider();
    void setPosition(sf::Vector2<int> newPosition);
    void setY(int newY);
    void setX(int newX);
};

#endif //TEST_PLAYER_H
