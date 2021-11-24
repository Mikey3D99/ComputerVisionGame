//
// Created by nowak on 11/23/2021.
//

#include "game.h"

void placeBall(sf::RenderWindow* window, MyPoint* position){
    sf::RectangleShape ball;
    sf::Vector2f sizeBall(20, 20);

    ball.setPosition(position->getX(), position->getY());
    ball.setSize(sizeBall);
    ball.setFillColor(sf::Color::Red);
    window->draw(ball);
}

void gameWindow(sf::RenderWindow* window, MyPoint* position){
//    sf::Event evt;

    window->setActive(true);
    window->clear();
    placeBall(window, position);
    window->display();

//    while(window->pollEvent(evt)){
//        if(evt.type == sf::Event::Closed)
//            window->close();
//        if(evt.type == sf::Event::KeyPressed){
//            if(evt.key.code == sf::Keyboard::Escape)
//                window->close();
//        }
//
//        window->setActive(true);
//        window->clear();
//
//        placeBall(window, position);
//
//        window->display();
//    }
}
