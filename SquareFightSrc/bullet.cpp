#include "bullet.h"

Bullet::Bullet()
{
    color = sf::Color(255, 255, 56);
    size = sf::Vector2f(10, 20);
    speed = sf::Vector2f(0, 0);
    zone = NULL;
    initRect();
}

Bullet::Bullet(sf::Vector2f mSize)
{
    color = sf::Color(255, 255, 56);
    size = mSize;
    speed = sf::Vector2f(0,0);
    zone = NULL;
    initRect();
}

Bullet::Bullet(int dir, Zonning *zoned)
{
    color = sf::Color(255, 255, 56);
    zone = zoned;
    initRect();
    changeDirection(dir);
}

void Bullet::initRect()
{
    outZone = false;
    direction = 1;
    rect.setSize(size);
    rect.setFillColor(color);
}

sf::RectangleShape Bullet::getBullet()
{
    return rect;
}

sf::Vector2f Bullet::getSize()
{
    return size;
}

sf::Color Bullet::getColor()
{
    return color;
}

int Bullet::getDamage()
{
    return damage;
}

sf::Vector2f Bullet::getSpeed()
{
    return speed;
}

int Bullet::getDirection()
{
    return direction;
}

Zonning Bullet::getZone()
{
    return *zone;
}

bool Bullet::getOutZone()
{
    return outZone;
}

void Bullet::setDamage(int dam)
{
    damage = dam;
}

void Bullet::setColor(int r, int g, int b)
{
    color = sf::Color(r, g, b);
    rect.setFillColor(color);
}

void Bullet::setSpeed(sf::Vector2f sp)
{
    speed = sp;
}

void Bullet::setPosition(float x, float y)
{
    rect.setPosition(x, y);   
}

void Bullet::setSize(sf::Vector2f si)
{
    size = si;
    rect.setSize(size);
}

void Bullet::setDirection(int dir)
{
    direction = dir;
}

void Bullet::setZone(Zonning *zoned)
{
    zone = zoned;    
}

void Bullet::changeDirection(int dir)
{
    setDirection(dir);
    switch (dir)
    {
        case 1 :
            speed = sf::Vector2f(0, -SPEED);
            setSize(sf::Vector2f(VERTICAL_SHOOT));
            break;
        case 2 :
            speed = sf::Vector2f(SPEED, 0);
            setSize(sf::Vector2f(HORIZONTAL_SHOOT));
            break;
        case 3 :
            speed = sf::Vector2f(0, SPEED);
            setSize(sf::Vector2f(VERTICAL_SHOOT));
            break;
        case 4 :
            speed = sf::Vector2f(-SPEED, 0);
            setSize(sf::Vector2f(HORIZONTAL_SHOOT));
            break;
        default:
            speed = sf::Vector2f(0, 0);
            setSize(sf::Vector2f(10, 10));
            setColor(255, 0, 0);
            break;
    }
}

bool Bullet::zonningCollide()
{
    if (rect.getPosition().x <= zone->getMinZone().x)
        return true;

    if (rect.getPosition().x + size.x >= zone->getMaxZone().x)
        return true;

    if (rect.getPosition().y <= zone->getMinZone().y)
        return true;

    if (rect.getPosition().y + size.y >= zone->getMaxZone().y)
        return true;

    return false;

}

void Bullet::moving()
{
    rect.move(speed.x, speed.y);

    if (zone != NULL)
        outZone = zonningCollide();
}
