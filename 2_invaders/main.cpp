#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"

std::vector<Ship *> ships;
sf::Texture spritesheet;
sf::Sprite invader;
sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");



void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));

    Invader* inv = new Invader(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)), { 100, 100 });
    ships.push_back(inv);
}


void Render() {
    window.draw(invader);
}

int main() {
    Load();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        Render();  // Draw the invader sprite
        window.display();
    }

    return 0;
}
