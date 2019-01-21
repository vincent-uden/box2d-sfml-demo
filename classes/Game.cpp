#include "../headers/Game.h"

Game::Game():
    window(sf::VideoMode(windowWidth, windowHeight), "Box2D Test",
           sf::Style::Close | sf::Style::Titlebar, settings),
    box2dWorld(gravity) {
    window.setFramerateLimit(60);

    bgFill.setSize(sf::Vector2f(windowWidth, windowHeight));
    bgFill.setFillColor(sf::Color(51, 51, 51));
    bgFill.setPosition(sf::Vector2f(0, 0));

}

Game::~Game() {

}

void Game::run() {
    clock.restart();
    dt = 0;
    isRunning = true;

    addSprites();

    while (isRunning) {
        deltaTime = clock.restart();
        dt = deltaTime.asMilliseconds() / 1000.0f;

        update();
        draw();
    }

}

void Game::update() {
    // SFML Events
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Key::A:
                    // Do something
                    break;
                default:
                    break;
            }
        }
    }
    // END SFML Events
    //
    // Box2D EVENTS

    for (int i = 0; i < spriteGroup.size(); i++) {
        spriteGroup[i]->update(dt);
    }

    box2dWorld.Step(dt, 6, 2);
    // END Box2D EVENTS

    
}

void Game::draw() {
    window.draw(bgFill);

    for (int i = 0; i < spriteGroup.size(); i++) {
        spriteGroup[i]->draw(window);
    }
 
    window.display();
}

void Game::addSprites() {

    spriteGroup.push_back(std::move(std::unique_ptr<BoxSpriteDynamic>
        (new BoxSpriteDynamic(&box2dWorld, 1.0f, 1.0f, 
                              1.0f, 0.3f, -6.0f, 5.0f))));

    spriteGroup.push_back(std::move(std::unique_ptr<BoxSpriteStatic>
        (new BoxSpriteStatic(&box2dWorld, 20.0f, 0.05f, 
                             0.3f, 0.0f, -5.0f))));

    spriteGroup.push_back(std::move(std::unique_ptr<CircleSpriteDynamic>
        (new CircleSpriteDynamic(&box2dWorld, 1.0f, 1.0f, 
                                 0.3f, 0.0f, 5.0f))));

    for (int i = 0; i < 20; i++) {
        spriteGroup.push_back(std::move(std::unique_ptr<CircleSpriteDynamic>
            (new CircleSpriteDynamic(&box2dWorld, 0.2f, 1.0f, 
                                     0.3f, 0.0f, 10.0f - i / 5.0f))));
    }



}

