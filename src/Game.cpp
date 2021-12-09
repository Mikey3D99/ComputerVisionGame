// Main Game class

#include "Game.h"
#include "constants.h"
#include "enemy.h"
#include "random"
#include <ctime>

Game::Game() {


    // set textures
    this->backgroundTexture.loadFromFile("/home/vm/CLionProjects/Aplikacja/src/assets/nebula.jpg");
    this->background.setTexture(this->backgroundTexture);

    this->fileDied = "/home/vm/CLionProjects/Aplikacja/src/assets/dead4.png";
    this->diedTexture.loadFromFile(fileDied);
    this->died.setTexture(this->diedTexture);
    this->isDead = false;


    // Init game window
    this->window = new sf::RenderWindow(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            "SFML Test",
            sf::Style::Close | sf::Style::Titlebar
    );
    this->window->setFramerateLimit(FRAMERATE);

    // Init player
    this->player = new Player(sf::Vector2<int>(WINDOW_WIDTH - 550, WINDOW_HEIGHT - 150), 20);

    // Init obstacles
    srand (time(nullptr));
    int segment1 = rand() % (WINDOW_WIDTH);
    sf::String file = "/home/vm/CLionProjects/Aplikacja/src/assets/laser.png";

    for(int i = 0; i < 4; i++){
        this->addObstacle(
                sf::Vector2f(segment1, 0),
                sf::Vector2f(100, 10),
                file,
                10 + i
        );
    }
}

void Game::drawBall() {

    sf::String fileSource = "/home/vm/CLionProjects/Aplikacja/src/assets/ufo1.png";
    sf::Texture texture;
    texture.loadFromFile(fileSource);
    sf::Sprite ball(texture);

    float ballScale = 0.33;
    ball.scale(ballScale, ballScale);

    //sf::CircleShape ball1;
    //ball.setRadius((float)this->player->getRadius());
    //ball.setFillColor(sf::Color::Red);
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
        if(this->isDead ){
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::R){
                    reset();
                }
            }
        }
    }

    if (this->hasPlayerCollidedWithObstacle() && !this->isDead) {
        std::cout << "Player collided with obstacle!" << std::endl;
        this->isDead = true;
        window->clear();
        window->draw(this->died);
    }
    else if(!this->isDead){
        window->setActive(true);
        window->clear();
        window->draw(this->background);
        this->drawObstacles();
        this->drawBall();
    }

    window->display();
}

sf::RenderWindow* Game::getWindow() {
    return this->window;
}

void Game::addObstacle(sf::Vector2f position, sf::Vector2f size,const sf::String& fileName, int speed) {
    this->obstacles.push_back(new Enemy(position, size, fileName, speed));
}

void Game::drawObstacles() {
    srand (time(nullptr));
    for (auto obstacle : this->obstacles) {
        obstacle->increaseFrameCounter();

        int randomizeBy = WINDOW_WIDTH / 3;
        int i = 0;

        if (obstacle->isUnderTheScreen()) {

            obstacle->resetYPosition(rand() % (randomizeBy + randomizeBy * i));
            obstacle->changeSpeed(5 + i * 5);
        }

        this->window->draw(obstacle->myEnemy);
    }
}

void Game::reset(){

    this->isDead = false;
    for (auto obstacle : this->obstacles) {
        obstacle->resetYPosition(rand() % WINDOW_WIDTH - 100);
    }
    this->player->setPosition(sf::Vector2<int>(WINDOW_WIDTH - 550, WINDOW_HEIGHT - 150));
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
