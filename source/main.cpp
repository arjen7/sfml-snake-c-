#include<iostream>
#include<SFML/Graphics.hpp>
#include<m_mainpage.hpp>
#include<m_fps.hpp>

int main(int argc, char const *argv[])
{
   sf::Font font;
    if (!font.loadFromFile("resource/sansation.ttf"))
        return EXIT_FAILURE;
    enum page{
        pagemain,
        pagegame
    };
    page whichpage=pagemain;
    sf::RenderWindow window(sf::VideoMode(800,600),"snake");
    m_mainpage mainpage(100,40,sf::Color::Cyan,&font);
    while (window.isOpen())
    {
        switch (whichpage)
        {
            case pagemain:
                mainpage.page(&window);
                break;
            case pagegame:
                break;
        }
    }
    
    return 0;
}
