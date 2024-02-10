#ifndef CRYSTAL_H
#define CRYSTAL_H

#include <SFML/Graphics.hpp>
#include <string>

class Crystal {
public:
    Crystal(const std::string& name, const std::string& color, int cost);
    void loadTexture(const std::string& texturePath);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
private:
    std::string name;
    std::string color;
    int cost;
    sf::Sprite sprite;
};

#endif
