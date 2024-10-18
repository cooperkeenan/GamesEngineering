// main.cpp
#include <SFML/Graphics.hpp>
#include "game.h"

int main() {
    Load();

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Calculate delta time
        float dt = clock.restart().asSeconds();

        // Update game entities
        Update(dt);

        // Render everything
        Render();
    }

    // Clean up dynamic memory
    delete player;
    delete invaderManager;

    return 0;
}
