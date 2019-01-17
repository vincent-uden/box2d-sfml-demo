#include "../headers/Sprite.h"

Sprite::Sprite(Game &game) {
    this->game = &game;
    this->world = game.getWorld();
}

Sprite::Sprite() {

}

Sprite::~Sprite() {

}

void Sprite::update(float dt) {

}

void Sprite::draw(sf::RenderWindow &window) {

}

BoxSprite::BoxSprite(Game &game): Sprite(game) {
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    body = world->CreateBody(&bodyDef);
    shape.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

}

BoxSprite::BoxSprite() {

}

BoxSprite::~BoxSprite() {

}

void BoxSprite::update(float dt) {

}

void BoxSprite::draw(sf::RenderWindow &window) {

}



