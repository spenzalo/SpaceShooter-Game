// Alien.cpp
#include "alien.h"

// Constructor for the Alien class with default values
Alien::Alien() : GameEntity(sf::Texture(), 1.0f), speed(0.0f), pointValue(0)
{
  // Initialize with default values
}

// Constructor for the Alien class with custom parameters
Alien::Alien(const sf::Texture &texture, float scale, float speed,
             int pointValue)
    : GameEntity(texture, scale), speed(speed), pointValue(pointValue)
{
  // Additional initialization for Alien class, if needed
}

// Update function for the Alien class
void Alien::update()
{
  // Move the alien vertically based on its speed
  sprite.move(0, speed);
}

// Getter function to retrieve the point value of the alien
int Alien::getPointValue() const { return pointValue; }
