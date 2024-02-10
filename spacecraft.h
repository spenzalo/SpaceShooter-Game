#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include "GameEntity.h"
#include <SFML/Graphics.hpp>

class SpaceSubcraft; // Forward declaration of SpaceSubcraft class

class Spacecraft : public GameEntity {
public:
    Spacecraft(int initialX, int initialY, const sf::Texture& texture);

    void move(float deltaTime) override;
    void handleCollision() override;
    sf::FloatRect getGlobalBounds() const override;
    bool hasWon(const SpaceSubcraft& opponent1, const SpaceSubcraft& opponent2) const;
    bool hasReachedFinishLine() const;
    bool collectCrystal(int finishLineY, const SpaceSubcraft& opponent1, const SpaceSubcraft& opponent2);
    void accelerate();
    void decelerate();
    void moveLeft();
    void moveRight();
    void resetPosition(int initialX, int initialY);
    int getY() const {
        return y;
    }

private:
    int x;
    int y;
    float velocityX;
    float velocityY;
    bool hasCrystal;
    sf::Sprite sprite;
    sf::Sprite crystal;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // SPACECRAFT_H
