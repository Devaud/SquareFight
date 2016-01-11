#include "ui.h"

Ui::Ui(Square *sq)
{
	this->sq = sq;
	this->lb.setfullLife(sq->getLife());
	this->lb.setSize(sf::Vector2f(UI_LIFEBAR_SIZE));
	this->lb.setBorderSize(sf::Vector2f(UI_LIFEBAR_SIZE));
	this->lb.setPosition(sf::Vector2f(UI_LIFEBAR_POSITION));
}


Ui::~Ui()
{

}

void Ui::update()
{
	this->lb.setCurrentlyLife(this->sq->getLife());
}

void Ui::draw(sf::RenderWindow *win)
{
	this->lb.draw(win);
}
