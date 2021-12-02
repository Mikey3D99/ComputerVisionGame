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

class Game {
private:
    sf::RenderWindow *window;
    Player *player;
    std::vector<Obstacle*> obstacles;

    // Draw player
    void drawBall();

    // Draw all of the obstacles
    void drawObstacles();

    bool hasPlayerCollidedWithObstacle();
public:
    // Constructor
    explicit Game();

    // Update game window, it should run every frame
    void updateWindow();

    // Add new obstacle to the game
    void addObstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    // Getters
    sf::RenderWindow* getWindow();
    Player* getPlayer();
};

#endif //TEST_GAME_H