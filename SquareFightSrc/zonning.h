#ifndef ZONNING_H
#define ZONNING_H

#include <SFML/Window.hpp>

/*
    Author      : Devaud
    Description : Zonning is for add a limited zone
    Date        : 2015.12.21
    Version     : 1.0
*/

class Zonning
{
public:
    Zonning(float minX, float minY, float maxX, float maxY);
    
    sf::Vector2f getMaxZone();
    sf::Vector2f getMinZone();

    void setMaxZone(float x, float y);
    void setMinZone(float x, float y);
    void setZone(float minX, float minY, float maxX, float maxY);
private:
    sf::Vector2f minZone;
    sf::Vector2f maxZone;
};


#endif
