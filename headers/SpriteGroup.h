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
    void createRevoluteJoint(int index1, int index2, b2Vec2 pos);
    void setWorld(b2World* world);

    int  addSprite(std::unique_ptr<Sprite> sprite);

    std::vector<std::unique_ptr<Sprite>> sprites;
private:
    b2World* world;
};
