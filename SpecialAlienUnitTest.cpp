// SpecialAlienUnitTest.h

#ifndef SPECIAL_ALIEN_UNIT_TEST_H
#define SPECIAL_ALIEN_UNIT_TEST_H

#include "SpecialAlien.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SpecialAlienUnitTest {
public:
  void runTests() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testGetIsFreezing();
  }

private:
  void testDefaultConstructor() {
    sf::Texture
        texture; // Create a texture (You may need to set it up properly)
    float scale = 1.0f;
    float speed = 2.0f;
    int pointValue = 10;
    bool freezesSpacecraft =
        true; // Set freezing to true for the default constructor test
    SpecialAlien specialAlien(texture, scale, speed, pointValue,
                              freezesSpacecraft);

    if (specialAlien.getPointValue() != pointValue ||
        !specialAlien.getIsFreezing()) {
      std::cout << "Test Default Constructor failed!" << std::endl;
    }
  }

  void testParameterizedConstructor() {
    sf::Texture
        texture; // Create a texture (You may need to set it up properly)
    float scale = 1.0f;
    float speed = 2.0f;
    int pointValue = 15; // Change the expected point value
    bool freezesSpacecraft =
        false; // Set freezing to false for the parameterized constructor test
    SpecialAlien specialAlien(texture, scale, speed, pointValue,
                              freezesSpacecraft);

    if (specialAlien.getPointValue() != pointValue ||
        specialAlien.getIsFreezing()) {
      std::cout << "Test Parameterized Constructor failed!" << std::endl;
    }
  }

  void testGetIsFreezing() {
    sf::Texture
        texture; // Create a texture (You may need to set it up properly)
    float scale = 1.0f;
    float speed = 2.0f;
    int pointValue = 15;
    bool freezesSpacecraft = true;
    SpecialAlien specialAlien(texture, scale, speed, pointValue,
                              freezesSpacecraft);

    if (!specialAlien.getIsFreezing()) {
      std::cout << "Test GetIsFreezing failed!" << std::endl;
    }
  }
};

#endif // SPECIAL_ALIEN_UNIT_TEST_H
