#include "../headers/SpriteGroup.h"

SpriteGroup::SpriteGroup() {

}

SpriteGroup::~SpriteGroup() {

}

void SpriteGroup::clear() {

}

void SpriteGroup::clear(int index) {

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




