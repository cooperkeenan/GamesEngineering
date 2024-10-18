// game.h
#pragma once
#include <SFML/Graphics.hpp>
#include "ship.h"
#include "InvaderManager.h"
#include "bullet.h" // Required for bullets

// Game dimensions
constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;

// Declare extern variables so they can be used across different files
extern sf::RenderWindow window;
extern sf::Texture spritesheet;
extern Player* player;
extern InvaderManager* invaderManager;
extern std::vector<Bullet*> bullets; // Global bullets vector

// Function declarations
void Load();
void Update(const float& dt);
void Render();
