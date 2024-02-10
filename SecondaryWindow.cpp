#include "SecondaryWindow.h"
#include <SFML/Graphics.hpp>
#include "planet1.h"

sf::FloatRect getCustomBounds(const sf::Sprite& sprite, float reductionPercentage) {
    sf::FloatRect globalBounds = sprite.getGlobalBounds();
    
    float widthReduction = globalBounds.width * reductionPercentage;
    float heightReduction = globalBounds.height * reductionPercentage;

    return 
    
    sf::FloatRect(globalBounds.left + widthReduction / 2, 
                         globalBounds.top + heightReduction / 2, 
                         globalBounds.width - widthReduction, 
                         globalBounds.height - heightReduction);
}

void openSecondaryWindow() {
    sf::RenderWindow secondaryWindow(sf::VideoMode(1000, 800), "Space");

    // Load the background image for the secondary window
    sf::Texture background;
    if (!background.loadFromFile("/Users/spenzalo/Documents/OOP_project/universe.jpeg")){
        // Handling error
        return;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);

    sf::Texture spacecraft, planet1, planet2;
    if(!spacecraft.loadFromFile("/Users/spenzalo/Documents/OOP_project/spacecraft.png")) return;
    if(!planet1.loadFromFile("/Users/spenzalo/Documents/OOP_project/planet1.png")) return;

    sf::Sprite spacecraftImage, planet1Image;
    spacecraftImage.setTexture(spacecraft);
    planet1Image.setTexture(planet1);

    // Resizing the sprites:
    spacecraftImage.setScale(0.07f, 0.07f);  // adjust scale 
    planet1Image.setScale(0.1f, 0.1f);     // adjust scale 

    spacecraftImage.setPosition(10, 10);
    planet1Image.setPosition(350, 350);

    while (secondaryWindow.isOpen()) {
        sf::Event event;
        while (secondaryWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                secondaryWindow.close();

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Left:
                spacecraftImage.move(-20, 0); //change speed
                break;
            case sf::Keyboard::Right:
                spacecraftImage.move(20, 0);
                break;
            case sf::Keyboard::Up:
                spacecraftImage.move(0, -20);
                break;
            case sf::Keyboard::Down:
                spacecraftImage.move(0, 20);
                break;
            case sf::Keyboard::Escape:
                secondaryWindow.close();
                return;
                break;
            default:
                break;  // handle other key press events
        }
    } 
}

sf::FloatRect customSpacecraftBounds = getCustomBounds(spacecraftImage, 0.4);  // 40% reduction for spacecraft
        sf::FloatRect customPlanet1Bounds = getCustomBounds(planet1Image, 0.35);        // 35% reduction for planet1      // 35% reduction for planet2

        if(customSpacecraftBounds.intersects(customPlanet1Bounds)) {
            launchPlanet1();
            spacecraftImage.setPosition(10, 10);
        }

        secondaryWindow.clear(); 
        secondaryWindow.draw(backgroundSprite);  
        secondaryWindow.draw(planet1Image);
        secondaryWindow.draw(spacecraftImage);  
        secondaryWindow.display();
    }
}
