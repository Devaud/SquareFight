#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "square.h"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 720), "Square fight");
    window.setPosition(sf::Vector2i(200, 200)); 

    Square sq;
    float speed;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
 	    {
	        if (event.type == sf::Event::Closed)
		        window.close();
	    }
        
        sq.keyEvent();
       
        // Colision testing
        if ((sq.getSquarePosition().x + sq.getSquareSize().x) >= window.getSize().x)
        {
            sq.setSquarePosition(window.getSize().x - sq.getSquareSize().x, sq.getSquarePosition().y); 
        }
    
        if (sq.getSquarePosition().x <= 0)
        {
            sq.setSquarePosition(0, sq.getSquarePosition().y); 
        }

        if (sq.getSquarePosition().y <= 0)
        {
            sq.setSquarePosition(sq.getSquarePosition().x, 0);
        }

        if ((sq.getSquarePosition().y + sq.getSquareSize().y) >= window.getSize().y)
        {
            sq.setSquarePosition(sq.getSquarePosition().x, window.getSize().y - sq.getSquareSize().y);
        }

        window.clear(sf::Color::Black);
        window.draw(sq.getSquare());
        window.display();
    }

    return 0;
}
