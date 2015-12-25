#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "square.h"
#include "zonning.h"
#include "bullet.h"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 720), "Square fight");
    window.setPosition(sf::Vector2i(200, 200)); 
    
    // Create square
    Square sq;
    // Create zone
    Zonning zone(0, 0, window.getSize().x, window.getSize().y);
    sq.setZone(&zone);

    // Create bullet
    Bullet b(sf::Vector2f(HORIZONTAL_SHOOT));
    b.setZone(&zone);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
 	    {
	        if (event.type == sf::Event::Closed)
		        window.close();
	    }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            b.changeDirection(RIGHT_DIRECTION);
            b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x - b.getSize().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            b.changeDirection(UP_DIRECTION);
            b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y);
        }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            b.changeDirection(DOWN_DIRECTION); 
            b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y + sq.getSquareSize().y - b.getSize().y);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            b.changeDirection(LEFT_DIRECTION); 
            b.setPosition(sq.getSquarePosition().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
        }
        sq.keyEvent();
        
        b.moving();
        
        window.clear(sf::Color::Black);
        window.draw(b.getBullet());
        window.draw(sq.getSquare());
        window.display();
    }

    return 0;
}
