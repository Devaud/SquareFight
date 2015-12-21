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

sf::Vector2f Square::getSquarePosition()
{
    return rect.getPosition();
}

sf::Vector2f Square::getSquareSize()
{
    return size;
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

void Square::keyEvent()
{
    moving();
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
}
