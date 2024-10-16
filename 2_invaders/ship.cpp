#include "ship.h"
using namespace sf;

extern sf::Texture spritesheet;

// Base Ship Constructor
Ship::Ship() {}

Ship::Ship(IntRect ir) : Sprite() {
    _sprite = ir;
    setTexture(spritesheet);
    setTextureRect(_sprite);
}

void Ship::Update(const float &dt) {}

// Ship Destructor
Ship::~Ship() = default;

// Invader Constructor (default)
Invader::Invader() : Ship() {}

// Invader Constructor with Arguments
Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
    setOrigin(Vector2f(16.f, 16.f));
    setPosition(pos);
}

void Invader::Update(const float &dt) {
    Ship::Update(dt);
}
