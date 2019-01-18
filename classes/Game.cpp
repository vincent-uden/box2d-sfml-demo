#include "../headers/Game.h"

Game::Game():
    window(sf::VideoMode(windowWidth, windowHeight), "Box2D Test",
           sf::Style::Close | sf::Style::Titlebar),
    box2dWorld(gravity) {
    window.setFramerateLimit(60);

    bgFill.setSize(sf::Vector2f(windowWidth, windowHeight));
    bgFill.setFillColor(sf::Color(51, 51, 51));
    bgFill.setPosition(sf::Vector2f(0, 0));

    testBody = BoxSpriteDynamic(&box2dWorld, 1.0f, 1.0f, 1.0f);
    testBody2 = BoxSpriteStatic(&box2dWorld, 2.0f, 1.0f);
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

    //std::cout << testBody.getBody()->GetPosition().y << std::endl;
    testBody.update(dt);
    testBody2.update(dt);

    box2dWorld.Step(dt, 6, 2);

    // END Box2D EVENTS

    
}

void Game::draw() {
    window.draw(bgFill);

    testBody.draw(window);
    testBody2.draw(window);

    window.display();
}

