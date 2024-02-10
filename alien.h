// Alien class definition for creating game entities representing alien
// characters. Aliens have various properties like speed and point value, and
// they can be updated as part of the game's dynamics.

#ifndef ALIEN_H
#define ALIEN_H

#include "GameEntity.h"

class Alien : public GameEntity
{
public:
  // Default constructor for the Alien class
  Alien();

  // Constructor that takes a texture, scale, speed, and point value as
  // parameters
  Alien(const sf::Texture &texture, float scale, float speed, int pointValue);

  // Update function to handle the alien's behavior in the game
  void update();

  // Getter function to retrieve the point value of the alien
  int getPointValue() const;

private:
  float speed;    // The speed of the alien
  int pointValue; // The point value awarded when the alien is defeated
};

#endif // ALIEN_H
