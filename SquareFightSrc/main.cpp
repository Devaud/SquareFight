#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1024, 720), "Square fight");
    window.setPosition(sf::Vector2i(200, 200)); 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
 	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}
	
	window.clear(sf::Color::Black);
	window.display();
    }

    return 0;
}
