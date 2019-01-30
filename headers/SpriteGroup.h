#include <SFML/Graphics.hpp>
#include <iostream>

#include "Box2D.h"
#include "Sprite.h"

class SpriteGroup {
public:
    SpriteGroup();
    ~SpriteGroup();

    void update(float dt);
    void draw(sf::RenderWindow &window);
    void clear();
    void clear(int index);
    void setVelocity(int index, b2Vec2 vel);

    int  addSprite(std::unique_ptr<Sprite> sprite);

private: 
    std::vector<std::unique_ptr<Sprite>> sprites;
};
