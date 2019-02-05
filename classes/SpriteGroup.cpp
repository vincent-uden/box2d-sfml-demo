#include "../headers/SpriteGroup.h"


SpriteGroup::SpriteGroup() {

}

SpriteGroup::~SpriteGroup() {

}

void SpriteGroup::clear() {

}

void SpriteGroup::clear(int index) {

}

void SpriteGroup::setWorld(b2World *world) {
    this->world = world;
}

void SpriteGroup::setVelocity(int index, b2Vec2 vel) {
    sprites[index]->getBody()->SetLinearVelocity(vel);
}

void SpriteGroup::update(float dt) {
    for (auto itr = sprites.begin(); itr != sprites.end(); ++itr) {
        (*itr)->update(dt);
    }
}

void SpriteGroup::draw(sf::RenderWindow &window) {
    for (auto itr = sprites.begin(); itr != sprites.end(); ++itr) {
        (*itr)->draw(window);
    }
}

int SpriteGroup::addSprite(std::unique_ptr<Sprite> sprite) {
    sprites.push_back(std::move(sprite));
    return sprites.size() - 1;
}

void SpriteGroup::createRevoluteJoint
(int index1, int index2, b2Vec2 pos) {

    b2RevoluteJointDef jointDef;
    jointDef.bodyA = sprites[index1]->getBody();
    jointDef.bodyB = sprites[index2]->getBody();
    jointDef.collideConnected = false;
    jointDef.localAnchorA.Set(0.0f, 0.0f);
    jointDef.localAnchorB.Set(0.0f, 0.0f);


    world->CreateJoint(&jointDef);




}




