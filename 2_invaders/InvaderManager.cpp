#include "InvaderManager.h"
#include <SFML/Graphics.hpp>
#include "ship.h"
#include "game.h"
#include <iostream>

InvaderManager::InvaderManager(sf::RenderWindow& win) : window(win) {}

void InvaderManager::GenerateInvaders() {
    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);

    // Set total number of columns and rows
    const int totalColumns = 11; 
    const int totalRows = 5;      

    // Calculate margins and gaps
    float leftMargin = 30.0f;  
    float rightMargin = 30.0f; 
    float additionalSpacing = 20.0f; 
    float availableWidth = windowWidth - leftMargin - rightMargin;
    float xPosGap = availableWidth / (totalColumns - 1);  
    float yPosGap = 22.0f;    
    float yPosition = 35.0f;

    int vecArr[5] = {32, 64, 96, 128};

    // Generate invaders in an 11x5 grid
    for (int row = 0; row < totalRows; row++) {
        for (int col = 0; col < totalColumns; col++) {
            float xPos = leftMargin + col * xPosGap;
            Invader* inv = new Invader(sf::IntRect(sf::Vector2i(vecArr[row], 0), sf::Vector2i(32, 32)), { xPos, yPosition });
            inv->setScale(0.40f, 0.47f);  // Scale down the invader sprite
            ships.push_back(inv);
        }
        yPosition += yPosGap;
    }
}

void InvaderManager::Render() {
    for (auto ship : ships) {
        window.draw(*ship);
    }
}

void InvaderManager::Update(const float& dt) {
    for (auto ship : ships) {
        ship->Update(dt);
    }
}
