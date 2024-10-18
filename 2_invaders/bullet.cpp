#include "bullet.h"
#include "game.h"
using namespace sf;

unsigned char Bullet::bulletPointer = 0;
Bullet Bullet::bullets[255]; // Array to hold all bullets

Bullet::Bullet() {
    // Constructor to initialize bullet properties
    _mode = false;
}

void Bullet::Init() {
    // This function can initialize any properties for the bullets array if needed.
    // Here we just reset all bullets to a default state.
    for (auto &bullet : bullets) {
        bullet.setPosition(0, 0);  // Set the initial position to "inactive" at (0, 0)
        bullet._mode = false;      // Set the initial mode to false (assumes false means player bullet)
    }
}

void Bullet::Fire(const sf::Vector2f &pos, const bool mode) {
    bullets[bulletPointer].setTexture(spritesheet);
    
    // Set bullet's position and texture rectangle for the sprite
    bullets[bulletPointer].setTextureRect(IntRect(160, 32, 8, 26));
    bullets[bulletPointer].setPosition(pos);
    bullets[bulletPointer]._mode = mode;

    bulletPointer++;
    if (bulletPointer >= 255) {
        bulletPointer = 0; // Loop back to reuse bullet slots
    }
}

void Bullet::Update(const float &dt) {
    for (auto &bullet : bullets) {
        bullet._Update(dt);
    }
}

void Bullet::Render(sf::RenderWindow &window) {
    for (auto &bullet : bullets) {
        // Only render bullets that are on the screen (i.e., with a position set)
        if (bullet.getPosition().y != 0) {
            window.draw(bullet);
        }
    }
}

void Bullet::_Update(const float &dt) {
    // Only update bullet if it is active
    if (getPosition().y != 0) {
        // Move bullet upwards if it's a player bullet, downwards if it's an enemy bullet.
        move(Vector2f(0, dt * 200.0f * (_mode ? 1.0f : -1.0f)));

        // If the bullet goes off-screen, reset its position (considered inactive)
        if (getPosition().y < 0 || getPosition().y > gameHeight) {
            setPosition(0, 0); // Setting position to 0 means inactive
        }
    }
}
