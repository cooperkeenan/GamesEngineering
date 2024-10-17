#pragma once
#include <SFML/Graphics.hpp>
#include "ship.h"

// Game dimensions
constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_columns = 12;

// Declare extern variables
extern sf::Texture spritesheet;
extern Player* player;
extern sf::RenderWindow window;
