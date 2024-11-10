// main.cpp
#include <SFML/Graphics.hpp>
#include "player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tile Engine - PRACTICAL_3");

    // Create player object
    Player player;

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update player
        double dt = clock.restart().asSeconds();
        player.Update(dt);

        // Render
        window.clear();
        player.Render(window);
        window.display();
    }

    return 0;
}
