#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "zonning.h"
#include "lifeBar.h"

#define DEFAULT_SPEED 0.5f
#define DEFAULT_LIFE 100
#define DEFAULT_ARMOR 5
#define DEFAULT_SIZE 50, 50
#define DEFAULT_COLOR 100, 250, 50
/*
	Author      : Devaud
	Description : Square class contains all square's  data and logical
	Date        : 2015.12.21
	Version     : 1.0
*/

class Square
{
public:
	Square();
	Square(bool showLifebar);

	float getSpeed();
	int getLife();
	int getArmor();
	sf::RectangleShape getSquare();
	sf::Vector2f getSquarePosition();
	sf::Vector2f getSquareSize();
	sf::Color getColor();
	Zonning getZone();

	void setColor(int r, int g, int b);
	void setSize(int width, int height);
	void setSquarePosition(float x, float y);
	void setZone(Zonning *zone);

	void keyEvent();
	void attacked(int damage);
	void draw(sf::RenderWindow *win);
	bool isAlive();

private:
	void initRect();
	void moving();
	void zonningCollide();
	void collided();
	
	sf::RectangleShape rect;
	int life;
	int armor;
	float speed;
	bool alive;
	bool showLifebar;
	Zonning *zone;
	lifeBar lb;
};


#endif
