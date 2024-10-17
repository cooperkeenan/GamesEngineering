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
    std::vector<Ship*> ships;  // This will now store all invader ships
    sf::RenderWindow& window;
};
