#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Box2D.h"
#include "Sprite.h"
#include "SpriteGroup.h"
#include "EventSystem.h"

class BoxSprite;
class BoxSpriteDynamic;
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
    void addSprites();
    void shoot();


    static const int windowWidth = 1920;
    static const int windowHeight = 1080;

    sf::ContextSettings settings = sf::ContextSettings(0, 0, 8); 

    sf::RenderWindow window;
    sf::RectangleShape bgFill;
    sf::Clock clock;
    sf::Time deltaTime;
    sf::Event event;
        
    float dt;
    bool isRunning;

    b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
    b2World box2dWorld;

    std::vector<std::unique_ptr<Sprite>> spriteGroup;
    SpriteGroup sprites;

};


