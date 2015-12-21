#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

    void setColor(int r, int g, int b);
    void setSize(int width, int height);
    void setSquarePosition(float x, float y);

    void keyEvent();
private:
    void initRect();
    void moving();

    sf::RectangleShape rect;
    sf::Vector2f size;
    sf::Color color;
    int life;
    int armor;
    float speed;
};


#endif
