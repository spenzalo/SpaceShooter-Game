#include "GameEntity.h"

// Constructor for the GameEntity class, which initializes the sprite with a
// texture and scale.
GameEntity::GameEntity(const sf::Texture &texture, float scale)
{
  sprite.setTexture(texture);    // Set the texture for the sprite
  sprite.setScale(scale, scale); // Set the scale of the sprite
}

// This function is used to draw the GameEntity on the specified SFML window.
void GameEntity::draw(sf::RenderWindow &window)
{
  window.draw(sprite); // Draw the sprite on the window
}

// This function checks if the GameEntity is out of bounds, given the window
// height.
bool GameEntity::isOutOfBounds(int windowHeight)
{
  // Check if the y-coordinate of the sprite's position is greater than the
  // window's height.
  return sprite.getPosition().y > windowHeight;
}

// This function checks if the GameEntity is hit by a bullet, based on the
// intersection of bounding rectangles.
bool GameEntity::isHitByBullet(const sf::FloatRect &bulletBounds)
{
  // Check if the global bounds of the sprite intersect with the given bullet
  // bounds.
  return sprite.getGlobalBounds().intersects(bulletBounds);
}

// This function provides access to the underlying sprite of the GameEntity.
sf::Sprite &GameEntity::getSprite()
{
  return sprite; // Return a reference to the sprite
}
