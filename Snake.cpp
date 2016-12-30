#include "Snake.h"

Snake::Snake(float blockSize) :
    blockSize(blockSize), 
    velocity(1.0, 0.0) {

    sf::RectangleShape head(sf::Vector2f(blockSize, blockSize));
    head.setPosition(sf::Vector2f(0, 0));
    head.setFillColor(sf::Color::White);

    body.push_back(head);
}

void Snake::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

void Snake::setVelocity(float dx, float dy) {
    velocity.x = dx;
    velocity.y = dy;
}

void Snake::update() {
    grow();
    body.pop_back();
}

// Grows the snake by adding a new rect to the front.
void Snake::grow() {
    sf::Vector2f prevHead(body.front().getPosition());
    sf::Vector2f updatedHead;
    updatedHead.x = prevHead.x + (velocity.x * blockSize);
    updatedHead.y = prevHead.y + (velocity.y * blockSize);

    sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
    rect.setPosition(updatedHead);
    rect.setFillColor(sf::Color::White);

    body.insert(body.begin(), rect);
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    for (const auto & rect : body) {
        target.draw(rect);
    }
}
