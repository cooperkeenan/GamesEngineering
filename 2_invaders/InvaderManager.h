#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ship.h"

class InvaderManager {
public:
    InvaderManager(sf::RenderWindow& window);
    void GenerateInvaders();
    void Render();
    void Update(const float& dt);
   

private:
    std::vector<Ship*> ships;  // This will store all invader ships
    sf::RenderWindow& window;

    //Direction and speed variables 
    bool moveRight = true;
    float speed = 25.0f;
    float moveDownDistance = 13.0f;

    //Moves invaders down when they reach an edge
    void MoveInvadersDown(); 
};
