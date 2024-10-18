#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "InvaderManager.h"
#include "game.h"

sf::RenderWindow window(sf::VideoMode({gameWidth, gameHeight}), "SFML works!");
sf::Texture spritesheet;
Player* player = nullptr;
InvaderManager* invaderManager = nullptr;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }

    // Create player
    player = new Player();

    // Initialize InvaderManager
    invaderManager = new InvaderManager(window);
    invaderManager->GenerateInvaders();
}

void Update(const float& dt) {
    if (player) {
        player->Update(dt);
    }
    if (invaderManager) {
        invaderManager->Update(dt);
    }
}

void Render() {
    window.clear();

    if (player) {
        window.draw(*player);
    }

    if (invaderManager) {
        invaderManager->Render();
    }

    window.display();
}

int main() {
    Load();

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Calculate delta time
        float dt = clock.restart().asSeconds();

        // Update game entities
        Update(dt);

        // Render everything
        Render();
    }

    // Clean up dynamic memory
    delete player;
    delete invaderManager;

    return 0;
}
