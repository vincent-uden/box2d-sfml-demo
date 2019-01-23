#include "../headers/Game.h"

Game::Game():
    window(sf::VideoMode(windowWidth, windowHeight), "Box2D Test",
           sf::Style::Close | sf::Style::Titlebar, settings),
    box2dWorld(gravity) {
    window.setFramerateLimit(60);

    bgFill.setSize(sf::Vector2f(windowWidth, windowHeight));
    bgFill.setFillColor(sf::Color(51, 51, 51));
    bgFill.setPosition(sf::Vector2f(0, 0));

    spriteGroup.push_back(std::move(std::unique_ptr<BoxSpriteStatic>
        (new BoxSpriteStatic(&box2dWorld, 20.0f, 0.05f, 
                             0.3f, 0.0f, -5.0f))));

}

Game::~Game() {

}

void Game::run() {
    clock.restart();
    dt = 0;
    isRunning = true;


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
                    shoot();
                    break;

                case sf::Keyboard::Key::P:
                    addSprites();
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

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            spriteGroup.push_back(std::move(std::unique_ptr<BoxSpriteDynamic>
                (new BoxSpriteDynamic(&box2dWorld, 1.0f, 1.0f, 
                    1.0f, 2.0f, i * 2 - 7.0f, j * 2 - 4.05f))));
        } 
    }
}

void Game::shoot() {

    spriteGroup.push_back(std::move(std::unique_ptr<CircleSpriteDynamic>
        (new CircleSpriteDynamic(&box2dWorld, 1.0f, 
                              4.0f, 2.0f, -50.0f, 2.0f))));
    spriteGroup[spriteGroup.size()- 1]->
        getBody()->SetLinearVelocity(b2Vec2(100.0f, 0.0f));
}

