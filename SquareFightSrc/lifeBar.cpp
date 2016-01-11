#include "lifeBar.h"

lifeBar::lifeBar() : lifeBar(DEFAULT_FULL_LIFE)
{
	
}

lifeBar::lifeBar(int fullLife)
{
	this->setfullLife(fullLife);
	this->maxWidth = MAX_WIDTH;
	this->initLifebarProperties(sf::Vector2f(START_SIZE), sf::Color(START_COLOR));
}

lifeBar::~lifeBar()
{

}

void lifeBar::setPosition(sf::Vector2f pos)
{
	sf::Vector2f posSpacing = sf::Vector2f(pos.x, pos.y - (float)SPACING);
	this->lifebar.setPosition(posSpacing);
	this->border.setPosition(posSpacing);
}

void lifeBar::setCurrentlyLife(int life)
{
	this->currentlyLife = life;

	float width = (float)(this->currentlyLife * this->maxWidth) / (float)fullLife;
	this->setSize(sf::Vector2f(width, this->getSize().y));
}

void lifeBar::setSize(sf::Vector2f nSize)
{
	this->lifebar.setSize(nSize);
}

void lifeBar::setBorderSize(sf::Vector2f size)
{
	this->border.setSize(size);
	this->maxWidth = size.x;
}

void lifeBar::setfullLife(int life)
{
	this->fullLife = life;
	this->currentlyLife = this->fullLife;
}

sf::Vector2f lifeBar::getSize()
{
	return this->lifebar.getSize();
}

void lifeBar::initLifebarProperties(sf::Vector2f mSize, sf::Color mColor)
{
	this->lifebar.setSize(mSize);
	this->lifebar.setFillColor(mColor);

	this->border.setSize(mSize);
	this->border.setFillColor(sf::Color(BORDER_BACKGROUND));
	this->border.setOutlineThickness(BORDER_THICKNESS);
	this->border.setOutlineColor(sf::Color(BORDER_COLOR));
}

void lifeBar::draw(sf::RenderWindow *win)
{
	win->draw(this->border);
	win->draw(this->lifebar);
}

void lifeBar::moving(float x, float y)
{
	this->lifebar.move(x, y);
	this->border.move(x, y);
}

void lifeBar::moving(sf::Vector2f speed)
{
	this->lifebar.move(speed);
	this->border.move(speed);
}