//
// Created by Marcin Świderek on 24/11/2021.
//

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MyPoint.h"
#include "Obstacle.h"
#include "Player.h"
#include "Enemy.h"

class Game {
private:
    sf::RenderWindow *window;
    Player *player;
    std::vector<Enemy*> obstacles;
    bool isDead;

    sf::String fileDied;
    sf::Texture diedTexture;
    sf::Texture backgroundTexture;
    sf::Sprite died;
    sf::Sprite background;

    void drawBall();

    void drawObstacles();

    void reset();

    bool hasPlayerCollidedWithObstacle();

public:
    explicit Game();
    void updateWindow();
    void addObstacle(sf::Vector2f position, sf::Vector2f size,const sf::String& fileName, int speed);
    sf::RenderWindow* getWindow();
    Player* getPlayer();
};

#endif
