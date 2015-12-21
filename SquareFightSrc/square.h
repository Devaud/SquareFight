#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "zonning.h"

#define DEFAULT_SPEED 0.5f
#define DEFAULT_LIFE 100
#define DEFAULT_ARMOR 100
#define DEFAULT_SIZE 50, 50
#define DEFAULT_COLOR 100, 250, 50
/*
    Author      : Devaud
    Description : Square class contains all square's  data and logical
    Date        : 2015.12.21
    Version     : 1.0
*/

class Square
{
public:
    Square();

    float getSpeed();
    int getLife();
    int getArmor();
    sf::RectangleShape getSquare();
    sf::Vector2f getSquarePosition();
    sf::Vector2f getSquareSize();
    Zonning getZone();
    
    void setColor(int r, int g, int b);
    void setSize(int width, int height);
    void setSquarePosition(float x, float y);
    void setZone(Zonning *zone);

    void keyEvent();
    void collided();
private:
    void initRect();
    void moving();
    void zonningCollide();

    sf::RectangleShape rect;
    sf::Vector2f size;
    sf::Color color;
    int life;
    int armor;
    float speed;
    Zonning *zone;
};


#endif
