//
// Created by nowak on 11/23/2021.
//

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball_handler.h"

void placeBall(sf::RenderWindow* window, MyPoint* position);
void gameWindow(sf::RenderWindow* window, MyPoint* position);
#endif //TEST_GAME_H
