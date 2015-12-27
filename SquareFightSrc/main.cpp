#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "square.h"
#include "zonning.h"
#include "bullet.h"

void bulletEvent(std::list<Bullet> *bulletList, Square sq, Zonning *zone, bool *shooting, sf::Keyboard::Key *pressed);
bool isRemoving(Bullet b);

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 720), "Square fight");
    window.setPosition(sf::Vector2i(200, 200));
    int i;
    sf::Keyboard::Key currentPressedKey = sf::Keyboard::F15;
    // Create square
    Square sq;

    // Create zone
    Zonning zone(0, 0, window.getSize().x, window.getSize().y);
    sq.setZone(&zone);
    
    // Create bullet
    std::list<Bullet> bullets;
    bool shooting = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
        }

        bulletEvent(&bullets, sq, &zone, &shooting, &currentPressedKey);
        sq.keyEvent();
        bullets.remove_if(isRemoving);

        for (std::list<Bullet>::iterator bulletIt = bullets.begin(); bulletIt != bullets.end(); bulletIt++)
            bulletIt->moving();

        window.clear(sf::Color::Black);
        for (std::list<Bullet>::iterator bulletIt = bullets.begin(); bulletIt != bullets.end(); bulletIt++)
            window.draw(bulletIt->getBullet());
        window.draw(sq.getSquare());
        window.display();
    }

    return 0;
}

bool isRemoving(Bullet b)
{
    return (b.getOutZone());
}

void bulletEvent(std::list<Bullet> *bulletList, Square sq, Zonning *zone, bool *shooting, sf::Keyboard::Key *pressed)
{

    if (!*shooting) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            Bullet b(RIGHT_DIRECTION, zone);
            b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x - b.getSize().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
            bulletList->push_back(b);
            *shooting = true;
            *pressed = sf::Keyboard::Right;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            Bullet b(UP_DIRECTION, zone);
            b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y);
            bulletList->push_back(b);
            *shooting = true;
            *pressed = sf::Keyboard::Up;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            Bullet b(DOWN_DIRECTION, zone);
            b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y + sq.getSquareSize().y - b.getSize().y);
            bulletList->push_back(b);
            *shooting = true;
            *pressed = sf::Keyboard::Down;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            Bullet b(LEFT_DIRECTION, zone);
            b.setPosition(sq.getSquarePosition().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
            bulletList->push_back(b);
            *shooting = true;
            *pressed = sf::Keyboard::Left;
        }
    }
    else
    {
        if (!sf::Keyboard::isKeyPressed(*pressed))
            *shooting = false;
    }
}

