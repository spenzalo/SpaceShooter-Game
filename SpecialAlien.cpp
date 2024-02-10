#include "SpecialAlien.h"

SpecialAlien::SpecialAlien(const sf::Texture &texture, float scale, float speed,
                           int pointValue, bool freezesSpacecraft)
    : Alien(texture, scale, speed, pointValue),
      freezesSpacecraft_(freezesSpacecraft), isFreezing(false) {
  // Initialize other member variables
  spaceshipSpeed = speed;
  initialSpeed = speed;
}

void SpecialAlien::update(sf::Sprite &spaceship) {
  // Call the base class update function to move the special alien
  Alien::update();

  // Check if the special alien freezes the spacecraft and the freezing effect
  // is not active
  if (freezesSpacecraft_ && !isFreezing) {
    // Check for collision with the spaceship
    if (getSprite().getGlobalBounds().intersects(spaceship.getGlobalBounds())) {
      // Apply the freezing effect
      isFreezing = true;
      originalColor = spaceship.getColor();
      spaceship.setColor(sf::Color::Blue); // Change spaceship color when frozen
      spaceshipSpeed = 0.0f;               // Stop the spaceship when frozen
      freezeTimer.restart();               // Start the freeze timer
    }
  }

  // Check if the freezing effect is active and has lasted for the specified
  // duration
  if (isFreezing &&
      freezeTimer.getElapsedTime().asSeconds() >= FREEZE_DURATION) {
    // Restore the original color and speed of the spaceship
    spaceship.setColor(originalColor);
    spaceshipSpeed = initialSpeed;
    isFreezing = false; // Reset the freezing effect
  }
}
