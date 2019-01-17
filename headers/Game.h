#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Box2D.h"
#include "Sprite.h"

class BoxSprite;
class Sprite;

class Game {
public:
    Game();
    ~Game();

    void run();

    b2World* getWorld();

private:
    void update();
    void draw();


    static const int windowWidth = 1200;
    static const int windowHeight = 800;

    sf::RenderWindow window;
    sf::RectangleShape bgFill;
    sf::Clock clock;
    sf::Time deltaTime;
    sf::Event event;

    float dt;
    bool isRunning;

    b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
    b2World box2dWorld;

    BoxSprite testBody;
    



};


