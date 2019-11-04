/**
 * Created by,
 *  - Ton3l & EpicJame
 *
 */

#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "App.h"

bool running = false;

int WinMain() {
	App().Start();

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    sf::Texture backTexture;
    if (!backTexture.loadFromFile("back.jpeg")) {
        std::cout << "Missing Background" << std::endl;
    }
    sf::Sprite backSprite;
    backSprite.setTexture(backTexture);

    // position
    backSprite.setPosition(sf::Vector2f(650.f, -250.f));  // absolute position

    // rotation
    backSprite.setRotation(45.f);  // absolute angle

    // scale
    backSprite.setScale(sf::Vector2f(2.f, 6.f));  // absolute scale factor

    sf::Texture barbaTexture;
    if (!barbaTexture.loadFromFile("barba.jpg")) {
        std::cout << "Missing character barba" << std::endl;
    }
    sf::Sprite barbaSprite;
    barbaSprite.setTexture(barbaTexture);

    // position
    barbaSprite.setPosition(sf::Vector2f(500.f, 500.f));  // absolute position

    sf::Music music;
    if (!music.openFromFile("music.ogg")) {
        std::cout << "Missing music" << std::endl;
    }
    music.play();

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("leap.ogg")) {
        std::cout << "Missing leap sound" << std::endl;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            // left key is pressed: move our character
            barbaSprite.move(-1.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            // left key is pressed: move our character
            barbaSprite.move(1.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            // left key is pressed: move our character
            barbaSprite.move(0.f, -1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            // left key is pressed: move our character
            barbaSprite.move(0.f, 1.f);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            // get the local mouse position (relative to a window)
            sf::Vector2f mousePositionFloat =
                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            barbaSprite.setPosition(mousePositionFloat.x,
                                    mousePositionFloat.y);  // absolute position
            sound.play();
        }

        window.clear();
        window.draw(backSprite);
        window.draw(barbaSprite);
        window.display();
    }

	music.stop();

    return 0;
}
