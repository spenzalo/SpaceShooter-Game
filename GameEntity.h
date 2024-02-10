#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <SFML/Graphics.hpp>

// The GameEntity class represents a  entity in your game.
class GameEntity
{
public:
    // Constructor to initialize a GameEntity with a texture and a scale factor.
    GameEntity(const sf::Texture &texture, float scale);

    // Pure virtual function that must be implemented by derived classes.
    virtual void update() = 0; // pure virtual function

    // Function to draw the entity on the given SFML window.
    void draw(sf::RenderWindow &window);

    // Function to check if the entity is out of bounds (above a certain height).
    bool isOutOfBounds(int windowHeight);

    // Function to check if the entity is hit by a bullet based on the bullet's
    // bounds.
    bool isHitByBullet(const sf::FloatRect &bulletBounds);

    // Get a reference to the internal sprite of the entity.
    sf::Sprite &getSprite();

protected:
    sf::Sprite sprite; // The sprite representing the entity.
};

#endif // GAME_ENTITY_H
