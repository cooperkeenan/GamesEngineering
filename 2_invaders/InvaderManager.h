#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ship.h"

class InvaderManager {
public:
    InvaderManager(sf::RenderWindow& window);
    void GenerateInvaders();
    void Render(sf::RenderWindow& window);

private:
    std::vector<Ship*> ships;
    sf::RenderWindow& window;
};
