//player.cpp
#include "player.h"

using namespace sf;
using namespace std;

void Player::Update(double dt) {
    sf::Vector2f direction(0.f, 0.f);

    //move in 4 directions based on keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x += 1;

    // scale direction by speed and delta time 
    direction *= _speed * static_cast<float>(dt);

    //move the player 
    move(direction);

    //Update
    Entity::Update(dt); 
}


Player::Player()
    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}


void Player::Render(sf::RenderWindow &window) const {
    window.draw(*_shape);
}