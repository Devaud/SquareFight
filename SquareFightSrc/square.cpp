#include "square.h"

Square::Square()
{
    color = sf::Color(DEFAULT_COLOR);
    size = sf::Vector2f(DEFAULT_SIZE);
    life = DEFAULT_LIFE;
    armor = DEFAULT_ARMOR;
    speed = DEFAULT_SPEED;
    initRect();
}

void Square::initRect()
{
    rect.setSize(size);
    rect.setFillColor(color);
}

sf::RectangleShape Square::getSquare()
{
    return rect;
}

float Square::getSpeed()
{
    return speed;
}

int Square::getLife()
{
    return life;
}

int Square::getArmor()
{
    return armor;
}

sf::Vector2f Square::getSquarePosition()
{
    return rect.getPosition();
}

sf::Vector2f Square::getSquareSize()
{
    return size;
}

Zonning Square::getZone()
{
    return *zone;
}

void Square::setColor(int r, int g, int b)
{
    color = sf::Color(r, g, b);
    rect.setFillColor(color);
}

void Square::setSize(int width, int height)
{
    size = sf::Vector2f(width, height);
    rect.setSize(size);
}

void Square::setSquarePosition(float x, float y)
{
    rect.setPosition(sf::Vector2f(x, y));
}

void Square::setZone(Zonning *zoned)
{
    zone = zoned;
}

void Square::keyEvent()
{
    moving();
}

void Square::collided()
{
    zonningCollide();   
}

void Square::moving()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        rect.move(-speed, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        rect.move(speed, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        rect.move(0, -speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        rect.move(0, speed);
    }

    if (zone != NULL)
        zonningCollide();
}

void Square::zonningCollide()
{
    if (rect.getPosition().x <= zone->getMinZone().x)
        rect.setPosition(zone->getMinZone().x, rect.getPosition().y);

    if (rect.getPosition().x + size.x >= zone->getMaxZone().x)
        rect.setPosition(zone->getMaxZone().x - size.x, rect.getPosition().y);

    if (rect.getPosition().y <= zone->getMinZone().y)
        rect.setPosition(rect.getPosition().x, zone->getMinZone().y);

    if (rect.getPosition().y + size.y >= zone->getMaxZone().y)
        rect.setPosition(rect.getPosition().x, zone->getMaxZone().y - size.y); 
}
