#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Squre fight");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
 	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}
    }

    return 0;
}
