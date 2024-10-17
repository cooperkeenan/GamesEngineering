//ship.h
#pragma once 
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    //default constructor is hidden
    Ship();
public:
    //construstor that takes a sprite
    explicit Ship(sf::IntRect ir);
    // pure virtial deconstructor
    virtual ~Ship() = 0;
    //Update, virtual so can be overridden but not pure virtual 
    virtual void Update(const float &dt);
};

class Invader : public Ship {
public:
    static bool direction;
    static float speed;
    Invader(sf::IntRect ir, sf::Vector2f pos);
    Invader();
    void Update(const float &dt) override;
};