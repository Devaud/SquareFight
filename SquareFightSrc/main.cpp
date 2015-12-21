#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "square.h"
#include "zonning.h"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 720), "Square fight");
    window.setPosition(sf::Vector2i(200, 200)); 

    Square sq;
    Zonning zone(0, 0, window.getSize().x, window.getSize().y);
    sq.setZone(&zone);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
 	    {
	        if (event.type == sf::Event::Closed)
		        window.close();
	    }
        
        sq.keyEvent();
        sq.collided();
        
        window.clear(sf::Color::Black);
        window.draw(sq.getSquare());
        window.display();
    }

    return 0;
}
