#pragma once
#include<SFML/Graphics.hpp>
#include<m_text.hpp>
class m_mainpage
{
private:
    sf::RectangleShape setting;
    sf::RectangleShape play;
    sf::Text settingtext;
    sf::Text playtext;
    enum select{
        e_play,
        e_fps,
        e_gamespeed,
        e_volume
    };
public:
    m_mainpage(int,int,sf::Color,sf::Font*);
    void draw(sf::RenderWindow*);
    void page(sf::RenderWindow*);
    void selection(select,m_text*);
    void settings();
};
