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
<<<<<<< HEAD
 	    {
	        if (event.type == sf::Event::Closed)
		        window.close();
	    }
    
        window.clear(sf::Color::Black);
        window.display();
    }

    

=======
 	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}
	
	window.clear(sf::Color::Black);
	window.display();
    }

>>>>>>> 2ed5e69185dde54ed90e05c4cfbb4522b2372a48
    return 0;
}
