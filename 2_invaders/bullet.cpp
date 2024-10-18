//bullet.cpp
#include "bullet.h"
#include "game.h"
using namespace sf;
using namespace std;

// Static function definition 
Bullet* Bullet::CreateBullet(const sf::Vector2f& pos, bool mode) {
    return new Bullet(pos, mode);
}

// Constructor
Bullet::Bullet(const sf::Vector2f &pos, const bool mode) {
    setTexture(spritesheet);  // Set the entire texture first

    int bulletWidth = 8;  
    int bulletHeight = 26; 
    
    int bulletX = 160; 
    int bulletY = 32;  // The vertical offset for the bullet row

    setTextureRect(IntRect(bulletX, bulletY, bulletWidth, bulletHeight));
    setPosition(pos);
    _mode = mode;
}

void Bullet::Update(const float &dt) {
    // Move bullet upwards if it's a player bullet, downwards if it's an enemy bullet.
    move(Vector2f(0, dt * 200.0f * (_mode ? 1.0f : -1.0f)));
}
