#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Square
{
public:
    Square();
    float getSpeed();
    int getLife();
    int getArmor();
    sf::RectangleShape getSquare();
    void setColor(int r, int g, int b);
    void setSize(int width, int height);
    void keyEvent();
private:
    void initRect();
    sf::RectangleShape rect;
    sf::Vector2f size;
    sf::Color color;
    int life;
    int armor;
    float speed;
};


#endif
