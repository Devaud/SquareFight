#include "square.h"

Square::Square() : Square(true)
{

}

Square::Square(bool showLifebar)
{
	this->rect.setSize(sf::Vector2f(DEFAULT_SIZE));
	this->rect.setFillColor(sf::Color(DEFAULT_COLOR));
	this->life = DEFAULT_LIFE;
	this->armor = DEFAULT_ARMOR;
	this->speed = DEFAULT_SPEED;
	this->showLifebar = showLifebar;
	this->alive = true;
}



sf::RectangleShape Square::getSquare()
{
	return this->rect;
}

float Square::getSpeed()
{
	return this->speed;
}

int Square::getLife()
{
	return this->life;
}

int Square::getArmor()
{
	return this->armor;
}

sf::Vector2f Square::getSquarePosition()
{
	return this->rect.getPosition();
}

sf::Vector2f Square::getSquareSize()
{
	return this->rect.getSize();
}

Zonning Square::getZone()
{
	return *zone;
}

sf::Color Square::getColor()
{
	return this->rect.getFillColor();
}

void Square::setColor(int r, int g, int b)
{
	this->rect.setFillColor(sf::Color(r, g, b));
}

void Square::setSize(int width, int height)
{
	this->rect.setSize(sf::Vector2f((float)width, (float)height));
}

void Square::setSquarePosition(float x, float y)
{
	this->rect.setPosition(sf::Vector2f(x, y));
	this->lb.setPosition(this->getSquarePosition());
}

void Square::setZone(Zonning *zoned)
{
	this->zone = zoned;
}

void Square::keyEvent()
{
	this->moving();
}

void Square::collided()
{
	this->zonningCollide();
}

void Square::moving()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->rect.move(-speed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->rect.move(speed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->rect.move(0, -speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->rect.move(0, speed);
	}

	if (this->zone != NULL)
		this->zonningCollide();

	this->lb.setPosition(this->getSquarePosition());
}

void Square::attacked(int damage)
{
	int damageWithArmor = damage - this->getArmor();

	if (damageWithArmor > 0)
	{
		this->life -= (damage - this->getArmor());
		this->lb.setCurrentlyLife(this->life);
		if (!this->isAlive())
			this->alive = false;
	}
}

void Square::draw(sf::RenderWindow *win)
{
	win->draw(this->rect);

	if (this->showLifebar)
		this->lb.draw(win);
}

void Square::zonningCollide()
{
	int borderThickness = (this->showLifebar) ? BORDER_THICKNESS : 0;
	int spacing = (this->showLifebar) ? SPACING : 0;
	sf::Vector2f lbSize = (this->showLifebar) ? this->lb.getSize() : sf::Vector2f(0, 0);

	if (this->rect.getPosition().x - borderThickness <= this->zone->getMinZone().x)
		this->rect.setPosition(this->zone->getMinZone().x + borderThickness, this->rect.getPosition().y);

	if (this->rect.getPosition().x + this->getSquareSize().x + borderThickness >= this->zone->getMaxZone().x)
		this->rect.setPosition(this->zone->getMaxZone().x - this->getSquareSize().x - borderThickness, this->rect.getPosition().y);

	if (this->rect.getPosition().y - lbSize.y - spacing <= this->zone->getMinZone().y)
		this->rect.setPosition(this->rect.getPosition().x, this->zone->getMinZone().y + lbSize.y + spacing);

	if (this->rect.getPosition().y + this->getSquareSize().y >= this->zone->getMaxZone().y)
		this->rect.setPosition(this->rect.getPosition().x, this->zone->getMaxZone().y - this->getSquareSize().y);

}

bool Square::isAlive()
{
	if (this->life <= 0)
		return false;
	else
		return true;
}
