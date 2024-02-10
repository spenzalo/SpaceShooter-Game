#include <SFML/Graphics.hpp>
#include "SecondaryWindow.h"

int main()
{
    // creates a video mode object with a width of 1000 pixels and a height of 800 pixel called Space Odyssey 
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Space Odyssey");

    // Load up the background of the universe 
    sf::Texture background;
    if (!background.loadFromFile("/Users/spenzalo/Documents/OOP_project/universe.jpeg"))
    {
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);

    //Uplaod the font type
    sf::Font font;
    if (!font.loadFromFile("/Users/spenzalo/Documents/OOP_project/YoungSerif-Regular.ttf"))
    {
        return -1;
    }

    //Make the start button of the game displaying "start and space 
    sf::Text text;
    text.setFont(font);
    text.setString("SPACE ODYSSEY");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(270, 100);

    sf::RectangleShape start;
    start.setSize(sf::Vector2f(300, 100));
    start.setPosition(270, 450);
    start.setFillColor(sf::Color::White);

    sf::Text startText;
    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(24);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(start.getPosition().x + 80, start.getPosition().y + 15);

    // Center the button
    sf::Vector2u windowSize = window.getSize();
    float startX = windowSize.x / 2.0f;
    float startY = windowSize.y / 2.0f;

    start.setPosition(startX - start.getSize().x / 2, startY - start.getSize().y / 2);

    // Center the text inside the button
    sf::FloatRect textRect = startText.getLocalBounds();
    startText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    startText.setPosition(start.getPosition().x + start.getSize().x / 2.0f, start.getPosition().y + start.getSize().y / 2.0f);

    sf::RectangleShape quit;
    quit.setSize(sf::Vector2f(300, 100));
    quit.setPosition(270, 600);
    quit.setFillColor(sf::Color::White);

    sf::Text quitText;
    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(24);
    quitText.setFillColor(sf::Color::Black);
    quitText.setPosition(quit.getPosition().x + 100, quit.getPosition().y + 15);

    float margin = 20.0f; // Space between the buttons
    quit.setPosition(start.getPosition().x, start.getPosition().y + start.getSize().y + margin);

    // Center the quitText inside the quit button
    sf::FloatRect quitTextRect = quitText.getLocalBounds();
    quitText.setOrigin(quitTextRect.left + quitTextRect.width / 2.0f, quitTextRect.top + quitTextRect.height / 2.0f);
    quitText.setPosition(quit.getPosition().x + quit.getSize().x / 2.0f, quit.getPosition().y + quit.getSize().y / 2.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (start.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
        {
            window.setVisible(false); // hide the main window
            openSecondaryWindow();
            window.setVisible(true); // show the main window again
        }

        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            if (quit.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
            {
                window.close();
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(text);
        window.draw(start);
        window.draw(startText);
        window.draw(quit);
        window.draw(quitText);
        window.display();
    }
    return 0;
}
