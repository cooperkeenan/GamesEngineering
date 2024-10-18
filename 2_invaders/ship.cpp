#include "ship.h"
#include "game.h"
using namespace sf;

extern sf::Texture spritesheet;

bool Invader::direction;
float Invader::speed;

// Base Ship Constructor
Ship::Ship() {}

Ship::Ship(IntRect ir) : Sprite() {
    _sprite = ir;
    setTexture(spritesheet);
    setTextureRect(_sprite);
}

void Ship::Update(const float &dt) {}
Ship::~Ship() = default;

// Invader Constructor (default)
Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
    setOrigin(Vector2f(16.f, 16.f));
    setPosition(pos);
}

void Invader::Update(const float &dt) {
    Ship::Update(dt);

    // Move left or right based on direction
    move(Vector2f(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f));
}

// Player Constructor
Player::Player() : Ship(IntRect(sf::Vector2i(160, 32), sf::Vector2i(32, 32))) {
    setPosition(sf::Vector2f(gameWidth * 0.5f, gameHeight - 32.0f));
}

void Player::Update(const float &dt) {
    Ship::Update(dt);

    const float speed = 200.0f;

    // Move left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(-speed * dt, 0.0f);
    }

    // Move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(speed * dt, 0.0f);
    }

    // Ensure the player does not move off the edges of the screen
    if (getPosition().x < 16.0f) {
        setPosition(16.0f, getPosition().y);
    } else if (getPosition().x > gameWidth - 16.0f) {
        setPosition(gameWidth - 16.0f, getPosition().y);
    }
}
