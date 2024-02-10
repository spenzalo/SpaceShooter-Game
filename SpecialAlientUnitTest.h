// AlienUnitTest.h

#ifndef ALIEN_UNIT_TEST_H
#define ALIEN_UNIT_TEST_H

#include "alien.h"
#include <iostream>

class AlienUnitTest {
public:
  void runTests() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testGetPointValue();
  }

private:
  void testDefaultConstructor() {
    Alien alien;

    if (alien.getPointValue() != 0) {
      std::cout << "Test Default Constructor failed!" << std::endl;
    }
  }

  void testParameterizedConstructor() {
    sf::Texture
        texture; // Create a texture (You may need to set it up properly)
    float scale = 1.0f;
    float speed = 2.0f;
    int pointValue = 10;
    Alien alien(texture, scale, speed, pointValue);

    if (alien.getPointValue() != pointValue) {
      std::cout << "Test Parameterized Constructor failed!" << std::endl;
    }
  }

  void testGetPointValue() {
    sf::Texture
        texture; // Create a texture (You may need to set it up properly)
    float scale = 1.0f;
    float speed = 2.0f;
    int pointValue = 15; // Change the expected point value
    Alien alien(texture, scale, speed, pointValue);

    if (alien.getPointValue() != pointValue) {
      std::cout << "Test GetPointValue failed!" << std::endl;
    }
  }
};

#endif // ALIEN_UNIT_TEST_H
