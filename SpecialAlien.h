// SpecialAlien.h
#ifndef SPECIALALIEN_H
#define SPECIALALIEN_H

#include <SFML/Graphics.hpp>

#include "alien.h"

class SpecialAlien : public Alien {
 public:
  SpecialAlien(const sf::Texture& texture, float scale, float speed,
               int pointValue, bool freezesSpacecraft);

  void update(sf::Sprite& spaceship);
  bool isFreezing;
  bool getIsFreezing() const { return isFreezing; };

 private:
  bool freezesSpacecraft_;
  ;
  sf::Color originalColor;
  sf::Clock freezeTimer;
  float spaceshipSpeed;  // Current speed of the spaceship
  float initialSpeed;    // Original speed of the spaceship before freezing
  static const float FREEZE_DURATION =
      3.0f;  // Duration of freeze in seconds
};

#endif  // SPECIALALIEN_H