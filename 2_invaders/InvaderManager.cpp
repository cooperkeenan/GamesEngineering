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

    // Define invader parameters
    float invaderWidth = 32.0f;  // Width of each invader in pixels
    float invaderScaleX = 1.3f; // Scaling factor for the width
    float invaderScaleY = 1.3f; // Scaling factor for the width
    float horizontalGap = 15.0f; // Horizontal gap between invaders
    float verticalGap = 50.0f;   // Vertical gap between rows
    float yPosition = 70.0f;     // Starting y position for the rows

    // Calculate the total width of the invader formation
    float scaledInvaderWidth = invaderWidth * invaderScaleX;
    float totalFormationWidth = (totalColumns * scaledInvaderWidth) + (totalColumns - 1) * horizontalGap;

    // Calculate left margin to center the formation
    float leftMargin = (windowWidth - totalFormationWidth) / 2.0f;

    int vecArr[5] = {0, 32, 64, 96, 128};

    // Generate invaders in an 11x5 grid
    for (int row = 0; row < totalRows; row++) {
        for (int col = 0; col < totalColumns; col++) {
            float xPos = leftMargin + col * (scaledInvaderWidth + horizontalGap);
            Invader* inv = new Invader(sf::IntRect(sf::Vector2i(vecArr[row], 0), sf::Vector2i(32, 32)), { xPos, yPosition });
            inv->setScale(invaderScaleX, invaderScaleY);  // Uniform scaling for X and Y
            ships.push_back(inv);
        }
        yPosition += verticalGap;
    }
}


void InvaderManager::Render() {
    for (auto ship : ships) {
        window.draw(*ship);
    }
}

void InvaderManager::Update(const float& dt) {
    //calculate the movement distance based on delta time
    float movement = speed * dt * (moveRight ? 1.0f : -1.0f);

    bool reachedEdge = false;

    // Update invader positions and check for edge collisions
    for (auto ship : ships) {
        ship->move(movement, 0.0f);

        // Check if an invader has reached the screen edge
        if (moveRight && ship->getPosition().x > gameWidth - 32) {
            reachedEdge = true;
        }
        else if (!moveRight && ship->getPosition().x < 32) {
            reachedEdge = true;
        }
    }

    //Move down if edged is reached 
    if (reachedEdge) {
        MoveInvadersDown();
        moveRight = !moveRight; //reverse direction
    }
}

void InvaderManager::MoveInvadersDown() {
    for (auto ship : ships) {
        ship->move(0.0f, moveDownDistance);
    }
}
