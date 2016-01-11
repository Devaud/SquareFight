#ifndef LIFEBAR_H
#define LIFEBAR_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define MAX_WIDTH 50
#define START_SIZE MAX_WIDTH, 10
#define START_COLOR 255, 0, 0
#define BORDER_COLOR 222, 184, 135
#define BORDER_BACKGROUND 150, 104, 44
#define DEFAULT_FULL_LIFE 100
#define BORDER_THICKNESS 2
#define SPACING 15

/*
	Author      : Devaud
	Description : Life bar is the class for show the life of on oject like Square
	Date        : 2016.01.06
	Version     : 1.0
*/

class lifeBar
{
public:
	lifeBar();
	lifeBar(int fullLife);
	~lifeBar();

	sf::Vector2f getSize();

	void setPosition(sf::Vector2f pos);
	void setCurrentlyLife(int life);
	void setfullLife(int life);
	void setSize(sf::Vector2f size);
	void setBorderSize(sf::Vector2f size);

	void draw(sf::RenderWindow *win);
	void moving(float x, float y);
	void moving(sf::Vector2f speed);

private:
	void initLifebarProperties(sf::Vector2f mSize, sf::Color mColor);

	sf::RectangleShape lifebar;
	sf::RectangleShape border;
	int fullLife;
	int currentlyLife;
	int maxWidth;
};

#endif

