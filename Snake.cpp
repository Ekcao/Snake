#include "Snake.h"

Snake::Snake(float size) : size(size), x(0), y(0), velocity(1.0, 0.0) {
    head.setSize(sf::Vector2f(size, size));
    head.setPosition(sf::Vector2f(x, y));
    head.setFillColor(sf::Color::White);
}

Snake::~Snake() {}

void Snake::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

void Snake::setVelocity(float dx, float dy) {
    velocity.x = dx;
    velocity.y = dy;
}

void Snake::update() {
    sf::Vector2f offset;
    offset.x = velocity.x * size;
    offset.y = velocity.y * size;
    head.move(offset);
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const {    
    target.draw(head);
}
