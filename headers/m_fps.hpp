#pragma once
#include<SFML/System.hpp>
class m_fps
{
private:
    sf::Clock clock;
    sf::Time time;
    float fps;
public:
    void tocount();
    void wait();
    void set(int fps=60);
};