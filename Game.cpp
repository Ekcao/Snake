#include "Game.h"

const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 7.f);
const int Game::WINDOW_SIZE = 640;
const int Game::SCALE = 64;
float Game::blockSize = floor(Game::WINDOW_SIZE / Game::SCALE);

Game::Game() :
    window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Snake"),
    direction(Direction::Right),
    snake(blockSize) {
    snake.grow();
    snake.grow();
}

/* The main loop of the game. */
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        render();
    }
}

/* Process KeyPressed and Closed events. */
void Game::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            processInput(event.key.code);
            break;
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}

/* Handle keyboard presses. */
void Game::processInput(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Left:
        direction = Direction::Left;
        break;
    case sf::Keyboard::Right:
        direction = Direction::Right;
        break;
    case sf::Keyboard::Up:
        direction = Direction::Up;
        break;
    case sf::Keyboard::Down:
        direction = Direction::Down;
        break;
    default:
        break;
    }
}

void Game::update(sf::Time dt) {
    sf::Vector2f velocity(0.f, 0.f);

    switch (direction) {
    case Direction::Up:
        velocity.y = -1;
        break;
    case Direction::Down:
        velocity.y = 1;
        break;
    case Direction::Left:
        velocity.x = -1;
        break;
    case Direction::Right:
        velocity.x = 1;
        break;
    default: 
        break;
    }

    snake.setVelocity(velocity);
    snake.update();
}

void Game::render() {
    window.clear();
    window.draw(snake);
    window.display();
}

Game::~Game() {}
