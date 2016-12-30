#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Snake : public sf::Drawable {
private:
    float size;
    float x;
    float y;
    sf::Vector2f velocity;
    sf::RectangleShape head;

public:
    Snake(float blockSize);
    ~Snake();

    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float dx, float dy);
    void update();
    // Inherited via Drawable
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

