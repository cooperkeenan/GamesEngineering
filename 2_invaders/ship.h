#pragma once 
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    Ship();  // default constructor is hidden
public:
    explicit Ship(sf::IntRect ir);  // constructor that takes a sprite rect
    virtual ~Ship() = 0;  // pure virtual destructor
    virtual void Update(const float &dt);  // Update, virtual so it can be overridden
};

class Invader : public Ship {
public:
    static bool direction;
    static float speed;
    Invader(sf::IntRect ir, sf::Vector2f pos);
    Invader();
    void Update(const float &dt) override;
};

class Player : public Ship {
public:
    Player();
    void Update(const float &dt) override;
};

// Extern declarations for global variables
extern sf::Texture spritesheet;
