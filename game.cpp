//
// Created by nowak on 11/23/2021.
//

#include "game.h"

void gameWindow(sf::RenderWindow* window, MyPoint* position){
    sf::Event evt;
    while(window->pollEvent(evt)){
        if(evt.type == sf::Event::Closed)
            window->close();
        if(evt.type == sf::Event::KeyPressed){
            if(evt.key.code == sf::Keyboard::Escape)
                window->close();
        }
    }
}
