#include "square.h"

Square::Square()
{
    color = sf::Color(100, 250, 50);
    size = sf::Vector2f(50, 50);
    life = 100;
    armor = 100;
    speed = 0.5f;
    initRect();
}

void Square::initRect()
{
    rect.setSize(size);
    rect.setFillColor(sf::Color(100, 250, 50));
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
