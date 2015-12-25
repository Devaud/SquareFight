#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define VERTICAL_SHOOT 10, 20
#define HORIZONTAL_SHOOT 20, 10
#define UP_DIRECTION 1
#define RIGHT_DIRECTION 2
#define DOWN_DIRECTION 3
#define LEFT_DIRECTION 4
#define SPEED 1

/*
    Author      : Devaud
    Description : Bullet class contains all bullet's data and logical
    Date        : 2015.12.23
    Version     : 1.0
*/

class Bullet
{
public:
    Bullet();
    Bullet(sf::Vector2f size);

    sf::RectangleShape getBullet();
    sf::Vector2f getSize();
    sf::Color getColor();
    int getDamage();
    sf::Vector2f getSpeed();
    int getDirection();

    void setDamage(int dam);
    void setColor(int r, int g, int b);
    void setSpeed(sf::Vector2f sp);
    void setPosition(float x, float y);
    void setSize(sf::Vector2f si);
    void setDirection(int dir);

    void moving();
    void changeDirection(int dir);
private:
    void initRect();

    sf::RectangleShape rect;
    sf::Vector2f size;
    sf::Color color;
    sf::Vector2f speed;
    int damage;
    int direction;

};

#endif
