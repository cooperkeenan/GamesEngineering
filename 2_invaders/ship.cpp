#include "ship.h"
#include "game.h"
#include "bullet.h"
#include <vector>    
#include <iostream>  


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

    fireCooldown = 0.5f;
    timeSinceLastFire = fireCooldown;
}

void Player::Update(const float &dt) {
    Ship::Update(dt);

    const float speed = 200.0f;

    // Update the time since the last shot
    timeSinceLastFire += dt;

    // Move left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(-speed * dt, 0.0f);
    }

    // Move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(speed * dt, 0.0f);
    }

    // Shoot bullet if cooldown is complete
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
        && timeSinceLastFire >= fireCooldown) {
        
        Bullet::Fire(getPosition(), false);
        timeSinceLastFire = 0.0f; // Reset the timer after firing

        std::cout << "Bullet fired! Current number of bullets: " << bullets.size() << std::endl;
    }

    // Update bullets and remove those out of bounds
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        Bullet* bullet = *it;
        bullet->Update(dt);

        // Remove bullets that go out of the window bounds
        if (bullet->getPosition().y < 0 || bullet->getPosition().y > gameHeight) {
            delete bullet;  // Clean up memory
            it = bullets.erase(it);
        } else {
            ++it;
        }
    }

    // Ensure the player does not move off the edges of the screen
    if (getPosition().x < 16.0f) {
        setPosition(16.0f, getPosition().y);
    } else if (getPosition().x > gameWidth - 16.0f) {
        setPosition(gameWidth - 16.0f, getPosition().y);
    }
}
