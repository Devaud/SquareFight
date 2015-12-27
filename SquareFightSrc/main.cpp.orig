#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

#include "square.h"
#include "zonning.h"
#include "bullet.h"

#define MAX_BULLET 10

void bulletEvent(std::list<Bullet> *bulletList, Square sq, Zonning *zone, bool *shooting);

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 720), "Square fight");
    window.setPosition(sf::Vector2i(200, 200)); 
    int i;
    // Create square
    Square sq;
    
    // Create zone
    Zonning zone(0, 0, window.getSize().x, window.getSize().y);
    sq.setZone(&zone);
    
    // Create bullet
    std::list<Bullet> bullets;
    bool shooting = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
 	    {
	        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		        window.close();
	    }
 
        bulletEvent(&bullets, sq, &zone, &shooting);
        sq.keyEvent();
        
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

void bulletEvent(std::list<Bullet> *bulletList, Square sq, Zonning *zone, bool *shooting)
{
     
    if (!*shooting)
    {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Bullet b(sf::Vector2f(HORIZONTAL_SHOOT));
        b.changeDirection(RIGHT_DIRECTION);
        b.setZone(zone);
        b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x - b.getSize().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
        bulletList->push_back(b);
        *shooting = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Bullet b(sf::Vector2f(HORIZONTAL_SHOOT));
        b.changeDirection(UP_DIRECTION);
        b.setZone(zone);
        b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y);
        bulletList->push_back(b);
        *shooting = true;
    }
       
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Bullet b(sf::Vector2f(HORIZONTAL_SHOOT));
        b.changeDirection(DOWN_DIRECTION); 
        b.setZone(zone);
        b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y + sq.getSquareSize().y - b.getSize().y);
        bulletList->push_back(b);
        *shooting = true;
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Bullet b(sf::Vector2f(HORIZONTAL_SHOOT));
        b.changeDirection(LEFT_DIRECTION); 
        b.setZone(zone);
        b.setPosition(sq.getSquarePosition().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
        bulletList->push_back(b);
        *shooting = true;
    }
    }
}

