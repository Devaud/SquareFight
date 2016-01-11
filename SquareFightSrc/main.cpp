#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>
#include <iostream>

#include "square.h"
#include "zonning.h"
#include "bullet.h"
#include "ui.h"

void bulletEvent(std::list<Bullet> *bulletList, Square sq, Zonning *zone, bool *shooting, sf::Keyboard::Key *pressed);
bool isRemoving(Bullet b);
bool isNotAlive(Square sq);
void updateList(std::list<Bullet> *bulletList, std::list<Square> *SquareList);
void drawList(sf::RenderWindow *win, std::list<Bullet> *bulletList, std::list<Square> *squareList);

int main()
{

	sf::RenderWindow window;
	window.create(sf::VideoMode(1024, 720), "Square fight");
	window.setPosition(sf::Vector2i(200, 200));
	sf::Keyboard::Key currentPressedKey = sf::Keyboard::F15;
		 
	// Create square
	Square sq(false);
	Ui ui(&sq);

	std::list<Square> ennemies;

	Square sqare;
	sqare.setSquarePosition(100, 100);
	sqare.setColor(0, 0, 255);
	ennemies.push_back(sqare);

	// Create zone
	Zonning zone(0, 0, (float)window.getSize().x, (float)window.getSize().y);
	sq.setZone(&zone);

	// Create bullet
	std::list<Bullet> bullets;
	
	bool shooting = false;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				window.close();
		}

		bulletEvent(&bullets, sq, &zone, &shooting, &currentPressedKey);
		sq.keyEvent();

		// Update list
		updateList(&bullets, &ennemies);
		ui.update();

		// Drawing
		window.clear(sf::Color::Black);
		drawList(&window, &bullets, &ennemies);
		sq.draw(&window);
		ui.draw(&window);
		window.display();
	}

	return 0;
}

void drawList(sf::RenderWindow *win, std::list<Bullet> *bulletList, std::list<Square> *squareList)
{
	if (bulletList->size() > 0)
	{
		for (std::list<Bullet>::iterator bulletIt = bulletList->begin(); bulletIt != bulletList->end(); bulletIt++)
			bulletIt->draw(win);
	}
	
	if (squareList->size() > 0)
	{
		for (std::list<Square>::iterator squareIt = squareList->begin(); squareIt != squareList->end(); squareIt++)
			squareIt->draw(win);
	}
}

void updateList(std::list<Bullet> *bulletList, std::list<Square> *squareList)
{
	bulletList->remove_if(isRemoving);
	squareList->remove_if(isNotAlive);

	for (std::list<Bullet>::iterator bulletIt = bulletList->begin(); bulletIt != bulletList->end(); bulletIt++)
	{
		bulletIt->moving();

		if (squareList->size() > 0)
		{
			for (std::list<Square>::iterator squareIt = squareList->begin(); squareIt != squareList->end(); squareIt++)
				bulletIt->hitted(&*squareIt);
		}
	}
}

bool isNotAlive(Square sq)
{
	return (!sq.isAlive());
}

bool isRemoving(Bullet b)
{
	return (b.getOutZone());
}

void bulletEvent(std::list<Bullet> *bulletList, Square sq, Zonning *zone, bool *shooting, sf::Keyboard::Key *pressed)
{

	if (!*shooting) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			Bullet b(RIGHT_DIRECTION, zone, sq.getColor());
			b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x - b.getSize().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
			std::cout << b.getSize().x << " " << b.getSize().y << std::endl;
			bulletList->push_back(b);
			*shooting = true;
			*pressed = sf::Keyboard::Right;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			Bullet b(UP_DIRECTION, zone, sq.getColor());
			b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y);
			bulletList->push_back(b);
			*shooting = true;
			*pressed = sf::Keyboard::Up;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			Bullet b(DOWN_DIRECTION, zone, sq.getColor());
			b.setPosition(sq.getSquarePosition().x + sq.getSquareSize().x / 2 - b.getSize().x / 2, sq.getSquarePosition().y + sq.getSquareSize().y - b.getSize().y);
			bulletList->push_back(b);
			*shooting = true;
			*pressed = sf::Keyboard::Down;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			Bullet b(LEFT_DIRECTION, zone, sq.getColor());
			b.setPosition(sq.getSquarePosition().x, sq.getSquarePosition().y + sq.getSquareSize().y / 2 - b.getSize().y / 2);
			bulletList->push_back(b);
			*shooting = true;
			*pressed = sf::Keyboard::Left;
		}
	}
	else
	{
		if (!sf::Keyboard::isKeyPressed(*pressed))
			*shooting = false;
	}
}