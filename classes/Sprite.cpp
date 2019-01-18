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

BoxSprite::BoxSprite(b2World* world, int width, int height): Sprite(world) {

    b2Width = width;
    b2Height = height;

    sfWidth = b2Width * 30 * 2;
    sfHeight = b2Height * 30 * 2;

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
    float sfX = b2Pos.x * 30 + windowWidth / 2;
    float sfY = b2Pos.y * -30 + windowHeight / 2; 
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

BoxSpriteDynamic::BoxSpriteDynamic(b2World* world, int width, int height, float dens): BoxSprite(world, width, height) {

    bodyDef.position.Set(0.0f, 0.0f);
    bodyDef.type = b2_dynamicBody;
    body = world->CreateBody(&bodyDef);
    shape.SetAsBox(b2Width, b2Height);
    fixtureDef.shape = &shape;
    fixtureDef.density = dens;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

BoxSpriteDynamic::BoxSpriteDynamic() {

}

BoxSpriteDynamic::~BoxSpriteDynamic() {

}

BoxSpriteStatic::BoxSpriteStatic(b2World* world, int width, int height): BoxSprite(world, width, height) {

    bodyDef.position.Set(2.1f, -5.2f);
    bodyDef.type = b2_staticBody;
    body = world->CreateBody(&bodyDef);
    shape.SetAsBox(b2Width, b2Height);
    fixtureDef.shape = &shape;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

BoxSpriteStatic::BoxSpriteStatic() {

}

BoxSpriteStatic::~BoxSpriteStatic() {

}


