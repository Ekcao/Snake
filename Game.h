#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Game {
private:
    static const sf::Time TIME_PER_FRAME;
    static const int WINDOW_SIZE;
    static const int SCALE;

    enum class Direction {
        Up, Down, Left, Right
    };

    sf::RenderWindow window;
    Direction direction;
    Snake snake;
    
    void processEvents();
    void processInput(sf::Keyboard::Key key);
    void update(sf::Time dt);
    void render();

public:
    static float blockSize;

    Game();
    ~Game();
    void run();
};

