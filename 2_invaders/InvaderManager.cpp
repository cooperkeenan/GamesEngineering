#include "InvaderManager.h"
#include <SFML/Graphics.hpp>
#include "ship.h"
#include <iostream>

InvaderManager::InvaderManager(sf::RenderWindow& win) : window(win) {}

void InvaderManager::GenerateInvaders() {
    // Get window size for placement reference
    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);

    // Set total number of columns and rows
    const int totalColumns = 11; 
    const int totalRows = 5;      

    // Calculate margins and gaps
    float leftMargin = 30.0f;  
    float rightMargin = 30.0f; 
    float availableWidth = windowWidth - leftMargin - rightMargin;
    float xPosGap = availableWidth / (totalColumns - 1);  
    float yPosGap = 20.0f;    
    float yPosition = 35.0f;  // Starting y position for the first row

    // Generate invaders in an 11x5 grid
    for (int row = 0; row < totalRows; row++) {
        for (int col = 0; col < totalColumns; col++) {
            float xPos = leftMargin + col * xPosGap;
            Invader* inv = new Invader(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)), { xPos, yPosition });
            inv->setScale(0.47f, 0.47f);  // Scale down the invader sprite
            ships.push_back(inv);
        }
        yPosition += yPosGap;  // Move to the next row
    }
}


void InvaderManager::Render(sf::RenderWindow& window) {
    for (auto ship : ships) {
        window.draw(*ship);
    }
}
