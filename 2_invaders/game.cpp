// game.cpp
#include "game.h"
#include "bullet.h"
#include "InvaderManager.h"
#include <iostream>

// Define global variables here
sf::RenderWindow window(sf::VideoMode({gameWidth, gameHeight}), "SFML works!");
sf::Texture spritesheet;
Player* player = nullptr;
InvaderManager* invaderManager = nullptr;
std::vector<Bullet*> bullets;

// Function definitions
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

    // Draw player
    if (player) {
        window.draw(*player);
    }

    // Draw invaders
    if (invaderManager) {
        invaderManager->Render();
    }

    // Draw bullets (use the global `bullets` vector)
    for (auto& bullet : bullets) {
        window.draw(*bullet);
    }

    window.display();
}

