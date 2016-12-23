#include "Game.h"

const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 5.f);
const float Game::WINDOW_SIZE = 640.0;
const int Game::SCALE = 40;

Game::Game() :
    window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Snake"),
    direction(Direction::Right) {
    blockSize = floor(WINDOW_SIZE / SCALE);
    rect.setSize(sf::Vector2f(blockSize, blockSize));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Blue);
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
    sf::Vector2f movement(0.f, 0.f);

    switch (direction) {
    case Direction::Up:
        movement.y -= blockSize;
        break;
    case Direction::Down:
        movement.y += blockSize;
        break;
    case Direction::Left:
        movement.x -= blockSize;
        break;
    case Direction::Right:
        movement.x += blockSize;
        break;
    default: break;
    }

    rect.move(movement);
}

void Game::render() {
    window.clear();
    window.draw(rect);
    window.display();
}

Game::~Game() {}
