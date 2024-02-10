#include "spacecraft.h"
#include "spaceSubcraft.h"
#include <SFML/Graphics.hpp>

Spacecraft::Spacecraft(int initialX, int initialY, const sf::Texture& texture)
    : x(initialX), y(initialY), velocityX(0.0f), velocityY(0.0f), hasCrystal(false) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    // Initialize crystal position relative to the spacecraft
    crystal.setPosition(x + 20, y - 20);
}


void Spacecraft::move(float deltaTime) {
    x += velocityX * deltaTime;
    y += velocityY * deltaTime;
    sprite.setPosition(x, y);

    if (hasCrystal) {
        crystal.setPosition(x + 20, y - 20); // Adjust crystal position relative to the spacecraft
    }
}

void Spacecraft::handleCollision() {
    // Basic collision handling logic
    // For simplicity, let's say if the spacecraft goes out of bounds, reset its position
    const float minX = 0;
    const float maxX = 800; // Assuming the screen width is 800
    const float minY = 0;
    const float maxY = 600; // Assuming the screen height is 600

    // Check for collision with screen boundaries
    if (x < minX) {
        x = minX;
    }
    if (x > maxX) {
        x = maxX;
    }
    if (y < minY) {
        y = minY;
    }
    if (y > maxY) {
        y = maxY;
    }

    sprite.setPosition(x, y);
}

bool Spacecraft::hasReachedFinishLine() const {
    return (y >= 500); // Assuming the finish line is at y-coordinate 500
}
bool Spacecraft::hasWon(const SpaceSubcraft& opponent1, const SpaceSubcraft& opponent2) const {
    // Check if the player has won based on the conditions
    bool hasReachedFinishLine = (y >= 500);
    bool isAheadOfOpponent1 = (y < opponent1.getY());
    bool isAheadOfOpponent2 = (y < opponent2.getY());

    return hasReachedFinishLine && isAheadOfOpponent1 && isAheadOfOpponent2;
}

bool Spacecraft::collectCrystal(int finishLineY, const SpaceSubcraft& opponent1, const SpaceSubcraft& opponent2) {
    // Check if the spacecraft has reached the finish line and is ahead of both opponents
    bool hasReachedFinishLine = (y >= 500);
    bool isAheadOfOpponent1 = (y < opponent1.getY());
    bool isAheadOfOpponent2 = (y < opponent2.getY());

    // Collect the crystal only if the spacecraft has reached the finish line and is ahead of both opponents
    if (hasReachedFinishLine && isAheadOfOpponent1 && isAheadOfOpponent2) {
        hasCrystal = true;
        return true; // Crystal collected
    }

    return false; // Crystal not collected
}

void Spacecraft::accelerate() {
    const float accelerationRate = 0.1f;
    velocityX += accelerationRate;
    velocityY += accelerationRate;
}

void Spacecraft::decelerate() {
    const float decelerationRate = 0.1f;
    velocityX -= decelerationRate;
    velocityY -= decelerationRate;
    // Ensure velocity doesn't go negative
    velocityX = std::max(0.0f, velocityX);
    velocityY = std::max(0.0f, velocityY);
}

void Spacecraft::moveLeft() {
    const float moveSpeed = 5.0f;
    velocityX -= moveSpeed;
}

void Spacecraft::moveRight() {
    const float moveSpeed = 5.0f;
    velocityX += moveSpeed;
}

sf::FloatRect Spacecraft::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Spacecraft::resetPosition(int initialX, int initialY) {
    // Reset the position of the spacecraft to its initial position
    x = initialX; // initialX should be a member variable in your Spacecraft class, representing the initial X-coordinate
    y = initialY; // initialY should be a member variable in your Spacecraft class, representing the initial Y-coordinate
    sprite.setPosition(x, y);
    // Reset other necessary variables and states of the spacecraft
}

void Spacecraft::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
    if (hasCrystal) {
        target.draw(crystal, states);
    }
}
