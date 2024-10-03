#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

// Declarations
void Load();
void Update(RenderWindow& window);
void Render(RenderWindow& window);

const Keyboard::Key controls[4] = {
    Keyboard::A,   // Player1 UP
    Keyboard::Z,   // Player1 Down
    Keyboard::Up,  // Player2 UP
    Keyboard::Down // Player2 Down
};
const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;

Vector2f ballVelocity;
bool isPlayer1Serving = false;
const float initialVelocityX = -100.f;
const float initialVelocityY = -60.f;
const float velocityMultiplier = 1.1f;

CircleShape ball;
RectangleShape paddles[2];


int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}

void Load() {
    // Set size and origin of paddles
    for (auto &p : paddles) {
        p.setSize(paddleSize);
        p.setOrigin(paddleSize / 2.f);
    }

    ballVelocity = { (isPlayer1Serving ? initialVelocityX : -initialVelocityX), initialVelocityY };
    // Set size and origin of ball
    ball.setRadius(ballRadius);
    ball.setOrigin(ballRadius, ballRadius); //Should be half the ball width and height
    // reset paddle position
    paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
    paddles[1].setPosition(Vector2f(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f));

    // reset Ball Position
    ball.setPosition(Vector2f(gameWidth / 2.f, gameHeight / 2.f));

}

void Update(RenderWindow &window) {
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();

    ball.move(ballVelocity * dt);

    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    // handle paddle movement
    float direction1 = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) {
        direction1--;
    }
    if (Keyboard::isKeyPressed(controls[1])) {
        direction1++;
    }
    paddles[0].move(0.f, direction1 * paddleSpeed * dt);

    float direction2 = 0.0f;
    if (Keyboard::isKeyPressed(controls[2])) {
        direction2--;
    }
    if (Keyboard::isKeyPressed(controls[3])) {
        direction2++;
    }
    paddles[1].move(0.f, direction2 * paddleSpeed * dt);

    // Check ball collision with walls
    const float bx = ball.getPosition().x;
    const float by = ball.getPosition().y;

    if (by <= ballRadius || by >= gameHeight - ballRadius) {
        ballVelocity.y = -ballVelocity.y; // Invert Y velocity
    }

    if (bx <= ballRadius) {
        // Ball hits left wall
        isPlayer1Serving = false; // Player 2 serves next
        ballVelocity.x = -initialVelocityX; // Reset ball velocity
        ball.setPosition(gameWidth / 2.f, gameHeight / 2.f);
    } else if (bx >= gameWidth - ballRadius) {
        // Ball hits right wall
        isPlayer1Serving = true; // Player 1 serves next
        ballVelocity.x = initialVelocityX; // Reset ball velocity
        ball.setPosition(gameWidth / 2.f, gameHeight / 2.f);
    }

    // Check ball collision with paddles
    if ((bx <= paddles[0].getPosition().x + paddleSize.x / 2.f && bx >= paddles[0].getPosition().x - paddleSize.x / 2.f) &&
        (by >= paddles[0].getPosition().y - paddleSize.y / 2.f && by <= paddles[0].getPosition().y + paddleSize.y / 2.f)) {
        ballVelocity.x = -ballVelocity.x * velocityMultiplier; // Bounce off left paddle
    }

    if ((bx >= paddles[1].getPosition().x - paddleSize.x / 2.f && bx <= paddles[1].getPosition().x + paddleSize.x / 2.f) &&
        (by >= paddles[1].getPosition().y - paddleSize.y / 2.f && by <= paddles[1].getPosition().y + paddleSize.y / 2.f)) {
        ballVelocity.x = -ballVelocity.x * velocityMultiplier; // Bounce off right paddle
    }
}



void Render(RenderWindow &window) {
    // Draw Everything
    window.draw(paddles[0]);
    window.draw(paddles[1]);
    window.draw(ball);
}


ssh-add ~/Users/cooperkeenan/Documents/GitHub/GamesEngineering/ssh_key