#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Snake : public sf::Drawable {
private:
    float blockSize;
    sf::Vector2f velocity;
    std::vector<sf::RectangleShape> body;

public:
    Snake(float blockSize);

    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float dx, float dy);
    void update();
    void grow();
    // Inherited via Drawable
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

