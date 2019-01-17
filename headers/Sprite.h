#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Box2D.h"


class Sprite {
public:
    Sprite(b2World* world);
    Sprite();
    ~Sprite();

    virtual void update(float dt);
    virtual void draw(sf::RenderWindow &window);
    
    b2Body* getBody();

protected:
    b2BodyDef bodyDef;
    b2Body* body;
    b2FixtureDef fixtureDef;

    b2World* world;
};

class BoxSprite: public Sprite {
public:
    BoxSprite(b2World* worldd);
    BoxSprite();
    ~BoxSprite();

    void update(float dt) override;
    void draw(sf::RenderWindow &window) override;

private:
    b2PolygonShape shape;
    
};
