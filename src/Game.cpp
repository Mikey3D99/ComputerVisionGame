// Main Game class

#include "Game.h"
#include "constants.h"

Game::Game() {
    // Init game window
    this->window = new sf::RenderWindow(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            "SFML Test",
            sf::Style::Close | sf::Style::Titlebar
    );
    this->window->setFramerateLimit(FRAMERATE);

    // Init player
    this->player = new Player(sf::Vector2<int>(0, 0), 20);

    // Init obstacles
    this->addObstacle(
            sf::Vector2f(20, 20),
            sf::Vector2f(200, 50),
            sf::Color::Red
    );

//    this->addObstacle(
//            sf::Vector2f(320, 20),
//            sf::Vector2f(200, 50),
//            sf::Color::Red
//    );
//
//    this->addObstacle(
//            sf::Vector2f(620, 20),
//            sf::Vector2f(200, 50),
//            sf::Color::Red
//    );
}

void Game::drawBall() {
    sf::CircleShape ball;
    ball.setRadius((float)this->player->getRadius());
    ball.setFillColor(sf::Color::Red);
    ball.setPosition((float)this->player->getX(), (float)this->player->getY());
    this->getWindow()->draw(ball);
}

void Game::updateWindow() {
    sf::Event event{};
    while (window->pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Escape)
                window->close();
        }
    }

    window->setActive(true);
    window->clear();

    this->drawObstacles();
    this->drawBall();

    if (this->hasPlayerCollidedWithObstacle()) {
        std::cout << "Player collided with obstacle!" << std::endl;
    }

    window->display();
}

sf::RenderWindow* Game::getWindow() {
    return this->window;
}

void Game::addObstacle(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    this->obstacles.push_back(new Obstacle(position, size, color));
}

void Game::drawObstacles() {
    for (auto obstacle : this->obstacles) {
        obstacle->increaseFrameCounter();

        if (obstacle->isUnderTheScreen()) {
            obstacle->resetYPosition();
        }

        this->window->draw(*obstacle->getShape());
    }
}

Player *Game::getPlayer() {
    return this->player;
}

bool Game::hasPlayerCollidedWithObstacle() {
    for (auto obstacle : this->obstacles) {
        if (obstacle->isCollidingWithPlayer(this->player)) {
            return true;
        }
    }

    return false;
}
