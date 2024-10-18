//bullet.h 
#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public: 
    //static function to create a bullet
    static Bullet* CreateBullet(const sf::Vector2f& pos, bool mode);

    void Update(const float &dt);
    Bullet(const sf::Vector2f &pos, const bool mode);
    ~Bullet() = default;
protected:
    Bullet();
    //false=player bullet, true=enemy Bullet
    bool _mode;
};