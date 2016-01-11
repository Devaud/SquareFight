#ifndef UI_H
#define UI_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "lifeBar.h"
#include "square.h"

#define UI_LIFEBAR_SIZE 150, 20
#define UI_LIFEBAR_POSITION 5, 20

class Ui
{
public:
	Ui(Square *sq);
	~Ui();

	void draw(sf::RenderWindow *win);
	void update();

private:
	lifeBar lb;
	Square *sq;
	
};

#endif