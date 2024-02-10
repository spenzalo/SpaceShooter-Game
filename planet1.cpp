#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

// Include the Alien class header
#include "SpecialAlien.h"
#include "alien.h"

void launchPlanet1()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Planet1");

  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("/Users/spenzalo/Documents/OOP_project/background.png"))
  {
    return;
  }
  sf::Sprite background(backgroundTexture);
  background.setScale(
      static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
      static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);

  sf::Texture spaceshipTexture;
  if (!spaceshipTexture.loadFromFile("/Users/spenzalo/Documents/OOP_project/spaceship.png"))
  {
    return;
  }
  sf::Sprite spaceship(spaceshipTexture);
  float spaceshipScale = 0.1f;
  spaceship.setScale(spaceshipScale, spaceshipScale);
  sf::Vector2f spaceshipPosition(
      0, window.getSize().y - spaceship.getGlobalBounds().height);
  spaceship.setPosition(spaceshipPosition);
  float spaceshipSpeed = 0.5f;

  sf::Texture bulletTexture;
  if (!bulletTexture.loadFromFile("/Users/spenzalo/Documents/OOP_project/bullet.png"))
  {
    return;
  }
  float bulletScale = 0.1f;
  float bulletSpeed = 0.5f;
  std::vector<sf::Sprite> bullets;

  sf::Texture alienTexture1, alienTexture2, alienTexture3, specialAlienTexture;
  if (!alienTexture1.loadFromFile("/Users/spenzalo/Documents/OOP_project/alien1.png") ||
      !alienTexture2.loadFromFile("/Users/spenzalo/Documents/OOP_project/alien2.png") ||
      !alienTexture3.loadFromFile("/Users/spenzalo/Documents/OOP_project/alien3.png") ||
      !specialAlienTexture.loadFromFile("/Users/spenzalo/Documents/OOP_project/special_alien.png"))
  {
    return;
  }

  // Create different types of aliens
  Alien alien1(alienTexture1, 0.1f, 0.01f,
               7); // Example values for the first alien type
  Alien alien2(alienTexture2, 0.1f, 0.015f,
               10); // Example values for the second alien type
  Alien alien3(alienTexture3, 0.1f, 0.05f,
               8); // Example values for the third alien type

  std::vector<Alien> aliens;

  // Create a special alien
  SpecialAlien specialAlien(specialAlienTexture, 0.1f, 0.02f, 15, true);

  int score = 0; // Initialize the score

  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  bool crystalCollected = false;

  bool spacePressed = false;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||
    (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) ||
    (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))))
    {
        std::cout << "Invalid keypress"<< std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        spaceshipPosition.x > 0)
    {
      spaceshipPosition.x -= spaceshipSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        spaceshipPosition.x <
            window.getSize().x - spaceship.getGlobalBounds().width)
    {
      spaceshipPosition.x += spaceshipSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spaceshipPosition.x > 0)
    {
      spaceshipPosition.x -= spaceshipSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        spaceshipPosition.x <
            window.getSize().x - spaceship.getGlobalBounds().width)
    {
      spaceshipPosition.x += spaceshipSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      if (!spacePressed) // This means spacebar just got pressed
      {
        sf::Sprite bullet(bulletTexture);
        bullet.setScale(bulletScale, bulletScale);
        sf::Vector2f bulletPosition(spaceshipPosition.x +
                                        spaceship.getGlobalBounds().width / 2 -
                                        bullet.getGlobalBounds().width / 2,
                                    spaceshipPosition.y);
        bullet.setPosition(bulletPosition);
        bullets.push_back(bullet);
        spacePressed = true; // Set the flag to indicate spacebar is pressed
      }
    }
    else
    {
      spacePressed = false; // Spacebar is released, reset the flag
    }

    if (rand() % 10000 < 5)
    {
      if (rand() % 10 == 0)
      { // 10% chance to spawn a special alien
        // Create and position a SpecialAlien instance
        sf::Vector2f alienPosition(
            static_cast<float>(
                rand() % static_cast<int>(
                             window.getSize().x -
                             specialAlien.getSprite().getGlobalBounds().width)),
            0);
        specialAlien.getSprite().setPosition(alienPosition);
        aliens.push_back(specialAlien);
      }
      else
      {
        // Randomly select a regular alien type
        int alienType = rand() % 3;
        Alien newAlien = (alienType == 0)   ? alien1
                         : (alienType == 1) ? alien2
                                            : alien3;
        sf::Vector2f alienPosition(
            static_cast<float>(
                rand() %
                static_cast<int>(window.getSize().x -
                                 newAlien.getSprite().getGlobalBounds().width)),
            0);
        newAlien.getSprite().setPosition(alienPosition);
        aliens.push_back(newAlien);
      }
    }

    // Check for collisions between bullets and aliens
    for (int i = 0; i < bullets.size(); ++i)
    {
      bullets[i].move(0, -bulletSpeed);
      if (bullets[i].getPosition().y < 0)
      {
        bullets.erase(bullets.begin() + i);
      }
      else
      {
        for (int j = 0; j < aliens.size(); ++j)
        {
          if (bullets[i].getGlobalBounds().intersects(
                  aliens[j].getSprite().getGlobalBounds()))
          {
            bullets.erase(bullets.begin() + i);
            score +=
                aliens[j].getPointValue(); // Add points for hitting an alien
            aliens.erase(aliens.begin() + j);
            break;
          }
        }
      }
    }

    for (int i = 0; i < aliens.size(); ++i)
    {
      aliens[i].update();
      if (aliens[i].getSprite().getPosition().y > window.getSize().y)
      {
        aliens.erase(aliens.begin() + i);
      }
    }
    // Update and check for collisions with the special alien
    specialAlien.update(spaceship);
    if (specialAlien.getSprite().getGlobalBounds().intersects(
            spaceship.getGlobalBounds()))
    {
      if (specialAlien.getIsFreezing())
      {
        spaceshipSpeed = 0.2f; // Reduce spaceship speed when frozen
      }
      else
      {
        spaceshipSpeed =
            0.5f; // Reset spaceship speed after freeze effect ends
      }
    }

    for (int i = 0; i < aliens.size(); ++i)
    {
      aliens[i].update();
      if (aliens[i].getSprite().getPosition().y > window.getSize().y)
      {
        aliens.erase(aliens.begin() + i);
      }
    }
    spaceship.setPosition(spaceshipPosition);

    window.clear();

    if (score >= 260)
    {
      sf::Texture crystalTexture;
      if (!crystalTexture.loadFromFile("/Users/spenzalo/Documents/OOP_project/crystal.png"))
      {
        return;
      }
      sf::Sprite crystalBackground(crystalTexture);
      crystalBackground.setScale(
          static_cast<float>(window.getSize().x) / crystalTexture.getSize().x,
          static_cast<float>(window.getSize().y) / crystalTexture.getSize().y);
      window.draw(crystalBackground);

      sf::Font font;
      font.loadFromFile("/Users/spenzalo/Documents/OOP_project/YoungSerif-Regular.ttf");
      sf::Text crystalText("You have collected the crystal", font);
      crystalText.setCharacterSize(30);
      crystalText.setPosition(200, 300);
      crystalText.setFillColor(
          sf::Color::Black); // Set the text color to black
      window.draw(crystalText);

      crystalCollected = true;
    }
    else
    {
      window.draw(background);
      window.draw(spaceship);
      for (int i = 0; i < bullets.size(); ++i)
      {
        window.draw(bullets[i]);
      }
      for (int i = 0; i < aliens.size(); ++i)
      {
        aliens[i].draw(window);
      }
    }

    sf::Font font;
    font.loadFromFile("/Users/spenzalo/Documents/OOP_project/YoungSerif-Regular.ttf");
    sf::Text scoreText("Score: " + std::to_string(score), font);
    scoreText.setCharacterSize(24);
    scoreText.setPosition(10, 10);
    scoreText.setFillColor(sf::Color::Red); // Set the text color to red
    window.draw(scoreText);

    // put into the window open area

    for (int i = 0; i < aliens.size(); ++i)
    {
      aliens[i].update();

      // Check if an alien reaches the bottom of the screen
      if (aliens[i].getSprite().getPosition().y > window.getSize().y)
      {
        aliens.erase(aliens.begin() + i);

        // Subtract 10 points when an alien reaches the bottom
        score -= 10;
      }
    }
    window.display();
  }

  std::string playerName;
  std::cout << "Enter your name: ";
  std::cin >> playerName;

  std::ofstream outfile("/Users/spenzalo/Documents/OOP_project/scores.txt", std::ios::app); // Open in append mode
  if (outfile.is_open())
  {
    outfile << playerName << " " << score << std::endl;
    outfile.close();
  }
  else
  {
    std::cerr << "Unable to open scores.txt for writing." << std::endl;
  }

  std::vector<std::pair<int, std::string> > leaderboard;
  std::ifstream infile("/Users/spenzalo/Documents/OOP_project/scores.txt");
  std::string readName;
  int readScore;
  while (infile >> readName >> readScore)
  {
    leaderboard.push_back(std::make_pair(readScore, readName));
  }
  infile.close();

  // Sort in descending order using Bubble Sort
  for (size_t i = 0; i < leaderboard.size(); i++)
  {
    for (size_t j = 0; j < leaderboard.size() - i - 1; j++)
    {
      if (leaderboard[j].first < leaderboard[j + 1].first)
      {
        // swap
        std::pair<int, std::string> temp = leaderboard[j];
        leaderboard[j] = leaderboard[j + 1];
        leaderboard[j + 1] = temp;
      }
    }
  }

  // Display the top entries using traditional array indexing
  for (size_t i = 0; i < leaderboard.size(); i++)
  {
    printf("%s: %d\n", leaderboard[i].second.c_str(), leaderboard[i].first);
  }
}
