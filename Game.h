#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    ~Game();
    void run();
private:
    static const sf::Time TIME_PER_FRAME;
    static const float WINDOW_SIZE;
    static const int SCALE;

    enum class Direction {
        Up, Down, Left, Right
    };

    sf::RenderWindow window;
    sf::RectangleShape rect;
    Direction direction;
    float blockSize;

    void processEvents();
    void processInput(sf::Keyboard::Key key);
    void update(sf::Time dt);
    void render();
};

