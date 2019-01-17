#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Box2D.h"
#include "./Game.h"

class Game;


class Sprite {
public:
    Sprite(Game &game);
    Sprite();
    ~Sprite();

    virtual void update(float dt);
    virtual void draw(sf::RenderWindow &window);

protected:
    b2BodyDef bodyDef;
    b2Body* body;
    b2FixtureDef fixtureDef;

    Game* game;
    b2World* world;
};

class BoxSprite: public Sprite {
public:
    BoxSprite(Game &game);
    BoxSprite();
    ~BoxSprite();

    void update(float dt) override;
    void draw(sf::RenderWindow &window) override;

private:
    b2PolygonShape shape;
    
};
