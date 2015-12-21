#include "zonning.h"

Zonning::Zonning(float minX, float minY, float maxX, float maxY)
{
   setZone(minX, minY, maxX, maxY); 
}

sf::Vector2f Zonning::getMaxZone()
{
    return maxZone;
}

sf::Vector2f Zonning::getMinZone()
{
    return minZone;
}

void Zonning::setMaxZone(float x, float y)
{
    maxZone = sf::Vector2f(x, y);
}

void Zonning::setMinZone(float x, float y)
{
    minZone = sf::Vector2f(x, y);
}

void Zonning::setZone(float minX, float minY, float maxX, float maxY)
{
    minZone = sf::Vector2f(minX, minY);
    maxZone = sf::Vector2f(maxX, maxY);
}
