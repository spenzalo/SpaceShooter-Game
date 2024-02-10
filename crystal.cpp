#include "crystal.h"

Crystal::Crystal(const std::string &name, const std::string &color, int cost) {
  this->name = name;
  this->color = color;
  this->cost = cost;
}

void Crystal::loadTexture(const std::string &texturePath) {
  if (!sprite.getTexture()) {
    sf::Texture texture;
    if (texture.loadFromFile(texturePath)) {
      sprite.setTexture(texture);
    }
  }
}

void Crystal::setPosition(float x, float y) { sprite.setPosition(x, y); }

void Crystal::draw(sf::RenderWindow &window) {
  window.draw(sprite);

  sf::Font font;
  font.loadFromFile("Tenar_Black.ttf"); // Use your font file

  sf::Text crystalInfo;
  crystalInfo.setFont(font);
  crystalInfo.setCharacterSize(18);
  crystalInfo.setString("Name: " + name + "\nColor: " + color +
                        "\nCost: " + std::to_string(cost));
  crystalInfo.setPosition(sprite.getPosition().x, sprite.getPosition().y - 50);
  crystalInfo.setFillColor(
      sf::Color::White); // Set the text color to match your crystal image.
  window.draw(crystalInfo);
}
