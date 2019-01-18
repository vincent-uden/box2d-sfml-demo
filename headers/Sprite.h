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

    static const int windowWidth = 1200;
    static const int windowHeight = 800;
};

class BoxSprite: public Sprite {
public:
    BoxSprite(b2World* world, int width, int height);
    BoxSprite();
    ~BoxSprite();

    void update(float dt) override;
    void draw(sf::RenderWindow &window) override;

protected:
    b2PolygonShape shape;
    sf::RectangleShape sfShape;

    float sfWidth;
    float sfHeight;

    float b2Width;
    float b2Height;
};

class BoxSpriteDynamic: public BoxSprite {
public:
    BoxSpriteDynamic(b2World* world, float width, float height, float dens, float fric, float x, float y);
    BoxSpriteDynamic();
    ~BoxSpriteDynamic();
private:
    float density;
};

class BoxSpriteStatic: public BoxSprite {
public:
    BoxSpriteStatic(b2World* world, float width, float height, float fric, float x, float y);
    BoxSpriteStatic();
    ~BoxSpriteStatic();
};

class CircleSprite: public Sprite {
public:
    CircleSprite(b2World* world, float rad);
    CircleSprite();
    ~CircleSprite();
    
    void update(float dt) override;
    void draw(sf::RenderWindow &window);

protected:
    b2CircleShape shape;
    sf::CircleShape sfShape;

    float sfRad;
    float b2Rad;
};

class CircleSpriteDynamic: public CircleSprite {
public:
    CircleSpriteDynamic(b2World* world, float rad, float dens, float fric, float x, float y);
    CircleSpriteDynamic();
    ~CircleSpriteDynamic();
};


class CircleSpriteStatic: public CircleSprite {
public:
    CircleSpriteStatic(b2World* world, float rad, float fric, float x, float y);
    CircleSpriteStatic();
    ~CircleSpriteStatic();
};
