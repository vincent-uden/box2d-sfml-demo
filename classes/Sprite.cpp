#include "../headers/Sprite.h"

Sprite::Sprite(b2World* world) {
    this->world = world;
}

Sprite::Sprite() {

}

Sprite::~Sprite() {

}

void Sprite::update(float dt) {

}

void Sprite::draw(sf::RenderWindow &window) {

}

b2Body* Sprite::getBody() {
    return body;
}

BoxSprite::BoxSprite(b2World* world, float width, float height): Sprite(world) {

    b2Width = width;
    b2Height = height;

    sfWidth = b2Width * worldScale * 2 + 0.5f;
    sfHeight = b2Height * worldScale * 2 + 0.5f;

    sfShape = sf::RectangleShape(
              sf::Vector2f(sfWidth, sfHeight));
    sfShape.setFillColor(sf::Color::Green);
    sfShape.setOrigin(sfWidth / 2, sfHeight / 2);
}

BoxSprite::BoxSprite() {

}

BoxSprite::~BoxSprite() {

}

void BoxSprite::update(float dt) {

    sf::Vector2f b2Pos = sf::Vector2f(body->GetPosition().x, 
                                      body->GetPosition().y);
    float sfX = b2Pos.x * worldScale + windowWidth / 2;
    float sfY = b2Pos.y * -worldScale + windowHeight / 2; 
    sfShape.setPosition(sf::Vector2f(sfX, sfY));

    float angle = body->GetAngle() * 180 / M_PI;
    while (angle <= 0){
        angle += 360;
    }
    while (angle > 360){
        angle -= 360;
    }

    sfShape.setRotation(-angle);
}

void BoxSprite::draw(sf::RenderWindow &window) {
    window.draw(sfShape);
}

BoxSpriteDynamic::BoxSpriteDynamic(b2World* world, float width, float height, float dens, float fric, float x, float y): BoxSprite(world, width, height) {

    bodyDef.position.Set(x, y);
    bodyDef.type = b2_dynamicBody;
    body = world->CreateBody(&bodyDef);
    shape.SetAsBox(b2Width, b2Height);
    fixtureDef.shape = &shape;
    fixtureDef.density = dens;
    fixtureDef.friction = fric;
    body->CreateFixture(&fixtureDef);
}

BoxSpriteDynamic::BoxSpriteDynamic() {

}

BoxSpriteDynamic::~BoxSpriteDynamic() {

}

BoxSpriteStatic::BoxSpriteStatic(b2World* world, float width, float height, float fric, float x, float y): BoxSprite(world, width, height) {

    bodyDef.position.Set(x, y);
    bodyDef.type = b2_staticBody;
    body = world->CreateBody(&bodyDef);
    shape.SetAsBox(b2Width, b2Height);
    fixtureDef.shape = &shape;
    fixtureDef.friction = fric;
    body->CreateFixture(&fixtureDef);


}

BoxSpriteStatic::BoxSpriteStatic() {

}

BoxSpriteStatic::~BoxSpriteStatic() {

}

CircleSprite::CircleSprite(b2World* world, float rad): Sprite(world) {
    b2Rad = rad;

    sfRad = b2Rad * worldScale;

    sfShape = sf::CircleShape(sfRad); 
    sfShape.setFillColor(sf::Color::Blue);
    sfShape.setOrigin(sfRad, sfRad);
}

CircleSprite::CircleSprite() {

}

CircleSprite::~CircleSprite() {
    
}

void CircleSprite::update(float dt) {
    sf::Vector2f b2Pos = sf::Vector2f(body->GetPosition().x,
                                      body->GetPosition().y);
    float sfX = b2Pos.x * worldScale + windowWidth / 2;
    float sfY = b2Pos.y * -worldScale + windowHeight / 2;
    sfShape.setPosition(sf::Vector2f(sfX, sfY));
 
    float angle = body->GetAngle() * 180 / M_PI;
    while (angle <= 0){
        angle += 360;
    }
    while (angle > 360){
        angle -= 360;
    }

    sfShape.setRotation(-angle);
}

void CircleSprite::draw(sf::RenderWindow &window) {
    window.draw(sfShape);
}

CircleSpriteDynamic::CircleSpriteDynamic(b2World* world, float rad, float dens, float fric, float x, float y):
CircleSprite(world, rad){

    bodyDef.position.Set(x, y);
    bodyDef.type = b2_dynamicBody;
    body = world->CreateBody(&bodyDef);
    shape.m_radius = rad;
    fixtureDef.shape = &shape;
    fixtureDef.density = dens;
    fixtureDef.friction = fric;
    body->CreateFixture(&fixtureDef);
}


CircleSpriteDynamic::CircleSpriteDynamic() {

}

CircleSpriteDynamic::~CircleSpriteDynamic() {

}



CircleSpriteStatic::CircleSpriteStatic(b2World* world, float rad, float fric, float x, float y): 
CircleSprite(world, rad) {
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_staticBody;
    body = world->CreateBody(&bodyDef);
    shape.m_radius = rad;
    fixtureDef.shape = &shape;
    fixtureDef.friction = fric;
    body->CreateFixture(&fixtureDef);
}

CircleSpriteStatic::CircleSpriteStatic() {

}

CircleSpriteStatic::~CircleSpriteStatic() {

}


