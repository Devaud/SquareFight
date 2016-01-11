#include "bullet.h"

Bullet::Bullet() : Bullet(START_BULLET_DIR, &Zonning(0, 0, 10, 10), sf::Color(BULLET_COLOR))
{

}

Bullet::Bullet(int dir, Zonning *zoned, sf::Color mColor)
{
	this->setColor(mColor);
	this->zone = zoned;
	this->direction = dir;
	this->setSize(sf::Vector2f(BULLET_SIZE));
	this->outZone = false;
	this->damage = DEFAULT_DAMAGE;
	this->changeDirection(dir);
}

sf::RectangleShape Bullet::getBullet()
{
	return this->rect;
}

sf::Vector2f Bullet::getSize()
{
	return this->rect.getSize();
}

sf::Color Bullet::getColor()
{
	return this->rect.getFillColor();
}

int Bullet::getDamage()
{
	return this->damage;
}

sf::Vector2f Bullet::getSpeed()
{
	return this->speed;
}

int Bullet::getDirection()
{
	return this->direction;
}

Zonning Bullet::getZone()
{
	return *zone;
}

bool Bullet::getOutZone()
{
	return this->outZone;
}

void Bullet::setDamage(int dam)
{
	this->damage = dam;
}

void Bullet::setColor(sf::Color mColor)
{
	this->rect.setFillColor(mColor);
}

void Bullet::setSpeed(sf::Vector2f sp)
{
	this->speed = sp;
}

void Bullet::setPosition(float x, float y)
{
	this->rect.setPosition(x, y);
}

void Bullet::setSize(sf::Vector2f si)
{
	this->rect.setSize(si);
}

void Bullet::setDirection(int dir)
{
	this->direction = dir;
}

void Bullet::setZone(Zonning *zoned)
{
	this->zone = zoned;
}

void Bullet::changeDirection(int dir)
{
	this->setDirection(dir);
	switch (dir)
	{
	case 1:
		this->speed = sf::Vector2f(0, -SPEED);
		this->setSize(sf::Vector2f(VERTICAL_SHOOT));
		break;
	case 2:
		this->speed = sf::Vector2f(SPEED, 0);
		this->setSize(sf::Vector2f(HORIZONTAL_SHOOT));
		break;
	case 3:
		this->speed = sf::Vector2f(0, SPEED);
		this->setSize(sf::Vector2f(VERTICAL_SHOOT));
		break;
	case 4:
		this->speed = sf::Vector2f(-SPEED, 0);
		this->setSize(sf::Vector2f(HORIZONTAL_SHOOT));
		break;
	default:
		this->speed = sf::Vector2f(0, 0);
		this->setSize(sf::Vector2f(10, 10));
		this->setColor(sf::Color(255, 0, 0));
		break;
	}
}
void Bullet::draw(sf::RenderWindow *win)
{
	win->draw(this->rect);
}

bool Bullet::zonningCollide()
{
	if (this->rect.getPosition().x <= this->zone->getMinZone().x)
		return true;

	if (this->rect.getPosition().x + this->getSize().x >= this->zone->getMaxZone().x)
		return true;

	if (this->rect.getPosition().y <= this->zone->getMinZone().y)
		return true;

	if (this->rect.getPosition().y + this->getSize().y >= this->zone->getMaxZone().y)
		return true;

	return false;

}

void Bullet::moving()
{
	this->rect.move(speed.x, speed.y);

	if (this->zone != NULL)
		this->outZone = this->zonningCollide();
}

void Bullet::hitted(Square *sq)
{
	if (this->rect.getPosition().x >= sq->getSquarePosition().x && this->rect.getPosition().x <= sq->getSquarePosition().x + sq->getSquareSize().x && this->rect.getPosition().y >= sq->getSquarePosition().y && this->rect.getPosition().y <= sq->getSquarePosition().y + sq->getSquareSize().y)
	{
		sq->attacked(this->damage);
		this->outZone = true;
	}
}