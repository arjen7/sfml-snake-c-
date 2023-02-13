#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include<time.h>
#include<cmath>
class m_snake 
{
private:
    std::vector<sf::RectangleShape> snake;
    sf::Color snakecolor;
    float horizontal;
    float vercital;
    float edge;
public:
    void movement(float);
    std::vector<sf::RectangleShape>* getvector();
    void newsnake();
    void collision();
    void bait();
    bool eat();
    m_snake(float,float,float,sf::Color);
};


