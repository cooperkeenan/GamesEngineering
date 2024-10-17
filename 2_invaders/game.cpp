#include "game.h"
#include "ship.h"
#include "InvaderManager.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow window(sf::VideoMode({gameWidth, gameHeight}), "SFML works!");
sf::Texture spritesheet;
Player* player = nullptr;
InvaderManager* invaderManager = nullptr;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }

    // Initialize Player
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
