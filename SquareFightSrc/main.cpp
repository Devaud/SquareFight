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
        speed = sq.getSpeed();             
        window.clear(sf::Color::Black);
        window.draw(sq.getSquare());
        window.display();
    }

    return 0;
}
